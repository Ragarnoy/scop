/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:50:39 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/12 17:03:32 by tlernoul         ###   ########.fr       */
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

int	display_loop(t_env *env)
{
	int retcode;

	retcode = 1;
	while (!glfwWindowShouldClose(env->window))
	{
		processInput(env->window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(env->shProgram);
		glBindVertexArray(env->vao);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(env->window);
        glfwPollEvents();
	}

	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	glDeleteProgram(env->shProgram);
	return (retcode);
}

int	main(int argc, char *argv[])
{
	t_env *env;

	if (argc != 2 || !argv[1])
		shutdown(0);
	env = get_env();
	if (!setup_gl(env))
		return -1;
    setup_shader(env);
    setup_vertex(env);
	display_loop(env);
	glfwTerminate();
	return 0;
}
