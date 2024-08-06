/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/ImFusionPlugin.h>
#include <ImFusion/Core/Resource/Repository.h>

namespace ImFusion
{
	class AlgorithmFactory;
	class AlgorithmControllerFactory;

	/// Minimal example for defining a custom plugin for the ImFusion SDK
	class DemoStreamDataPlugin : public ImFusionPlugin
	{
	public:
		DemoStreamDataPlugin();
		virtual ~DemoStreamDataPlugin();
		virtual const AlgorithmFactory* getAlgorithmFactory();
		virtual const AlgorithmControllerFactory* getAlgorithmControllerFactory();
	};
}
