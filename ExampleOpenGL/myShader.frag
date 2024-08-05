#version 400

in vec3 in_texCoord;
uniform vec3 u_weights;
uniform sampler2D u_texIn;

layout(location = 0) out vec4 out_color;

void main()
{
	// 2D shader
	float grey = dot(texture(u_texIn, in_texCoord.xy).rgb, u_weights) / dot(u_weights, vec3(1.0));

	out_color = vec4(vec3(grey), 1.0);
}
