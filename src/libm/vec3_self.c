/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_self.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:10:57 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/23 16:42:48 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"

void		fvec3_set(t_fvec3 *v, float f)
{
	v->x = f;
	v->y = f;
	v->z = f;
}

t_fvec3 	fvec3_copy(t_fvec3 *in, t_fvec3 *to_copy)
{
	in->x = to_copy->x;
	in->y = to_copy->y;
	in->z = to_copy->z;
	return (*in);
}