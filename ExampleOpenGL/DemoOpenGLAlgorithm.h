/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/Algorithm.h>
#include <ImFusion/Core/Parameter.h>

#include <memory>

namespace ImFusion
{
	class SharedImageSet;

	/// Simple demonstration of a custom Algorithm.
	/// This algorithm will convert the input image to gray.
	class DemoOpenGLAlgorithm : public Algorithm
	{
	public:
		/// Creates the algorithm instance with an image
		explicit DemoOpenGLAlgorithm(SharedImageSet* img);

		/// \name	Methods implementing the algorithm interface
		//\{
		/// Factory method to check for applicability or to create the algorithm
		static bool createCompatible(const DataList& data, Algorithm** a = nullptr);

		/// Applies the processing
		void compute() override;

		/// If new data was created, make it available here
		OwningDataList takeOutput() override;
		//\}

		/// Weight parameters \f$w\f$. The algorithm will convert to grey via: \f$\frac{\|v^\top w\|}{\|w\|_1}\f$
		Parameter<vec3> p_weights = { "weights", vec3(0.299f, 0.587f, 0.114f), this };

	private:
		SharedImageSet* m_imgIn = nullptr;           ///< Input image to process
		std::unique_ptr<SharedImageSet> m_imgOut;    ///< Output image after processing
	};
}
