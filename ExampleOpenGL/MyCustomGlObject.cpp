#include "MyCustomGlObject.h"
 
#include <ImFusion/Core/Mat.h>
#include <ImFusion/Core/GL/FixedFunctionPipeline.h>
#include <ImFusion/Core/GL/VertexBuffer.h>
 
#include <vector>
 
using namespace ImFusion;
 
void MyCustomGlObject::draw(const GlView& view)
{
	GL::FixedFunctionPipeline& ffp = GL::FixedFunctionPipeline::cachedInstance();
 
	// define vertex data on the CPU
	std::vector<vec3f> lineVertices{
		vec3f(-10.f, 10.f, 0.f), vec3f(10.f, 10.f, 0.f), vec3f(10.f, -10.f, 0.f)
	};
	// upload vertex data to the GPU using the utility function of GL::FixedFunctionPipeline.
	std::unique_ptr<GL::VertexBuffer> vbo = GL::FixedFunctionPipeline::makeVertexData(lineVertices);
 
	// Select the line rendering shader and initialize it with the GlViewState of the view passed as argument
	ffp.enable(view.state(), GL::FixedFunctionPipeline::ShaderSelection::LineRendering);
	// Set line color and width
	ffp.setDefaultColor(vec4(1.0, 0.5, 0.0, 1.0));
	ffp.setLineWidth(4);
 
	// When the shader is completely configured, issue the draw call on the vertex buffer
	vbo->draw(GL::Primitive::LineStrip);

	// define vertex data
	std::vector<vec3f> triangleVertices{
		vec3f(-10.f, 8.f, 0.f), vec3f(-10.f, -10.f, 0.f), vec3f(8.f, -10.f, 0.f)
	};
	std::vector<vec3f> triangleColors{
		vec3f(1.f, 0.f, 0.f), vec3f(0.f, 1.f, 0.f), vec3f(0.f, 0.f, 1.f)
	};
	// update the vertex buffer with the new data for the triangle
	GL::FixedFunctionPipeline::makeVertexData(triangleVertices).useColors(triangleColors).assign(*vbo);
 
	ffp.enable(view.state(), GL::FixedFunctionPipeline::ShaderSelection::Default);
	vbo->draw(GL::Primitive::Triangles);
 
	ffp.disable();
}