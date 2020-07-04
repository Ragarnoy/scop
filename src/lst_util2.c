/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:30:37 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/04 19:02:39 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

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

void			assign_face(unsigned int **ret, size_t *i,
		size_t size, size_t *isize)
{
	*ret = ft_memalloc(sizeof(unsigned int) * (size * 5));
	ft_bzero(*ret, sizeof(unsigned int) * (size * 5));
	*isize = 0;
	*i = 0;
}

unsigned int	*delist_faces(t_face *start, size_t size, t_env *env)
{
	size_t			i;
	unsigned int	*ret;
	t_face			*tmp;
	size_t			isize;

	assign_face(&ret, &i, size, &isize);
	tmp = start;
	while (tmp)
	{
		ret[i * 3 + 0] = tmp->uv.x - 1;
		ret[i * 3 + 1] = tmp->uv.y - 1;
		ret[i * 3 + 2] = tmp->uv.z - 1;
		isize += 3;
		if (tmp->uv.w != 0 && (isize += 3))
		{
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
