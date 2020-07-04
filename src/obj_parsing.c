/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:26:42 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 09:57:09 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void			set_max(t_obj *obj, t_vert *tmp)
{
	t_fvec3 val;

	val = (t_fvec3){tmp->v.x, tmp->v.y, tmp->v.z};
	while (tmp)
	{
		if (tmp->v.x > val.x)
			val.x = tmp->v.x;
		if (tmp->v.y > val.y)
			val.y = tmp->v.y;
		if (tmp->v.z > val.z)
			val.z = tmp->v.z;
		tmp = tmp->next;
	}
	obj->max = val;
}

void			set_min(t_obj *obj, t_vert *tmp)
{
	t_fvec3 val;

	val = (t_fvec3){tmp->v.x, tmp->v.y, tmp->v.z};
	while (tmp)
	{
		if (tmp->v.x < val.x)
			val.x = tmp->v.x;
		if (tmp->v.y < val.y)
			val.y = tmp->v.y;
		if (tmp->v.z < val.z)
			val.z = tmp->v.z;
		tmp = tmp->next;
	}
	obj->min = val;
}

t_face			*ret_faces(char *str)
{
	int		i;
	uint8_t	spaces;
	int		tmp[4];
	int		size;

	size = ft_strlen(str);
	ft_bzero(tmp, sizeof(int) * 4);
	spaces = 0;
	i = 0;
	while (i < size && spaces < 4)
	{
		if (ft_isdigit(str[i]))
		{
			tmp[spaces] = ft_atoi(str + i);
			spaces++;
			while (i < size && str[i] != ' ')
				i++;
		}
		i++;
	}
	return (lst_facenew(tmp[0], tmp[1], tmp[2], tmp[3]));
}

t_vert			*ret_vertices(char *str)
{
	int		i;
	int		size;
	uint8_t spaces;
	float	tmp[3];

	size = ft_strlen(str);
	ft_bzero(tmp, sizeof(float) * 3);
	spaces = 0;
	i = 0;
	while (i < size && spaces < 3)
	{
		if (str[i] == '-' || ft_isdigit(str[i]))
		{
			tmp[spaces] = ft_atof(str + i);
			spaces++;
			while (i < size && str[i] != ' ')
				i++;
		}
		i++;
	}
	return (lst_vertnew(tmp[0], tmp[1], tmp[2]));
}

t_obj			*fill_list(int fd, t_obj *ret)
{
	char	*line;
	t_vert	*curv;
	t_vert	*last_vert;
	t_face	*curf;
	t_face	*last_curf;

	last_vert = NULL;
	last_curf = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ' && (ret->vsize += 1))
		{
			curv = ret_vertices(line);
			vertice_add(curv, ret, &last_vert);
		}
		else if (line[0] == 'f' && line[1] == ' ' && (ret->isize += 1))
		{
			curf = ret_faces(line);
			face_add(curf, ret, &last_curf);
		}
		free(line);
	}
	free(line);
	return (ret);
}
