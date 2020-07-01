/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:26:42 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/01 18:18:25 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>

void		set_max(t_obj *obj, t_vert *tmp)
{
	t_fvec3 val;

	val = (t_fvec3){0.0f, 0.0f, 0.0f};
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

void		set_min(t_obj *obj, t_vert *tmp)
{
	t_fvec3 val;

	val = (t_fvec3){0.0f, 0.0f, 0.0f};
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

t_faces		*ret_faces(char *str)
{
	int		i;
	uint8_t spaces;
	int 	tmp[4];
	int 	size;

	size = ft_strlen(str);
	ft_bzero(tmp, sizeof(int) * 4);
	spaces = 0;
	i = 0;
	while (i < size && spaces < 4)
	{
		if (ft_isdigit(str[i]))
		{
			tmp[spaces] = ft_atoi(str + i);
//			printf("READING : '%s' ||| GETTING : '%d'\n", str + i, tmp[spaces]);
			spaces++;
			while (i < size && str[i] != ' ')
				i++;
		}
		i++;
	}
//	printf("FUCK YOU FUCK YOU FUCK YOU %d %d %d %d\n\n", tmp[0], tmp[1], tmp[2], tmp[3]);
	return (lst_facenew(tmp[0], tmp[1], tmp[2], tmp[3]));
}

t_vert 	*ret_vertices(char *str)
{
	int		i;
	uint8_t spaces;
	float 	tmp[3];
	int 	size;

	size = ft_strlen(str);
	ft_bzero(tmp, sizeof(float) * 3);
	spaces = 0;
	i = 0;
	while (i < size && spaces < 3)
	{
		if (str[i] == '-' || ft_isdigit(str[i]))
		{
			tmp[spaces] = ft_atof(str + i);
//			printf("READING : '%s' ||| GETTING : '%f'\n", str + i, tmp[spaces]);
			spaces++;
			while (i < size && str[i] != ' ')
				i++;
		}
		i++;
	}
//	printf("FUCK YOU FUCK YOU FUCK YOU %f %f %f\n\n", tmp[0], tmp[1], tmp[2]);
	return (lst_vertnew(tmp[0], tmp[1], tmp[2]));
}

t_obj	*fill_list(int fd, t_obj *ret)
{
	char 	*line;
	t_vert	*curv;
	t_vert	*last_vert;
	t_faces	*curf;
	t_faces	*last_curf;

	last_vert = NULL;
	last_curf = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			curv = ret_vertices(line);
//			printf("%f %f %f\n", curv->v.x, curv->v.y, curv->v.z);
			vertice_add(curv, ret, &last_vert);
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			curf = ret_faces(line);
			face_add(curf, ret, &last_curf);
		}
	}
	return (ret);
}

t_obj 	*parse_obj(char *pth)
{
	int 	fd;
	t_obj 	*obj;

	fd = 0;
	obj = NULL;
	if (ft_strlen(pth) >= 5 && !ft_strstr(ft_strsub(pth,
			ft_strlen(pth) - 4, 4), ".obj"))
		return (NULL);
	//TODO CHECK IF EXIST RETARD
	if ((fd = open(pth, O_RDONLY)) == -1)
		return (NULL);
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return(NULL);
	obj->isize = 0;
	obj->vsize = 0;
	obj = fill_list(fd, obj);
	if (obj->vertices)
		obj->vsize = count_verts(obj->vertices);
	if (obj->indices)
		obj->isize = count_faces(obj->indices);
	set_max(obj, obj->vertices);
	set_min(obj, obj->vertices);
	return (obj);
}
