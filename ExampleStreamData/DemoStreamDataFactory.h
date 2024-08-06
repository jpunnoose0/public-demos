/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class DemoStreamDataAlgorithmFactory : public AlgorithmFactory
	{
	public:
		DemoStreamDataAlgorithmFactory();
	};

	/// AlgorithmControllerFactory for demo plugin
	class DemoStreamDataControllerFactory : public AlgorithmControllerFactory
	{
	public:
		DemoStreamDataControllerFactory();

		AlgorithmController* create(Algorithm* a) const override;
	};
}
