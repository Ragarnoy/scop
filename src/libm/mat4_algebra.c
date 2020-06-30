/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_algebra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:52:10 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/30 12:08:22 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"
#include <stdio.h>

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
	m->m[5] = cosf(theta);
	m->m[6] = sinf(theta);
	m->m[9] = -sinf(theta);
	m->m[10] = cosf(theta);
}

static void	ret_axis_y_rot_matrix(t_mat4 *m, float theta)
{
	m->m[0] = cosf(theta);
	m->m[2] = -sinf(theta);
	m->m[8] = sinf(theta);
	m->m[10] = cosf(theta);
}


static void	ret_axis_z_rot_matrix(t_mat4 *m, float theta)
{
	m->m[0] = cosf(theta);
	m->m[1] = sinf(theta);
	m->m[4] = -sinf(theta);
	m->m[5] = cosf(theta);
}

t_mat4 		m4_rotate_axis(t_mat4 m, t_axis axis, float angle)
{
	t_mat4	r;
	float	theta;

	m4_set(&r, (float)IDENTITY);
	theta = angle * (float)(M_PI / 180);
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

t_mat4 		m4_translate(t_mat4 mat, t_fvec3 vec)
{
	t_mat4 ret;

	ret = m4_copy(&ret, mat);
	ret.m[12] = mat.m[0] * vec.x + mat.m[4] * vec.y + mat.m[8] * vec.z;
	ret.m[13] = mat.m[1] * vec.x + mat.m[5] * vec.y + mat.m[9] * vec.z;
	ret.m[14] = mat.m[2] * vec.x + mat.m[6] * vec.y + mat.m[10] * vec.z;
	ret.m[15] = 1.0f;
//	printf("\nMatrix print####\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n################",
//		   mat.m[0], mat.m[1], mat.m[2], mat.m[3], mat.m[4], mat.m[5], mat.m[6], mat.m[7],
//		   mat.m[8], mat.m[9], mat.m[10], mat.m[11], mat.m[12], mat.m[13], mat.m[14], mat.m[15]);
	return (ret);
}

t_mat4 m4_rotate(t_mat4 mat, float angle, t_fvec3 ax)
{
	t_mat4	r;
	float 	cosa;
	float 	sina;
	t_fvec3	axis;
	t_fvec3	tmp;

	m4_set(&r, IDENTITY);
	cosa = cosf(angle);
	sina = sinf(angle);
	axis = fv3_normalize(ax);
	tmp = (t_fvec3){(1.0f - cosa) * axis.x, (1.0f - cosa) * axis.y, (1.0f - cosa) * axis.z};

	r.m[0] = cosa + tmp.x * axis.x;
	r.m[1] = 0 + tmp.x * axis.y + sina * axis.z;
	r.m[2] = 0 + tmp.x * axis.z - sina * axis.y;

	r.m[4] = 0 + tmp.y * axis.x - sina * axis.z;
	r.m[5] = cosa + tmp.y * axis.y;
	r.m[6] = 0 + tmp.y * axis.z + sina * axis.x;

	r.m[8] = 0 + tmp.z * axis.x + sina * axis.y;
	r.m[9] = 0 + tmp.z * axis.y - sina * axis.x;
	r.m[10] = cosa + tmp.z * axis.z;
	return (m4_mul(mat, r));
}