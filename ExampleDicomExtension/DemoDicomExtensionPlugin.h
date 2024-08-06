/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/ImFusionPlugin.h>

namespace ImFusion
{
	class AlgorithmFactory;
	class AlgorithmControllerFactory;

	/// Minimal example for defining a custom plugin for the ImFusion SDK
	class DemoDicomExtensionPlugin : public ImFusionPlugin
	{
	public:
		DemoDicomExtensionPlugin();
		~DemoDicomExtensionPlugin() override;
		const AlgorithmFactory* getAlgorithmFactory() override;
		const AlgorithmControllerFactory* getAlgorithmControllerFactory() override;
	};
}
