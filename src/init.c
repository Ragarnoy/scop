/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:32:59 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 17:08:02 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

int			setup_gl(t_env *env)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	if (APPLE)
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	env->window = glfwCreateWindow(800, 600, "SCOP", NULL, NULL);
	if (env->window == NULL)
		return (shutdown(1));
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, frmbuff_size_cback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (shutdown(2));
	return (1);
}

int			setup_texture(t_env *env)
{
	t_bmp			*bmp;

	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	if (!(bmp = ft_parse_bmp("textures/wall.bmp")))
		return (0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
			bmp->fheader.width, bmp->fheader.height,
			0, GL_RGBA, GL_UNSIGNED_BYTE, bmp->img);
	glGenerateMipmap(GL_TEXTURE_2D);
	ft_free_bmp(bmp);
	return (1);
}

int			setup_vertex(t_env *env)
{
	float			*vertices;
	unsigned int	*indices;

	vertices = delist_verts(env->obj->vertices, env->obj->vsize);
	indices = delist_faces(env->obj->indices, env->obj->isize, env);
	glGenVertexArrays(1, &env->vao);
	glGenBuffers(1, &env->vbo);
	glGenBuffers(1, &env->ebo);
	glBindVertexArray(env->vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER, (env->obj->vsize * 3) * sizeof(float),
			vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			(env->obj->isize) * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT,
			GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
			(void*)(3 * sizeof(float)));
	free(vertices);
	free(indices);
	return (1);
}

int			setup_shader(t_env *env)
{
	int	vert_shader;
	int	frag_shader;
	int	success;

	vert_shader = load_vert("src/shaders/camera.vert");
	frag_shader = load_frag("src/shaders/camera.frag");
	env->shader = glCreateProgram();
	glAttachShader(env->shader, vert_shader);
	glAttachShader(env->shader, frag_shader);
	glLinkProgram(env->shader);
	glGetProgramiv(env->shader, GL_LINK_STATUS, &success);
	if (!success)
		glprogram_log_error(env->shader);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	env->uni.model = glGetUniformLocation(env->shader, "model");
	env->uni.proj = glGetUniformLocation(env->shader, "projection");
	env->uni.view = glGetUniformLocation(env->shader, "view");
	env->uni.vtxcol = glGetUniformLocation(env->shader, "vertexColor");
	env->uni.colmode = glGetUniformLocation(env->shader, "mode");
	env->uni.lerp = glGetUniformLocation(env->shader, "lerp");
	return (1);
}

t_env		*get_env(void)
{
	static t_env *env = NULL;

	if (env)
		return (env);
	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(-1);
	ft_bzero(env, sizeof(t_env));
	m4_set(&env->mvp.model, IDENTITY);
	m4_set(&env->mvp.proj, IDENTITY);
	m4_set(&env->mvp.view, IDENTITY);
	env->cam = (t_fvec3){0.0f, 0.0f, -6.5f};
	env->rotdir = (t_fvec3) {0.0f, 0.3f, 0.0f};
	env->rotspeed = 0.01f;
	env->lerp = 0.0f;
	return (env);
}
