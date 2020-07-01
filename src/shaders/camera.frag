#version 410 core
out vec4    FragColor;

in vec2     TexCoord;
smooth in vec4 face_col;

uniform vec4 vertexColor;
uniform sampler2D   texture1;

void main()
{
	FragColor = vertexColor + face_col;
}
