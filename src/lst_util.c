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

t_face			*lst_facenew(uint16_t a, uint16_t b, uint16_t c, uint16_t d)
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

t_vert			*lst_vertdelone(t_vert *list)
{
	t_vert	*tmp;

	tmp = list;
	tmp = tmp->next;
	free(list);
	return (tmp);
}

t_face			*lst_facesdelone(t_face *list)
{
	t_face	*tmp;

	tmp = list;
	tmp = tmp->next;
	free(list);
	return (tmp);
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

float			*delist_verts(t_vert *start, size_t size)
{
	size_t	i;
	float	*ret;
	t_vert	*tmp;

	i = 0;
	ret = ft_memalloc(sizeof(float) * (size * 3));
	tmp = start;
	while (i < size)
	{
		ret[i * 3 + 0] = tmp->v.x;
		ret[i * 3 + 1] = tmp->v.y;
		ret[i * 3 + 2] = tmp->v.z;
		tmp = lst_vertdelone(tmp);
		i++;
	}
	return (ret);
}

unsigned int	*delist_faces(t_face *start, size_t size, t_env *env)
{
	size_t			i;
	unsigned int	*ret;
	t_face			*tmp;
	size_t			isize;

	isize = 0;
	i = 0;
	ret = ft_memalloc(sizeof(unsigned int) * (size * 5));
	ft_bzero(ret, sizeof(unsigned int) * (size * 4));
	tmp = start;
	while (tmp)
	{
		ret[i * 3 + 0] = tmp->uv.x - 1;
		ret[i * 3 + 1] = tmp->uv.y - 1;
		ret[i * 3 + 2] = tmp->uv.z - 1;
		isize += 3;
		if (tmp->uv.w != 0)
		{
			isize += 3;
			i++;
			ret[i * 3 + 0] = tmp->uv.z - 1;
			ret[i * 3 + 1] = tmp->uv.w - 1;
			ret[i * 3 + 2] = tmp->uv.x - 1;
		}
		tmp = lst_facesdelone(tmp);
		i++;
	}
	env->obj->isize = isize;
	return (ret);
}

size_t			count_verts(t_vert *verts)
{
	size_t	size;
	t_vert	*tmp;

	size = 0;
	tmp = verts;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

size_t			count_faces(t_face *faces)
{
	size_t	size;
	t_face	*tmp;

	size = 0;
	tmp = faces;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
