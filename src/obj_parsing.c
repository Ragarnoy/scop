/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:26:42 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/18 19:51:53 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>
#include <stdio.h>

int 	ret_vertices(char *str, int i, float **verts)
{
	int j;

	j = 0;
	while (str[i] && str[i] != 'f')
	{
		ft_putchar(str[i]);
		if (str[i] == '-' || ft_isdigit(str[i]))
		{
			*verts[j] = ft_atof(str + i);
			printf("%lf ", *verts[j]);
			j++;
			while (str[i] != ' ')
				i++;
		}
		i++;
	}

	return (i);
}

t_obj 	*tokenize(char *str)
{
	int		i;
	float	*verts;

	i = 0;
	verts = ft_memalloc(sizeof(float) * ft_countwords(str, 'v'));
	while (str[i] != '\0')
	{
		if (str[i] == 'v' && (ft_isdigit(str[i + 2]) || str[i + 2] == '-'))
			i = ret_vertices(str, i, &verts);
		i++;
	}
	return (NULL);
}

t_obj 	*parse_obj(char *pth)
{
	int 	fd;
	char 	*buf;
	char 	*content;

	fd = 0;
	if (ft_strlen(pth) >= 5 && !ft_strstr(ft_strsub(pth,
			ft_strlen(pth) - 4, 4), ".obj"))
		return NULL;
	fd = open(pth, fd, O_RDONLY);
	while (get_next_line(fd, &buf) > 0)
	{
		//TODO Might leak
		buf = ft_strjoin(buf, " ");
		content = ft_strappend(content, buf, 2);
	}
	tokenize(content);
//	printf("%s\n%zu\n", content, ft_countwords(content, ' '));
	return (NULL);
}
