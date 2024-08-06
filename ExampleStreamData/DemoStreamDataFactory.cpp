#include "DemoStreamDataFactory.h"

#include "DemoStreamDataAlgorithm.h"

#include <ImFusion/GUI/DefaultAlgorithmController.h>

namespace ImFusion
{
	DemoStreamDataAlgorithmFactory::DemoStreamDataAlgorithmFactory()
		: AlgorithmFactory("ExampleStreamData")
	{
		// register the DemoStreamDataAlgorithm
		registerAlgorithm<DemoStreamDataAlgorithm>("DemoStreamDataAlgorithm", "Demo;Demo stream data algorithm");
	}

	DemoStreamDataControllerFactory::DemoStreamDataControllerFactory()
		: AlgorithmControllerFactory("ExampleStreamData")
	{
	}

	AlgorithmController* DemoStreamDataControllerFactory::create(Algorithm* a) const
	{
		// register the DemoController for the DemoStreamDataAlgorithm
		if (auto alg = dynamic_cast<DemoStreamDataAlgorithm*>(a))
			return new DefaultAlgorithmController(alg);
		return nullptr;
	}
}
