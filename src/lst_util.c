/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:30:37 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/29 09:41:09 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

t_vert		*lst_vertnew(float x, float y, float z)
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

t_faces 	*lst_facenew(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
{
	t_faces	*new;
	if (!(new = ft_memalloc(sizeof(t_faces))))
		return (NULL);

	new->uv.x = a;
	new->uv.y = b;
	new->uv.z = c;
	new->uv.w = d;
	new->next = NULL;
	return (new);
}

void 	lst_vertdel(t_vert **list)
{
	t_vert	*tmp;

	tmp = *list;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	*list = NULL;
}

void 	lst_facesdel(t_faces **list)
{
	t_faces	*tmp;

	tmp = *list;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	*list = NULL;
}

void	vertice_add(t_vert *vert, t_obj *ret, t_vert **last_vert)
{
	if (*last_vert == NULL)
		ret->vertices = vert;
	else
		(*last_vert)->next = vert;
	*last_vert = vert;
}


void	face_add(t_faces *face, t_obj *ret, t_faces **last_face)
{
	if (*last_face == NULL)
		ret->indices = face;
	else
		(*last_face)->next = face;
	*last_face = face;
}

float 	*delist_verts(t_vert *start)
{
	int		i;
	float 	*ret;
	t_vert	*tmp;

	i = 0;
	tmp = start;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	ret = ft_memalloc(sizeof(float) * (i * 3));
	tmp = start;
	while (i > 0)
	{
		ret[i * 3 + 0] = tmp->v.x;
		ret[i * 3 + 1] = tmp->v.y;
		ret[i * 3 + 2] = tmp->v.z;
		free(tmp);
		tmp = tmp->next;
		i--;
	}
	//TODO Free
	return (ret);
}

int 	*delist_faces(t_faces *start)
{
	int		i;
	int 	*ret;
	t_faces	*tmp;

	i = 0;
	tmp = start;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	ret = ft_memalloc(sizeof(int) * (i * 4));
	tmp = start;
	while (i > 0)
	{
		ret[i * 3 + 0] = tmp->uv.x;
		ret[i * 3 + 1] = tmp->uv.y;
		ret[i * 3 + 2] = tmp->uv.z;
		ret[i * 3 + 3] = tmp->uv.w;
		free(tmp);
		tmp = tmp->next;
		i--;
	}
	//TODO Free
	return (ret);
}
