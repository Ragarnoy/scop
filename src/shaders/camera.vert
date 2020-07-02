#version 410 core
#define COLOR 0
#define COLORSHIFT 1
#define GREY 2
#define TEX 3
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

smooth out vec4 smooth_col;
flat out vec4   flat_col;
out vec2        TexCoord;

uniform int     mode;
uniform mat4    model;
uniform mat4    view;
uniform mat4    projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
	if (mode == COLOR)
		smooth_col = vec4(aPos.y * 0.4f + 0.4f, aPos.z * 0.1 + aPos.y * 0.4f + 0.1f, 0.2f, 1.0f);
	if (mode == COLORSHIFT)
		smooth_col = vec4(aPos * 0.4f + 0.4f, 1.0f);
	if (mode == GREY)
	{
		smooth_col = vec4(aPos * 0.4f + 0.4f, 1.0f);
		flat_col = smooth_col;
	}
}
