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
#include <stdio.h> // nono
#include <stdlib.h> // nono


t_faces	*ret_faces(char *str)
{
    int		        i;
    uint8_t         spaces;
    unsigned int    tmp[4];
    int             size;

    size = ft_strlen(str);
    ft_bzero(tmp, sizeof(unsigned int) * 4);
    spaces = 0;
    i = -1;
    while (++i < size && str[i] != 'v')
    {
        if (ft_isdigit(str[i]))
        {
            tmp[spaces] = ft_atoi(str + i);
            spaces++;
//            printf("f READING '%s' AT %c -> %d\n", str + i, str[i], atoi(str + i));
            while (i < size && !ft_isblank(str[i]))
                i++;
        }
    }
//    printf("========================================\nf RESULT = %d  %d  %d  %d\n\n", tmp[0], tmp[1], tmp[2], tmp[3]);
    return (lst_facenew(tmp[0], tmp[1], tmp[2], tmp[3]));
}

t_vert 	*ret_verts(char *str)
{
	int		i;
	uint8_t spaces;
	float 	tmp[3];
    int     size;

    size = ft_strlen(str);
	ft_bzero(tmp, sizeof(float) * 3);
	spaces = 0;
	i = -1;
	while (++i < size && str[i] != 'f')
	{
		if (str[i] == '-' || ft_isdigit(str[i]))
		{
			tmp[spaces] = ft_atof(str + i);
			spaces++;
//			printf("v READING '%s' AT %c -> %f\n", str + i, str[i], atof(str + i));
//			if (ft_atof(str + i) != atof(str + i))
//			    printf("!!!!INCORRECT ATOF!\nExpected:%lf\n     Got:%lf\n", atof(str + i), ft_atof(str + i));
			while (i < size && !ft_isblank(str[i]))
				i++;
		}
	}
	printf("========================================\nv RESULT = %f  %f  %f\n\n", tmp[0], tmp[1], tmp[2]);
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
		if (!ret->verts && buf[0] == 'v' && (curv = ret_verts(buf)))
			ret->verts = curv;
		if (!ret->faces && buf[0] == 'f' && (curf = ret_faces(buf)))
			ret->faces = curf;
		if (buf[0] == 'v' && curv == ret->verts && (curv = ret->verts->next))
            curv = curv->next;
		else if (buf[0] == 'v' && (curv = ret_verts(buf)))
			curv = curv->next;
        if (buf[0] == 'f' && curf == ret->faces)
            curf = curf->next;
		else if (buf[0] == 'f' && (curf = ret_faces(buf)))
			curf = curf->next;
	}
	curv = ret->verts;
	while (curv)
    {
	    if (!curv->next)
	        ft_putendl("null next");
	    printf("LL %f %f %f\n", curv->v.x, curv->v.y, curv->v.z);
	    curv = curv->next;
    }
//	printf("%s\n%zu\n", content, ft_countwords(content, ' '));
	return (ret);
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
