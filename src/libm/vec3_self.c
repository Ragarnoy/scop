/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_self.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:10:57 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/24 11:18:55 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"

void		fv3_set(t_fvec3 *v, float f)
{
	v->x = f;
	v->y = f;
	v->z = f;
}

t_fvec3 	fv3_copy(t_fvec3 *in, t_fvec3 *to_copy)
{
	in->x = to_copy->x;
	in->y = to_copy->y;
	in->z = to_copy->z;
	return (*in);
}