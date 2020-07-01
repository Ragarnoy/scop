#version 410 core
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec2 aTexCoord;

smooth out vec4 face_col;
//out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	face_col = vec4(aPos.y * 0.4f + 0.4f, aPos.z * 0.1 + aPos.y * 0.4f + 0.1f, 0.2f, 1.0f);
//	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}
