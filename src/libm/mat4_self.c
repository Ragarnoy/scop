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

void		m4_set(t_mat4 *m, float f)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		if ((int)f == 0x7FFFFFFF)
			m->m[i] = (i % 5 == 0 ? 1 : 0);
		else
			m->m[i] = f;
	}
}

t_mat4	 	m4_copy(t_mat4 *in, t_mat4 to_copy)
{
	int i;

	i = -1;
	while (++i < 16)
		in->m[i] = to_copy.m[i];
	return (*in);
}
