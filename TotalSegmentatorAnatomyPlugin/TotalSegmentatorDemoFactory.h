/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class TotalSegmentatorDemoAlgorithmFactory : public AlgorithmFactory
	{
	public:
		TotalSegmentatorDemoAlgorithmFactory(const std::string& module);
	};

	/// AlgorithmControllerFactory for demo plugin
	class TotalSegmentatorDemoControllerFactory : public AlgorithmControllerFactory
	{
	public:
		TotalSegmentatorDemoControllerFactory(std::string module);
		virtual AlgorithmController* create(Algorithm* a) const;
	};
}
