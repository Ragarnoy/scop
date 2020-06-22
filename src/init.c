/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:32:59 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/18 12:39:44 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

int	setup_gl(t_env *env)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (APPLE)
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	env->window = glfwCreateWindow(800, 600, "Ouais_ok", NULL, NULL);
	if (env->window == NULL)
		return (shutdown(1));
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (shutdown(2));
	return (1);
}


int setup_texture(t_env *env)
{
	t_bmp			*bmp;

	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	if (!(bmp = ft_parse_bmp("/Users/tlernoul/Downloads/wall.bmp")))
	{
		return (0);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp->fheader.width, bmp->fheader.height,
			0, GL_RGBA, GL_UNSIGNED_BYTE, bmp->img);
	glGenerateMipmap(GL_TEXTURE_2D);
	ft_free_bmp(bmp);
	return (1);
}

int	setup_vertex(t_env *env)
{
    // TODO ideally pass shapes here maybe?
//	float vertices[] = {
//			0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
//			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
//			0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
//
//	};

	float vertices[] = {
			// positions          // colors           // texture coords
			0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
	};

	unsigned int indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
	};

    glGenVertexArrays(1, &env->vao);
    glGenBuffers(1, &env->vbo);
    glGenBuffers(1, &env->ebo);

	glBindVertexArray(env->vao);

    glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
	return (1);
}

int	setup_shader(t_env *env)
{
	int vertShader;
	int fragShader;
	int success;

    vertShader = load_vert("src/shaders/triangle.vert");
	fragShader = load_frag("src/shaders/triangle.frag");
	env->shProgram = glCreateProgram();
	glAttachShader(env->shProgram, vertShader);
	glAttachShader(env->shProgram, fragShader);
	glLinkProgram(env->shProgram);
	glGetProgramiv(env->shProgram, GL_LINK_STATUS, &success);
	if (!success)
		glProgramLogError(env->shProgram);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
	return (1);
}

t_env	*get_env(void)
{
	static t_env *env = NULL;

	if (env)
		return (env);
	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(-1);
	return (env);
}

