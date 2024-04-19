#include "TotalSegmentatorDemoAlgorithm.h"

#include "AnatomyKeys.h"

#include <ImFusion/AnatomyPlugin/GenericASC.h>
#include <ImFusion/Base/LabelDataComponent.h>
#include <ImFusion/Base/SharedImageSet.h>
#include <ImFusion/Seg/LabelToMeshAlgorithm.h>
#include <ImFusion/TotalSegmentatorPlugin/TotalSegmentatorAlgorithm.h>

namespace ImFusion
{
	TotalSegmentatorDemoAlgorithm::TotalSegmentatorDemoAlgorithm(SharedImageSet* img)
		: m_imgIn(img)
	{
	}


	bool TotalSegmentatorDemoAlgorithm::createCompatible(const DataList& data, Algorithm** a)
	{
		// check requirements to create the algorithm
		if (data.size() != 1)
			return false;
		SharedImageSet* img = data.getImage(Data::UNKNOWN, Data::CT);    // Only allow CT modality
		if (img == nullptr)
			return false;

		// requirements are met, create the algorithm if asked
		if (a)
		{
			*a = new TotalSegmentatorDemoAlgorithm(img);
		}
		return true;
	}


	void TotalSegmentatorDemoAlgorithm::compute()
	{
		// Reference value of successful algorithm run. Used to check status
		// after each algorithm call below
		constexpr int statusSuccess{static_cast<int>(Status::Success)};

		// set generic error status until we have finished
		m_status = static_cast<int>(Status::Error);

		if (!m_ASCOut)
		{
			m_ASCOut = std::make_unique<GenericASC>();
		}

		// Create an instance of total segementator algorithm and run it
		// The algorithm "TotalSegmentatorAlgorithm" is a lightweight wrapper around the models from
		// TotalSegmentator (https://github.com/wasserth/TotalSegmentator).
		// It runs the models from there and returns the result as a label map.
		TotalSegmentatorAlgorithm segAlg{m_imgIn};
		segAlg.setProgress(m_progress);
		LOG_INFO("Total Segmentator Demo plugin", "Running total segmentator algorithm ...");
		segAlg.compute();
		if (segAlg.status() != statusSuccess)
		{
			m_status = segAlg.status();
			return;
		}

		// The output of total segmentator will become the input
		// of mesh extraction algorithm
		auto labelMap{segAlg.takeOutput().extractFirstImage()};
		if (labelMap == nullptr)
		{
			m_status = static_cast<int>(Status::Error);
			return;
		}

		// Convert labels to meshes
		LabelToMeshAlgorithm labelToMeshAlg{labelMap.get()};
		labelToMeshAlg.setProgress(m_progress);
		labelToMeshAlg.p_labelMapMode = true;

		// Smoothing makes the resulting mesh look nicer, but changes the
		// segmentation slightly. Default value is 1, but can be changed in the GUI
		labelToMeshAlg.p_smoothing = p_smoothing;

		LOG_INFO("Total Segmentator Demo plugin", "Transforming labels to meshes ...");

		labelToMeshAlg.compute();
		if (labelToMeshAlg.status() != statusSuccess)
		{
			m_status = labelToMeshAlg.status();
			return;
		}

		// Get a label map - collection of pairs [pixelValue, LabelConfig]
		// LabelConfig has a name, color and visibility setting
		auto labelMapComponent{labelMap->components().get<LabelDataComponent>()};
		const std::map<int, LabelDataComponent::LabelConfig>& segAlgLabelConfigs{labelMapComponent->labelConfigs()};

		// Temporary storage for component colors - will be used to set mesh colors
		std::map<std::string, vec4> componentColors{};

		// Fill componentColors with pairs (volume name, volume color)
		std::transform(segAlgLabelConfigs.cbegin(),
					   segAlgLabelConfigs.cend(),
					   std::inserter(componentColors, componentColors.end()),
					   [](const auto& labelConfigItem) { return std::make_pair(labelConfigItem.second.name, labelConfigItem.second.color); });

		// Vector of unique pointers to mesh instances
		auto labeledMeshes{labelToMeshAlg.takeOutput().extractAll<Mesh>()};


		for (int i = 0; i < labeledMeshes.size(); ++i)
		{
			Mesh& mesh{*labeledMeshes[i]};

			const std::string key{TotalSegmentator::Keys::AnatomyKeys::translateKey(mesh.name())};

			auto structure{std::make_unique<GenericAnatomicalStructure>(key)};
			structure->meshes()[key] = std::move(labeledMeshes[i]);
			if (auto colorIt{componentColors.find(mesh.name())}; colorIt != componentColors.end())
			{
				const vec4 meshColor{colorIt->second};
				structure->meshes()[key].attributes().setParam("color", meshColor);
			}
			m_ASCOut->addAnatomicalStructure(std::move(structure));
		}

		// set algorithm status to success
		m_status = static_cast<int>(Status::Success);
	}


	OwningDataList TotalSegmentatorDemoAlgorithm::takeOutput()
	{
		// if we have produced some output, add it to the list
		return OwningDataList{std::unique_ptr<Data>(dynamic_cast<Data*>(m_ASCOut.release()))};
	}
}
