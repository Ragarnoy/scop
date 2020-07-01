/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:30:37 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/01 15:52:23 by tlernoul         ###   ########.fr       */
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

float 	*delist_verts(t_vert *start, size_t size)
{
	size_t 	i;
	float 	*ret;
	t_vert	*tmp;

	i = 0;
	ret = ft_memalloc(sizeof(float) * (size * 3));
	tmp = start;
	while (i < size)
	{
		ret[i * 3 + 0] = tmp->v.x;
		ret[i * 3 + 1] = tmp->v.y;
		ret[i * 3 + 2] = tmp->v.z;
		printf("VERT %zu: %f %f %f\n", i, ret[i * 3 + 0], ret[i * 3 + 1], ret[i * 3 + 2]);
		free(tmp);
		tmp = tmp->next;
		i++;
	}
	//TODO Free
	return (ret);
}

unsigned int 	*delist_faces(t_faces *start, size_t size, t_env *env)
{
	size_t			i;
	unsigned int	*ret;
	t_faces			*tmp;
	size_t 			isize;

	isize = 0;
	i = 0;
	ret = ft_memalloc(sizeof(unsigned int) * (size * 5));
	ft_bzero(ret, sizeof(unsigned int) * (size * 4));
	printf("memsize = %zu\n", size * 4);
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
			printf("FACE4 %zu: %u %u %u\n        %u %u %u\n", (i-1), ret[(i-1) * 3 + 0],
					ret[(i-1) * 3 + 1], ret[(i-1) * 3 + 2], ret[(i-1) * 3 + 3], ret[(i-1) * 3 + 4], ret[(i-1) * 3 + 5]);
		} else {
			printf("FACE %zu: %u %u %u\n", i, ret[i * 3 + 0], ret[i * 3 + 1], ret[i * 3 + 2]);}
//		free(tmp);
		tmp = tmp->next;
		i++;
	}
	printf("%zu\n", isize);
	//TODO Free
	env->obj->isize = isize;
	for (unsigned int j = 0; j < isize; j++)
	{
		ft_putnbr(ret[j]);
		ft_putchar(' ');
	}
	ft_putendl("");
	return (ret);
}

size_t 	count_verts(t_vert *verts)
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

size_t 	count_faces(t_faces *faces)
{
	size_t	size;
	t_faces	*tmp;

	size = 0;
	tmp = faces;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
