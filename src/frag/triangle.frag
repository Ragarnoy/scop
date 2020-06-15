#version 410 core
out vec4 FragColor;

in vec3 ourColor;
uniform vec4 vertexColor;

void	main()
{
	FragColor = vec4(ourColor, 1.0) + vertexColor;
}
