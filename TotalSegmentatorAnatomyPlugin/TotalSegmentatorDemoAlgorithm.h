/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/Algorithm.h>
#include <ImFusion/Core/Parameter.h>

#include <memory>

namespace ImFusion
{
	class SharedImageSet;
	class AnatomicalStructureCollection;

	/// Simple demonstration of a custom Algorithm.
	/// This algorithm runs TotalSegmentator algorithm and converts resulting volumes
	/// into meshes
	class TotalSegmentatorDemoAlgorithm : public Algorithm
	{
	public:
		/// Creates the algorithm instance with an image
		TotalSegmentatorDemoAlgorithm(SharedImageSet* img);

		/// \name	Methods implementing the algorithm interface
		///\{
		/// Factory method to check for applicability or to create the algorithm
		static bool createCompatible(const DataList& data, Algorithm** a = nullptr);

		/// Implements the actual algorithm. Creates an instance of TotalMeshSegmentatorAlgorithm,
		/// runs it and feeds the output into LabelToMeshAlgorithm in order to generate
		/// one mesh per segmented volume
		void compute() override;

		/// If new data was created, make it available here
		OwningDataList takeOutput() override;
		///\}

	private:
		/// Input image to process
		SharedImageSet* m_imgIn = nullptr;
		/// Abstract anatomical data structures - output of mesh extraction
		std::unique_ptr<AnatomicalStructureCollection> m_ASCOut;

		/// Smoothing value passed to LabelToMeshAlgorithm (see the implementation of compute())
		/// Visible in ImFusionSuite GUI
		Parameter<int> p_smoothing{"smoothing", 1, this};
	};
}
