/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:30:37 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/19 13:05:10 by tlernoul         ###   ########.fr       */
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

t_faces 	*lst_newface(uint16_t x, uint16_t y, uint16_t z, uint16_t w)
{
	t_faces	*new;
	if (!(new = ft_memalloc(sizeof(t_faces))))
		return (NULL);

	new->uv.x = x;
	new->uv.y = y;
	new->uv.z = z;
	new->uv.w = w;
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
