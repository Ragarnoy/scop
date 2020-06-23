/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_algebra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:52:10 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/23 16:08:15 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"

t_mat4 		m4_transpose(t_mat4 m)
{
	int 	x;
	int 	y;
	t_mat4	t;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			t.m[y * 4 + x] = m.m[x * 4 + y];
	}
	m = m4_copy(&m, t);
	return (m);
}

static void	ret_axis_x_rot_matrix(t_mat4 *m, float theta)
{
	m->m[5] = cos(theta);
	m->m[6] = sin(theta);
	m->m[9] = -sin(theta);
	m->m[10] = cos(theta);
}

static void	ret_axis_y_rot_matrix(t_mat4 *m, float theta)
{
	m->m[0] = cos(theta);
	m->m[2] = -sin(theta);
	m->m[8] = sin(theta);
	m->m[10] = cos(theta);
}


static void	ret_axis_z_rot_matrix(t_mat4 *m, float theta)
{
	m->m[0] = cos(theta);
	m->m[1] = sin(theta);
	m->m[4] = -sin(theta);
	m->m[5] = cos(theta);
}

t_mat4 		m4_rotate_axis(t_mat4 m, t_axis axis, float angle)
{
	t_mat4	r;
	float	theta;

	m4_set(&r, (float)0x7FFFFFFF);
	theta = angle * (M_PI / 180);
	if (axis == AXIS_X)
	{
		ret_axis_x_rot_matrix(&r, theta);
		m = m4_mul(m, r);
	}
	if (axis == AXIS_Y)
	{
		ret_axis_y_rot_matrix(&r, theta);
		m = m4_mul(m, r);
	}
	if (axis == AXIS_Z)
	{
		ret_axis_z_rot_matrix(&r, theta);
		m = m4_mul(m, r);
	}
	return (m);
}
