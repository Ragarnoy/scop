/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:39:56 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/17 14:42:20 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void 	set_uniform_4f(char *uniform, float r, float g, float b, float a)
{
	int 	vertex;
	t_env	*env;

	env = get_env();
	vertex = glGetUniformLocation(env->shProgram, uniform);
	glUniform4f(vertex, r, g, b, a);
}

void 	set_uniform_3f(char *uniform, float r, float g, float b)
{
	int 	vertex;
	t_env	*env;

	env = get_env();
	vertex = glGetUniformLocation(env->shProgram, uniform);
	glUniform3f(vertex, r, g, b);
}
