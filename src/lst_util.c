/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:30:37 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 11:53:44 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

t_vert			*lst_vertnew(float x, float y, float z)
{
	t_vert	*new;

	if (!(new = ft_memalloc(sizeof(t_vert))))
		return (NULL);
	new->v.x = x;
	new->v.y = y;
	new->v.z = z;
	new->next = NULL;
	return (new);
}

t_face			*lst_facenew(GLuint a, GLuint b, GLuint c, GLuint d)
{
	t_face	*new;

	if (!(new = ft_memalloc(sizeof(t_face))))
		return (NULL);
	new->uv.x = a;
	new->uv.y = b;
	new->uv.z = c;
	new->uv.w = d;
	new->next = NULL;
	return (new);
}

void			vertice_add(t_vert *vert, t_obj *ret, t_vert **last_vert)
{
	if (*last_vert == NULL)
		ret->vertices = vert;
	else
		(*last_vert)->next = vert;
	*last_vert = vert;
}

void			face_add(t_face *face, t_obj *ret, t_face **last_face)
{
	if (*last_face == NULL)
		ret->indices = face;
	else
		(*last_face)->next = face;
	*last_face = face;
}
