#version 410 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform vec4        vertexColor;
uniform sampler2D   ourTexture;

void	main()
{
	FragColor = texture(ourTexture, TexCoord) + vertexColor;
}
