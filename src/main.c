/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:50:39 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/01 18:35:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void		debug_mats(t_mat4 model, t_mat4 view, t_mat4 projection)
{
	printf("\nMatrix print M##\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n################",
		   model.m[0], model.m[1], model.m[2], model.m[3], model.m[4], model.m[5], model.m[6], model.m[7],
		   model.m[8], model.m[9], model.m[10], model.m[11], model.m[12], model.m[13], model.m[14], model.m[15]);
	printf("\nMatrix print V##\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n################",
		   view.m[0], view.m[1], view.m[2], view.m[3], view.m[4], view.m[5], view.m[6], view.m[7],
		   view.m[8], view.m[9], view.m[10], view.m[11], view.m[12], view.m[13], view.m[14], view.m[15]);
	printf("\nMatrix print P##\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n################",
		   projection.m[0], projection.m[1], projection.m[2], projection.m[3], projection.m[4], projection.m[5], projection.m[6], projection.m[7],
		   projection.m[8], projection.m[9], projection.m[10], projection.m[11], projection.m[12], projection.m[13], projection.m[14], projection.m[15]);
}

void		framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void		processInput(GLFWwindow *win)
{
	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(win, 1);
}

static int	display_loop(t_env *env)
{
	int				retCode;
	float			timeValue;
	float			colorShift;
	float			_greenValue;
	float			_redValue;
	float			_blueValue;
	unsigned int 	error;

	error = 0;
	retCode = 1;
	glUseProgram(SHADERPROGRAM);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	env->mvp.model = m4_translate(env->mvp.model, (t_fvec3){-(env->obj->max.x + env->obj->min.x) / 2.0f,
									   -(env->obj->max.y + env->obj->min.y) / 2.0f, -(env->obj->max.z + env->obj->min.z) / 2.0f});
	while (!glfwWindowShouldClose(env->window))
	{
		timeValue = glfwGetTime();
		colorShift = (sin(timeValue) / 2.0f);
		env->mvp.model = m4_rotate(env->mvp.model, 0.01f, (t_fvec3) {0.0f, 0.3f, 0.0f});
		env->mvp.view = m4_translate(env->mvp.view, (t_fvec3){0.0f, -0.5f, -6.5f});
		env->mvp.proj = perspective(deg_to_rad(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		processInput(env->window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		set_uniform_m4("model", 1, GL_FALSE, (const float *)&env->mvp.model.m);
		set_uniform_m4("view", 1, GL_FALSE, (const float *)&env->mvp.view.m);
		set_uniform_m4("projection", 1, GL_FALSE, (const float *)&env->mvp.proj.m);
		_greenValue = colorShift + 0.1f;
		_redValue = colorShift + 0.2f;
		_blueValue = colorShift + 0.2f;
		set_uniform_4f("vertexColor", _redValue, _greenValue, _blueValue, 1.0f);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, env->obj->isize, GL_UNSIGNED_INT, 0);

//		glBindTexture(GL_TEXTURE_2D, env->texture);
		glUseProgram(SHADERPROGRAM);

        glfwSwapBuffers(env->window);
        glfwPollEvents();
		if ((error = glGetError()) != GL_NO_ERROR)
			printf("####%d####\n", error);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(env->shProgram);
	return (retCode);
}

int			main(int argc, char *argv[])
{
	t_env *env;

	if (argc != 2 || !argv[1])
		shutdown(0);
	env = get_env();
	if (!(env->obj = parse_obj(argv[1])))
		return (-1);
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
