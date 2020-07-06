/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:50:39 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/06 13:03:36 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>

t_obj		*parse_obj(char *pth)
{
	int		fd;
	t_obj	*obj;

	fd = 0;
	obj = NULL;
	if (ft_strlen(pth) >= 5 && !ft_strstr(
			pth + (ft_strlen(pth) - 4), ".obj"))
		return (NULL);
	if ((fd = open(pth, O_RDONLY)) < 1)
		return (NULL);
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return (NULL);
	ft_bzero(obj, sizeof(t_obj));
	obj = fill_list(fd, obj);
	set_max(obj, obj->vertices);
	set_min(obj, obj->vertices);
	return (obj);
}

void		process_input(t_env *env)
{
	if (glfwGetKey(env->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->window, 1);
	else if (glfwGetKey(env->window, GLFW_KEY_KP_0) == GLFW_PRESS)
		glUniform1i(env->uni.colmode, 0);
	else if (glfwGetKey(env->window, GLFW_KEY_KP_1) == GLFW_PRESS)
		glUniform1i(env->uni.colmode, 1);
	else if (glfwGetKey(env->window, GLFW_KEY_KP_2) == GLFW_PRESS)
		glUniform1i(env->uni.colmode, 2);
	else if (glfwGetKey(env->window, GLFW_KEY_KP_3) == GLFW_PRESS)
		glUniform1i(env->uni.colmode, 3);
	else if (glfwGetKey(env->window, GLFW_KEY_KP_EQUAL) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (glfwGetKey(env->window, GLFW_KEY_KP_DIVIDE) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else
		movement(env);
}

static void	display_loop(t_env *env)
{
	glUseProgram(env->shader);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	glad_glUniform1f(env->uni.lerp, 0.0f);
	while (!glfwWindowShouldClose(env->window))
	{
		set_mvp(env);
		process_input(env);
		set_color(env);
		glBindVertexArray(env->vao);
		glDrawElements(GL_TRIANGLES, env->obj->isize, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(env->window);
		glfwPollEvents();
		if (glGetError() != GL_NO_ERROR)
			ft_putendl("Encountered major error during display loop.");
	}
	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	glDeleteProgram(env->shader);
}

int			main(int argc, char *argv[])
{
	t_env	*env;

	if (argc != 2 || !argv[1])
		shutdown(0);
	env = get_env();
	if (!(env->obj = parse_obj(argv[1])))
		shutdown(4);
	if (!setup_gl(env))
		shutdown(5);
	if (!setup_shader(env))
		shutdown(5);
	if (!setup_vertex(env))
		shutdown(6);
	if (!setup_texture(env))
		shutdown(7);
	env->cam = (t_fvec3){0.0f, 0.0f, -(env->obj->max.z -
					env->obj->min.z) * 2.0f};
	env->mvp.model = m4_translate(env->mvp.model, (t_fvec3){
		-(env->obj->max.x + env->obj->min.x) / 2.0f, -(env->obj->max.y +
		env->obj->min.y) / 2.0f, -(env->obj->max.z + env->obj->min.z) / 2.0f});
	display_loop(env);
	glfwTerminate();
	return (0);
}
