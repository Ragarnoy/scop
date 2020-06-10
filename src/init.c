/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:32:59 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/10 17:44:04 by tlernoul         ###   ########.fr       */
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

t_env	*get_env(void)
{
	static t_env *env = NULL;

	if (env)
		return (env);
	if (!(env = ft_memalloc(sizeof(t_env))))
		exit(-1);
	return (env);
}

