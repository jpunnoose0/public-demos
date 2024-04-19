#include "TotalSegmentatorDemoPlugin.h"

#include "TotalSegmentatorDemoFactory.h"

// Export free factory function to instantiate plugin
#ifdef WIN32
extern "C" __declspec(dllexport) ImFusion::ImFusionPlugin* createPlugin() { return new ImFusion::TotalSegmentatorDemoPlugin; }
#else
extern "C" ImFusion::ImFusionPlugin* createPlugin() { return new ImFusion::TotalSegmentatorDemoPlugin; }
#endif


namespace ImFusion
{
	TotalSegmentatorDemoPlugin::TotalSegmentatorDemoPlugin() {}

	TotalSegmentatorDemoPlugin::~TotalSegmentatorDemoPlugin() {}

	const ImFusion::AlgorithmFactory* TotalSegmentatorDemoPlugin::getAlgorithmFactory()
	{
		return new TotalSegmentatorDemoAlgorithmFactory{"TotalSegmentatorDemo"};
	}

	const ImFusion::AlgorithmControllerFactory* TotalSegmentatorDemoPlugin::getAlgorithmControllerFactory()
	{
		return new TotalSegmentatorDemoControllerFactory("TotalSegmentatorDemo");
	}
}
