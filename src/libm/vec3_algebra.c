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

float 		fvec3_magnitude(t_fvec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_fvec3		fvec3_normalize(t_fvec3 v)
{
	float mag;

	mag = fvec3_magnitude(v);
	v.x /= mag;
	v.y /= mag;
	v.z /= mag;
	return (v);
}

t_fvec3		fvec3_scale(t_fvec3 v, float f)
{
	fvec3_magnitude(v);
	v.x *= f;
	v.y *= f;
	v.z *= f;
	return (v);
}

t_fvec3		fvec3_cross(t_fvec3 a, t_fvec3 b)
{
	t_fvec3		tmp;

	tmp.x = a.y * b.z - a.z * b.y;
	tmp.y = a.z * b.x - a.x * b.z;
	tmp.z = a.x * b.y - a.y * b.x;
	fvec3_copy(&a, &tmp);
	return (a);
}