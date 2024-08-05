#include "DemoAnatomyAlgorithm.h"

#include <ImFusion/AnatomyPlugin/GenericASC.h>
#include <ImFusion/Base/DataList.h>
#include <ImFusion/Base/ImFusionFile.h>
#include <ImFusion/Core/Filesystem/Directory.h>
#include <ImFusion/Core/Filesystem/Filesystem.h>
#include <ImFusion/Core/Filesystem/Path.h>
#include <ImFusion/Mesh/Mesh.h>

#include <array>

namespace ImFusion
{
	DemoAnatomyAlgorithm::DemoAnatomyAlgorithm()
	{
		// These actions can be called from python bindings and show up in the DefaultAlgorithmController
		registerAction("loadMeshes", "1) Load meshes", [this]() {
			// Load the meshes from the imf file
			ImFusionFile imf(Filesystem::Path(__FILE__).parentDirectory().path() / "meshes.imf");
			m_meshes = imf.load()->extractAll<Mesh>();

			return Status::Success;
		});

		registerAction("createASC", "2) Create ASC", [this]() {
			if (m_meshes.size() != 4)
				return Status::Error;

			// create a new ASC
			m_ascOut = std::make_unique<GenericASC>();

			// create lookup table for the keys
			const auto keys = std::array<std::string, 4>{
				ImFusion::Keys::Liver::key, ImFusion::Keys::LeftKidney::key, ImFusion::Keys::RightKidney::key, ImFusion::Keys::Lungs::key};

			LOG_INFO("Adding " << m_meshes.size() << " meshes to the ASC");
			for (int i = 0; i < m_meshes.size(); ++i)
			{
				// create new anatomical structure
				auto structure = std::make_unique<GenericAnatomicalStructure>(keys[i]);
				// move the mesh to the structure as segmentation
				structure->meshes()[ImFusion::Keys::Segmentation::key] = std::move(m_meshes[i]);
				// add the structure to the ASC
				m_ascOut->addAnatomicalStructure(std::move(structure));
			}

			return Status::Success;
		});

		registerAction("loadRef", "3) Load reference ASC", [this]() {
			// ASCs can also be stored and loaded from ImFusion files
			ImFusionFile imf(Filesystem::Path(__FILE__).parentDirectory().path() / "asc.imf");
			m_ascRef = imf.load()->extractFirst<GenericASC>();

			return Status::Success;
		});
	}


	bool DemoAnatomyAlgorithm::createCompatible(const DataList& /*data*/, Algorithm** a)
	{
		if (a)
			*a = new DemoAnatomyAlgorithm();

		return true;
	}


	void DemoAnatomyAlgorithm::compute()
	{
		// set generic error status until we have finished
		m_status = static_cast<int>(Status::Error);

		// Here we could run the ASCRegistration algorithm

		// set algorithm status to success
		m_status = static_cast<int>(Status::Success);
	}


	OwningDataList DemoAnatomyAlgorithm::takeOutput()
	{
		// if we have produced some output, add it to the list
		OwningDataList odl;
		odl.add(std::move(m_meshes));
		odl.add(std::move(m_ascOut));
		odl.add(std::move(m_ascRef));
		return odl;
	}
}
