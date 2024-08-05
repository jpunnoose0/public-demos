#include "DemoStreamDataPlugin.h"

#include "DemoStreamDataFactory.h"

IMFUSION_REGISTER_PLUGIN(ImFusion::DemoStreamDataPlugin)

namespace ImFusion
{
	DemoStreamDataPlugin::DemoStreamDataPlugin() = default;


	DemoStreamDataPlugin::~DemoStreamDataPlugin() = default;


	const ImFusion::AlgorithmFactory* DemoStreamDataPlugin::getAlgorithmFactory() { return new DemoStreamDataAlgorithmFactory; }


	const ImFusion::AlgorithmControllerFactory* DemoStreamDataPlugin::getAlgorithmControllerFactory() { return new DemoStreamDataControllerFactory; }
}
