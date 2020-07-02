/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:38:06 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 09:57:09 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

t_mat4 	perspective(float fov, float aspect, float near, float far)
{
	t_mat4		ret;
	float 		tanhalffov;

	m4_set(&ret, 0.0f);
	tanhalffov = tan(fov / 2);
	ret.m[0] = 1 / (aspect * tanhalffov);
	ret.m[5] = 1 / (tanhalffov);
	ret.m[10] = - (far + near) / (far - near);
	ret.m[11] = - 1;
	ret.m[14] = - (2 * far * near) / (far - near);
//	printf("\nMatrix print####\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n%f  %f  %f  %f\n################",
//		   ret.m[0], ret.m[1], ret.m[2], ret.m[3], ret.m[4], ret.m[5], ret.m[6], ret.m[7],
//		   ret.m[8], ret.m[9], ret.m[10], ret.m[11], ret.m[12], ret.m[13], ret.m[14], ret.m[15]);
	return (ret);
}

// ROW MAJOR [X][Y] {x = 0 4 8 12, y = 0 1 2 3}
t_mat4	look_at(t_fvec3 pos, t_fvec3 center, t_fvec3 up)
{
	t_fvec3		fwrd;
	t_fvec3		rght;
	t_fvec3		tmp;
	t_mat4		ret;

	fwrd = fv3_normalize(fv3_sub(pos, center));
	rght = fv3_normalize(fv3_cross(fwrd, up));
	tmp = fv3_cross(rght, fwrd);

	ret.m[0] = rght.x;
	ret.m[1] = rght.y;
	ret.m[2] = rght.z;
	ret.m[4] = tmp.x;
	ret.m[5] = tmp.y;
	ret.m[6] = tmp.z;
	ret.m[8] = -fwrd.x;
	ret.m[9] = -fwrd.y;
	ret.m[10] = -fwrd.z;
	ret.m[12] = -fv3_dot(rght, pos);
	ret.m[13] = -fv3_dot(tmp, pos);
	ret.m[14] = -fv3_dot(fwrd, pos);
	ret.m[15] = 1; // TODO could be wrong lmao
	return (ret);
}

