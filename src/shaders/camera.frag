#version 410 core
#define COLOR 0
#define COLORSHIFT 1
#define GREY 2
#define TEX 3
out vec4    FragColor;

in vec2         TexCoord;
flat in vec4    flat_col;
smooth in vec4  smooth_col;

uniform float       lerp;
uniform int         mode;
uniform vec4        vertexColor;
uniform sampler2D   texture1;

vec4    get_color()
{
	vec4 color = FragColor;
    vec4 texColor;
	float grey;

	if (mode == COLOR)
		color = smooth_col;
	else if (mode == COLORSHIFT)
		color = smooth_col + vertexColor;
	else if (mode == GREY)
	{
		color = flat_col;
		grey = (0.2125 * color.x + 0.7154 * color.y + 0.0721 * color.z) / 1.4f;
		color = vec4(grey, grey, grey, 1.0f);
	}
	else if (mode == TEX)
	{
		texColor = texture(texture1, TexCoord);
		color = mix(color, texColor, lerp);
	}
	return (color);
}

void    main()
{
	FragColor = get_color();
}
