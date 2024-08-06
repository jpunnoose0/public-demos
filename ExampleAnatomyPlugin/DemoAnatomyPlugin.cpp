#include "DemoAnatomyPlugin.h"

#include "DemoAnatomyFactory.h"

IMFUSION_REGISTER_PLUGIN(ImFusion::DemoAnatomyPlugin)

namespace ImFusion
{
	DemoAnatomyPlugin::DemoAnatomyPlugin() = default;


	DemoAnatomyPlugin::~DemoAnatomyPlugin() = default;


	const ImFusion::AlgorithmFactory* DemoAnatomyPlugin::getAlgorithmFactory() { return new DemoAnatomyAlgorithmFactory; }


	const ImFusion::AlgorithmControllerFactory* DemoAnatomyPlugin::getAlgorithmControllerFactory() { return new DemoAnatomyControllerFactory; }
}
