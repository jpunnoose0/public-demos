/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class DemoAlgorithmFactory : public AlgorithmFactory
	{
	public:
		DemoAlgorithmFactory();
	};

	/// AlgorithmControllerFactory for demo plugin
	class DemoControllerFactory : public AlgorithmControllerFactory
	{
	public:
		DemoControllerFactory();

		AlgorithmController* create(Algorithm* a) const override;
	};
}
