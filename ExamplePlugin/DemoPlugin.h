#pragma once

#include <ImFusion/Base/ImFusionPlugin.h>

namespace ImFusion
{
	class AlgorithmFactory;
	class AlgorithmControllerFactory;

	/// Minimal example for defining a custom plugin for the ImFusion SDK
	class DemoPlugin : public ImFusionPlugin
	{
	public:
		DemoPlugin();
		~DemoPlugin() override;
		const AlgorithmFactory* getAlgorithmFactory() override;
		const AlgorithmControllerFactory* getAlgorithmControllerFactory() override;
	};
}
