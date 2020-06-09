/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:50:39 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/09 17:00:49 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include "/Users/tlernoul/.brew/Cellar/glfw/3.3.2/include/GLFW/glfw3.h"

int	main(int argc, char *argv[])
{
	GLFWwindow *win = NULL;
	if (argc != 1)
		return (0);
	if (!argv[0])
		return (0);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	win = glfwCreateWindow(800, 600, "Ouais ok", NULL, NULL);
	if (win == NULL)
	{
		ft_putendl("ahaha");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);
	glViewport(0, 0, 800, 600);
	while (!glfwWindowShouldClose(win))
	{
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
