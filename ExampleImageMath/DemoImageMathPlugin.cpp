#include "DemoImageMathPlugin.h"

#include "DemoImageMathFactory.h"

IMFUSION_REGISTER_PLUGIN(ImFusion::DemoImageMathPlugin)

namespace ImFusion
{
	DemoImageMathPlugin::DemoImageMathPlugin() = default;


	DemoImageMathPlugin::~DemoImageMathPlugin() = default;


	const ImFusion::AlgorithmFactory* DemoImageMathPlugin::getAlgorithmFactory() { return new DemoImageMathAlgorithmFactory; }


	const ImFusion::AlgorithmControllerFactory* DemoImageMathPlugin::getAlgorithmControllerFactory() { return new DemoImageMathControllerFactory; }
}
