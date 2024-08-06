/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class DemoImageMathAlgorithmFactory : public AlgorithmFactory
	{
	public:
		DemoImageMathAlgorithmFactory();
	};

	/// AlgorithmControllerFactory for demo plugin
	class DemoImageMathControllerFactory : public AlgorithmControllerFactory
	{
	public:
		DemoImageMathControllerFactory();
		AlgorithmController* create(Algorithm* a) const override;
	};
}
