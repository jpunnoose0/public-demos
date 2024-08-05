#include "DemoOpenGLPlugin.h"

#include "DemoOpenGLFactory.h"

#include <ImFusion/Core/Resource/FilesystemRepository.h>

IMFUSION_REGISTER_PLUGIN(ImFusion::DemoOpenGLPlugin)


namespace ImFusion
{
	DemoOpenGLPlugin::DemoOpenGLPlugin() {
		// We will use a FilesystemRepository for simplicity. We also offer other repositories e.g. to compile resources into a binary file.
		m_shaderRepo.reset(
			new Resource::FilesystemRepository("OpenGLDemoRepository", {Filesystem::Path(__FILE__).parentDirectory()}));
		Resource::addRepository(m_shaderRepo.get());
	}


	DemoOpenGLPlugin::~DemoOpenGLPlugin() = default;


	const ImFusion::AlgorithmFactory* DemoOpenGLPlugin::getAlgorithmFactory() { return new DemoOpenGLAlgorithmFactory; }


	const ImFusion::AlgorithmControllerFactory* DemoOpenGLPlugin::getAlgorithmControllerFactory() { return new DemoOpenGLControllerFactory; }
}
