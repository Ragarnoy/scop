/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_arithmetics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:35:44 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/23 15:48:18 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"

t_fvec3		fv3_add(t_fvec3 a, t_fvec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_fvec3		fv3_sub(t_fvec3 a, t_fvec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_fvec3		fv3_mul(t_fvec3 a, t_fvec3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_fvec3		fv3_fmul(t_fvec3 a, float f)
{
	a.x *= f;
	a.y *= f;
	a.z *= f;
	return (a);
}

float		fv3_dot(t_fvec3 a, t_fvec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
