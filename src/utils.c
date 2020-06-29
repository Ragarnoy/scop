/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:39:56 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/29 14:09:58 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void 	set_uniform_4f(char *uniform, float r, float g, float b, float a)
{
	int 	id;
	t_env	*env;

	env = get_env();
	id = glGetUniformLocation(env->shProgram, uniform);
	glUniform4f(id, r, g, b, a);
}

void 	set_uniform_3f(char *uniform, float r, float g, float b)
{
	int 	id;
	t_env	*env;

	env = get_env();
	id = glGetUniformLocation(env->shProgram, uniform);
	glUniform3f(id, r, g, b);
}

void 	set_uniform_i(char *uniform, int a)
{
	int 	id;
	t_env	*env;

	env = get_env();
	id = glGetUniformLocation(env->shProgram, uniform);
	glUniform1i(id, a);
}

void 	set_uniform_m4(char *uniform, unsigned int size, int transpose, const float *mat)
{
	int 	id;
	t_env	*env;

	env = get_env();
	id = glGetUniformLocation(env->shProgram, uniform);
	glUniformMatrix4fv(id, size, transpose, mat);
}
