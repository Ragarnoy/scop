/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:32:59 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/15 14:25:50 by tlernoul         ###   ########.fr       */
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
	return 1;
}

int	setup_vertex(t_env *env)
{
    // TODO ideally pass shapes here maybe?
//    float vertices[] = {
//            -0.5f, -0.5f, 0.0f, // left
//            0.5f, -0.5f, 0.0f, // right
//            0.0f,  0.5f, 0.0f  // top
//    };

	float vertices[] = {
			0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
			0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top

	};

    glGenVertexArrays(1, &env->vao);
    glGenBuffers(1, &env->vbo);
	glBindVertexArray(env->vao);
    glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return 1;
}

int	setup_shader(t_env *env)
{
	int vertShader;
	int fragShader;
	int success;

    vertShader = loadVert("src/vert/triangle.vert");
	fragShader = loadFrag("src/frag/triangle.frag");
	env->shProgram = glCreateProgram();
	glAttachShader(env->shProgram, vertShader);
	glAttachShader(env->shProgram, fragShader);
	glLinkProgram(env->shProgram);
	glGetProgramiv(env->shProgram, GL_LINK_STATUS, &success);
	if (!success)
		glProgramLogError(env->shProgram);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
	return 1;
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

