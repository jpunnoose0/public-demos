#include "DemoDicomExtensionPlugin.h"

#include "DemoDataComponent.h"
#include "DemoDicomExtensionFactory.h"
#include "DemoExtension.h"

#include <ImFusion/Base/DataComponentFactory.h>
#include <ImFusion/Dicom/DicomIOD_Registry.h>

#include <memory>

IMFUSION_REGISTER_PLUGIN(ImFusion::DemoDicomExtensionPlugin)

namespace ImFusion
{
	DemoDicomExtensionPlugin::DemoDicomExtensionPlugin()
	{
		// Register DataComponent
		DataComponentFactory::get().registerComponent(DemoDataComponent().id(), []() { return std::make_unique<DemoDataComponent>(); });
		// Register DICOM extension
		Dicom::IOD_Registry::registerDefaultExtension(std::make_unique<DemoExtension>());
	}

	DemoDicomExtensionPlugin::~DemoDicomExtensionPlugin() = default;

	const AlgorithmFactory* DemoDicomExtensionPlugin::getAlgorithmFactory() { return new DemoDicomExtensionAlgorithmFactory; }

	const AlgorithmControllerFactory* DemoDicomExtensionPlugin::getAlgorithmControllerFactory() { return new DemoDicomExtensionControllerFactory; }
}
