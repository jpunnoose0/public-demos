/* Copyright (c) 2012-2024 ImFusion GmbH, Munich, Germany. All rights reserved. */
#pragma once

#include <ImFusion/Base/AlgorithmControllerFactory.h>
#include <ImFusion/Base/AlgorithmFactory.h>

namespace ImFusion
{
	class Algorithm;

	/// AlgorithmFactory for demo plugin
	class DemoDicomExtensionAlgorithmFactory : public AlgorithmFactory
	{
	public:
		DemoDicomExtensionAlgorithmFactory();
	};

	/// AlgorithmControllerFactory for demo plugin
	class DemoDicomExtensionControllerFactory : public AlgorithmControllerFactory
	{
	public:
		DemoDicomExtensionControllerFactory();

		AlgorithmController* create(Algorithm* a) const override;
	};
}
