#include "TotalSegmentatorDemoFactory.h"

#include "TotalSegmentatorDemoAlgorithm.h"
#include "TotalSegmentatorDemoPlugin.h"

#include <ImFusion/GUI/DefaultAlgorithmController.h>

namespace ImFusion
{
	TotalSegmentatorDemoAlgorithmFactory::TotalSegmentatorDemoAlgorithmFactory(const std::string& module)
		: AlgorithmFactory{module}
	{
		// register the TotalSegmentatorDemoAlgorithm
		registerAlgorithm<TotalSegmentatorDemoAlgorithm>("TotalSegmentatorDemoAlgorithm", "Demo Plugin; Total Segmentator Demo Algorithm");
	}

	TotalSegmentatorDemoControllerFactory::TotalSegmentatorDemoControllerFactory(std::string module)
		: AlgorithmControllerFactory{module}
	{
	}

	AlgorithmController* TotalSegmentatorDemoControllerFactory::create(Algorithm* a) const
	{
		// register the DemoController for the DemoAlgorithm
		if (TotalSegmentatorDemoAlgorithm* alg = dynamic_cast<TotalSegmentatorDemoAlgorithm*>(a))
		{
			return new DefaultAlgorithmController(alg);
		}
		return 0;
	}
}
