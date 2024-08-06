#include "DemoOpenGLAlgorithm.h"

#include <ImFusion/Base/DataList.h>
#include <ImFusion/Base/MemImage.h>
#include <ImFusion/Base/SharedImageSet.h>
#include <ImFusion/Core/GL/ImageProgram.h>
#include <ImFusion/Core/GL/Texture.h>
#include <ImFusion/GL/GlImage.h>


namespace ImFusion
{
	DemoOpenGLAlgorithm::DemoOpenGLAlgorithm(SharedImageSet* img)
		: m_imgIn(img)
	{
	}


	bool DemoOpenGLAlgorithm::createCompatible(const DataList& data, Algorithm** a)
	{
		// check requirements to create the algorithm
		if (data.size() != 1)
			return false;
		SharedImageSet* img = data.getImage(Data::IMAGE);    // in our case, any image is fine
		if (img == nullptr)
			return false;

		// requirements are met, create the algorithm if asked
		if (a)
		{
			*a = new DemoOpenGLAlgorithm(img);
		}
		return true;
	}


	void DemoOpenGLAlgorithm::compute()
	{
		// set generic error status until we have finished
		m_status = static_cast<int>(Status::Error);

		// For a lot of use cases the ImageProgram is the most convenient way to write custom shaders
		// It is designed to be used if you want to apply a shader to an image
		// In most cases it is completely sufficient to only provide a fragment shader.

		// Shaders are loaded through our resource repositories.
		// See DemoOpenGLPlugin.cpp for the registration of the repo.
		ImFusion::GL::ImageProgram prog("OpenGLDemoRepository/myShader.frag");
		prog.enable();
		prog.setArgument("u_weights", p_weights.value());

		m_imgOut = m_imgIn->clone();
		for (int i = 0; i < m_imgIn->size(); i++)
		{
			prog.setArgument("u_texIn", m_imgIn->gl(i)->texture());
			prog.compute(m_imgOut->gl(i)->texture());
		}

		prog.disable();

		// set algorithm status to success
		m_status = static_cast<int>(Status::Success);
	}


	OwningDataList DemoOpenGLAlgorithm::takeOutput()
	{
		// if we have produced some output, add it to the list
		return OwningDataList(std::move(m_imgOut));
	}
}
