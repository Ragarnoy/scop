/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:26:42 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/23 12:18:34 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>
#include <stdio.h>


t_faces	*ret_faces(char *str)
{
	int		i;
	uint8_t spaces;
	int 	tmp[4];
	int 	size;

	size = ft_strlen(str);
	ft_bzero(tmp, sizeof(int) * 4);
	spaces = 0;
	i = 0;
	while (i < size)
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
	while (i < size)
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
		if (line[0] == 'v')
		{
			curv = ret_vertices(line);
//			printf("%f %f %f\n", curv->v.x, curv->v.y, curv->v.z);
			vertice_add(curv, ret, &last_vert);
		}
		else if (line[0] == 'f')
		{
			curf = ret_faces(line);
			face_add(curf, ret, &last_curf);
		}
	}
	curv = ret->vertices;
	int i = 0;
	while (curv)
	{
		printf("uhh %f %f %f\n", curv->v.x, curv->v.y, curv->v.z);
		curv = curv->next;
		i++;
	}
	printf("%d\n", i);
	return (ret);
}

t_obj 	*parse_obj(char *pth)
{
	int 	fd;
	t_obj 	*obj;

	fd = 0;
	if (ft_strlen(pth) >= 5 && !ft_strstr(ft_strsub(pth,
			ft_strlen(pth) - 4, 4), ".obj"))
		return NULL;
	fd = open(pth, fd, O_RDONLY);
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return(NULL);
	return (fill_list(fd, obj));
}
