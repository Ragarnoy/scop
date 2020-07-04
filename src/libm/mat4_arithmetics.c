/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_arithmetics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:35:44 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/24 11:26:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"

t_mat4		m4_add(t_mat4 a, t_mat4 b)
{
	int i;

	i = -1;
	while (++i < 16)
		a.m[i] += b.m[i];
	return (a);
}

t_mat4		m4_sub(t_mat4 a, t_mat4 b)
{
	int i;

	i = -1;
	while (++i < 16)
		a.m[i] -= b.m[i];
	return (a);
}

t_mat4		m4_mul(t_mat4 a, t_mat4 b)
{
	int		x;
	int		y;
	int		z;
	t_mat4	m;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			z = -1;
			m.m[x * 4 + y] = 0;
			while (++z < 4)
				m.m[x * 4 + y] += a.m[x * 4 + z] * b.m[z * 4 + y];
		}
	}
	return (m);
}

t_mat4		m4_scale(t_mat4 m, float f)
{
	int i;

	i = -1;
	while (++i < 16)
		m.m[i] *= f;
	return (m);
}
