/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glLoader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:00:13 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/19 12:20:33 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>

int	load_vert(char *pth)
{
	int 	fd;
	int	    vertShader;
	int	    err;
	char	*str;
	char	*ret;

	fd = open(pth, O_RDONLY);
    ret = ft_strnew(0);
	while ((err = get_next_line(fd, &str)) > 0)
	{
		str = ft_strjoin(str, "\n");
		ret = ft_strappend(ret, str, 2);
	}
	if (err == -1)
		shutdown(3); // TODO err case for vert file read failure

	vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, (const char *const *)&ret, NULL);
	glCompileShader(vertShader);
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &err);
	if (err == 0)
		glShaderLogError(vertShader, GL_VERTEX_SHADER);
	return (vertShader);
}


int	load_frag(char *pth)
{
	int 	fd;
	int	    fragShader;
	int	    err;
	char	*str;
	char	*ret;

	fd = open(pth, O_RDONLY);
	ret = ft_strnew(0);
	while ((err = get_next_line(fd, &str)) > 0)
	{
		str = ft_strjoin(str, "\n");
		ret = ft_strappend(ret, str, 2);
	}
	if (err == -1)
		shutdown(3); // TODO err case for frag file read failure

	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, (const char *const*)&ret, NULL);
	glCompileShader(fragShader);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &err);
	if (err == 0)
		glShaderLogError(fragShader, GL_FRAGMENT_SHADER);
	return (fragShader);
}
