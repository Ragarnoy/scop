/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:38:06 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/25 19:22:17 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

// x - y |
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
	return (ret);
}

