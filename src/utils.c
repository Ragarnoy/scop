/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:39:56 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 17:12:34 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void		movement(t_env *env)
{
	if (env->cam.z < 10.0f && glfwGetKey(env->window, GLFW_KEY_PAGE_UP)
														== GLFW_PRESS)
		env->cam.z += 0.1f;
	else if (env->cam.z > -100.f && glfwGetKey(env->window, GLFW_KEY_PAGE_DOWN)
														== GLFW_PRESS)
		env->cam.z -= 0.1f;
	if (glfwGetKey(env->window, GLFW_KEY_UP) == GLFW_PRESS)
		env->cam.y += 0.01f;
	if (glfwGetKey(env->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		env->cam.y -= 0.01f;
	if (glfwGetKey(env->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		env->cam.x -= 0.01f;
	if (glfwGetKey(env->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		env->cam.x += 0.01f;
	else if (env->rotspeed < 10.0f && glfwGetKey(env->window,
								GLFW_KEY_KP_ADD) == GLFW_PRESS)
		env->rotspeed += 0.001f;
	else if (env->rotspeed > 0.000001f && glfwGetKey(env->window,
								GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
		env->rotspeed -= 0.001f;
}

void		framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void		set_mvp(t_env *env)
{
	env->mvp.model = m4_rotate(env->mvp.model, env->rotspeed, env->rot);
	env->mvp.view = m4_translate(env->mvp.view, env->cam);
	env->mvp.proj = perspective(deg_to_rad(45.0f),
			800.0f / 600.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(env->uni.model, 1, GL_FALSE,
			(const float *)&env->mvp.model.m);
	glUniformMatrix4fv(env->uni.proj, 1, GL_FALSE,
			(const float *)&env->mvp.proj.m);
	glUniformMatrix4fv(env->uni.view, 1, GL_FALSE,
			(const float *)&env->mvp.view.m);
}

void		set_color(t_env *env)
{
	float			time_value;
	float			color_shift;
	t_fvec3			rgb;
	int 			mode;

	time_value = glfwGetTime();
	color_shift = (sin(time_value) / 2.0f);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rgb.x = color_shift + 0.2f;
	rgb.y = color_shift + 0.1f;
	rgb.z = color_shift + 0.2f;
	glGetUniformiv(env->shader, env->uni.colmode, &mode);
	if (mode == 3 && env->lerp < 1.0f)
		env->lerp += 0.004f;
	else if (mode != 3)
		env->lerp = 0;
	glUniform1f(env->uni.lerp, env->lerp);
	glUniform4f(env->uni.vtxcol, rgb.x, rgb.y, rgb.z, 1.0f);
}
