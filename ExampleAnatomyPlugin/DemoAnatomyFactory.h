/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class DemoAnatomyAlgorithmFactory : public AlgorithmFactory
	{
	public:
		DemoAnatomyAlgorithmFactory();
	};

	/// AlgorithmControllerFactory for demo plugin
	class DemoAnatomyControllerFactory : public AlgorithmControllerFactory
	{
	public:
		DemoAnatomyControllerFactory();

		AlgorithmController* create(Algorithm* a) const override;
	};
}
