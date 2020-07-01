/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:32:59 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/01 17:42:05 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

int	setup_gl(t_env *env)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
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
	if (!(bmp = ft_parse_bmp("textures/wall.bmp")))
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

	float			*vertices;
	unsigned int	*indices;
	vertices = delist_verts(env->obj->vertices, env->obj->vsize);
	indices = delist_faces(env->obj->indices, env->obj->isize, env);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, (env->obj->vsize * 3) * sizeof(float), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (env->obj->isize) * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3 * sizeof(float)));

//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (1);
}

int	setup_shader(t_env *env)
{
	int vertShader;
	int fragShader;
	int success;

    vertShader = load_vert("src/shaders/camera.vert");
	fragShader = load_frag("src/shaders/camera.frag");
	env->shProgram = glCreateProgram();
	glAttachShader(SHADERPROGRAM, vertShader);
	glAttachShader(SHADERPROGRAM, fragShader);
	glLinkProgram(SHADERPROGRAM);
	glGetProgramiv(SHADERPROGRAM, GL_LINK_STATUS, &success);
	if (!success)
		glProgramLogError(SHADERPROGRAM);
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
	m4_set(&env->mvp.model, IDENTITY);
	m4_set(&env->mvp.proj, IDENTITY);
	m4_set(&env->mvp.view, IDENTITY);
	return (env);
}

