/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:26:42 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/19 17:09:18 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>
#include <stdio.h>


t_faces	*ret_faces(char *str)
{
//	int		i;
//	int		tmp;
//
//	tmp = 0;
//	i = 0;
	(void)str;
	return (NULL);
}

t_vert 	*ret_vertices(char *str)
{
	int		i;
	uint8_t spaces;
//	t_fvec3	tmp;
	float 	tmp[3];

	ft_bzero(tmp, sizeof(float) * 3);
	spaces = 0;
	i = -1;
	ft_putendl("Bite2");
	while (str[++i] && str[i] != 'f')
	{
		if (str[i] == '-' || ft_isdigit(str[i]))
		{
			tmp[spaces] = ft_atof(str + i);
			spaces++;
			printf("%lf ", tmp[spaces]);
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (lst_vertnew(tmp[0], tmp[1], tmp[2]));
}

t_obj	*fill_list(int fd)
{
	t_obj	*ret;
	char 	*buf;
	t_vert	*curv;
	t_faces	*curf;

	if (!(ret = ft_memalloc(sizeof(t_obj))))
		return (NULL);
	while (get_next_line(fd, &buf) > 0)
	{
		//TODO Might leak
		if (!ret->vertices && buf[0] == 'v' && (curv = ret_vertices(buf)))
			ret->vertices = curv;
		if (!ret->indices && buf[0] == 'f' && (curf = ret_faces(buf)))
			ret->indices = curf;
		if (buf[0] == 'v' && (curv = ret_vertices(buf)))
			curv = curv->next;
		if (buf[0] == 'f' && (curf = ret_faces(buf)))
			curf = curf->next;
	}
//	printf("%s\n%zu\n", content, ft_countwords(content, ' '));
	return NULL;
}

t_obj 	*parse_obj(char *pth)
{
	int 	fd;

	fd = 0;
	if (ft_strlen(pth) >= 5 && !ft_strstr(ft_strsub(pth,
			ft_strlen(pth) - 4, 4), ".obj"))
		return NULL;
	fd = open(pth, fd, O_RDONLY);
	return (fill_list(fd));
}
