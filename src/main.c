/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:50:39 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/10 17:46:44 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void	framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void	processInput(GLFWwindow *win)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(win, 1);
}

int	main(int argc, char *argv[])
{
	t_env *env;

	if (argc != 1 || !argv[1])
		shutdown(0);
	env = get_env();
	if (!setup_gl(env))
		return -1;
	while (!glfwWindowShouldClose(env->window))
	{
		processInput(env->window);
		glfwSwapBuffers(env->window);
		glfwPollEvents();
		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glfwTerminate();
	return 0;
}
