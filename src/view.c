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

t_mat4	perspective(float fov, float aspect, float near, float far)
{
	t_mat4		ret;
	float		tanhalffov;

	m4_set(&ret, 0.0f);
	tanhalffov = tan(fov / 2);
	ret.m[0] = 1 / (aspect * tanhalffov);
	ret.m[5] = 1 / (tanhalffov);
	ret.m[10] = -(far + near) / (far - near);
	ret.m[11] = -1;
	ret.m[14] = -(2 * far * near) / (far - near);
	return (ret);
}
