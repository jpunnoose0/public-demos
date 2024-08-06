/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/Algorithm.h>
#include <ImFusion/Core/Parameter.h>

#include <memory>

namespace ImFusion
{
	class SharedImageSet;
	class Mesh;
	class AnatomicalStructureCollection;

	/// Simple demonstration of a custom Algorithm.
	class DemoAnatomyAlgorithm : public Algorithm
	{
	public:
		/// Creates the algorithm instance with an image
		DemoAnatomyAlgorithm();

		/// \name	Methods implementing the algorithm interface
		//\{
		/// Factory method to check for applicability or to create the algorithm
		static bool createCompatible(const DataList& data, Algorithm** a = nullptr);

		/// Applies the processing
		void compute() override;

		/// If new data was created, make it available here
		OwningDataList takeOutput() override;
		//\}

	private:
		std::vector<std::unique_ptr<Mesh>> m_meshes;                ///< Loaded meshes
		std::unique_ptr<AnatomicalStructureCollection> m_ascOut;    ///< Abstract anatomical data structures constructed from meshes
		std::unique_ptr<AnatomicalStructureCollection> m_ascRef;    ///< Abstract anatomical data structures loaded from ImFusionFile

		std::unique_ptr<SharedImageSet> m_imgOut;    ///< Output image after processing
	};
}
