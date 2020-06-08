/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/08 18:45:10 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**multi_fd(int fd)
{
	static char		***mfd = NULL;

	if (!mfd)
		mfd = (char ***)ft_memalloc(sizeof(char **) * MAX_FD);
	if (mfd)
	{
		if (!mfd[fd])
		{
			mfd[fd] = (char **)ft_memalloc(sizeof(char *));
			*(mfd[fd]) = ft_strnew(BUFF_SIZE);
		}
		if (mfd[fd])
			return (mfd[fd]);
	}
	return (NULL);
}

static int	checkerror(int end, char **s)
{
	if (end == -1)
	{
		ft_strdel(s);
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	int			end;
	char		**save;

	end = -2;
	if (fd > MAX_FD || fd < 0 || BUFF_SIZE <= 0 || line == NULL ||
		!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	save = multi_fd(fd);
	while (!(ft_strchr(*save, '\n')) && ((end = read(fd, buf, BUFF_SIZE)) > 0))
	{
		*save = ft_strappend(*save, buf, 1);
		ft_strclr(buf);
	}
	if (!(checkerror(end, &buf)))
		return (-1);
	*line = (ft_strchr(*save, '\n') ?
		ft_strsub(*save, 0, ft_strchr(*save, '\n') - *save) : ft_strdup(*save));
	if (ft_strchr(*save, '\n'))
		ft_strcpy(*save, ft_strchr(*save, '\n') + 1);
	if (!end)
		ft_strclr(*save);
	ft_strdel(&buf);
	return (end || **line);
}
