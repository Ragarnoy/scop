/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:50:39 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/22 11:22:37 by tlernoul         ###   ########.fr       */
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
	int     retCode;
	float   timeValue;
	float   colorShift;
	float   _greenValue;
	float   _redValue;
	float   _blueValue;

	retCode = 1;
	glUseProgram(env->shProgram);
	while (!glfwWindowShouldClose(env->window))
	{
		timeValue = glfwGetTime();
		colorShift = (sin(timeValue) / 2.0f);
		processInput(env->window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		_greenValue = colorShift + 0.4f;
		_redValue = colorShift + 0.4f;
		_blueValue = colorShift + 0.4f;
//		set_uniform_4f("vertexColor", _redValue, _greenValue, _blueValue, 1.0f);
		glBindTexture(GL_TEXTURE_2D, env->texture);
		glBindVertexArray(env->vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(env->window);
        glfwPollEvents();
	}

	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	glDeleteProgram(env->shProgram);
	return (retCode);
}

int	main(int argc, char *argv[])
{
	t_env *env;

	if (argc != 2 || !argv[1])
		shutdown(0);
	parse_obj(argv[1]);
	return 1;
	env = get_env();
	if (!setup_gl(env))
		return (-1);
    if (!setup_shader(env))
    	return (-1);
    if (!setup_vertex(env))
    	return (-1);
    if (!setup_texture(env))
		return (-1);
	display_loop(env);
	glfwTerminate();
	return 0;
}
