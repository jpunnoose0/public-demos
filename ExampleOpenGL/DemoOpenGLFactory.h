/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class DemoOpenGLAlgorithmFactory : public AlgorithmFactory
	{
	public:
		DemoOpenGLAlgorithmFactory();
	};

	/// AlgorithmControllerFactory for demo plugin
	class DemoOpenGLControllerFactory : public AlgorithmControllerFactory
	{
	public:
		DemoOpenGLControllerFactory();

		AlgorithmController* create(Algorithm* a) const override;
	};
}
