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
	int		fd;
	int		vert_shader;
	int		err;
	char	*str;
	char	*ret;

	fd = open(pth, O_RDONLY);
	ret = ft_strnew(0);
	while ((err = get_next_line(fd, &str)) > 0)
		ret = ft_strappend(ret, ft_strappend(str, "\n", 1), 3);
	free(str);
	if (err == -1)
		shutdown(3);
	vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_shader, 1, (const char *const *)&ret, NULL);
	free(ret);
	glCompileShader(vert_shader);
	glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &err);
	if (err == 0)
		glshader_log_error(vert_shader, GL_VERTEX_SHADER);
	return (vert_shader);
}

int	load_frag(char *pth)
{
	int		fd;
	int		frag_shader;
	int		err;
	char	*str;
	char	*ret;

	fd = open(pth, O_RDONLY);
	ret = ft_strnew(0);
	while ((err = get_next_line(fd, &str)) > 0)
		ret = ft_strappend(ret, ft_strappend(str, "\n", 1), 3);
	free(str);
	if (err == -1)
		shutdown(3);
	frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_shader, 1, (const char *const*)&ret, NULL);
	free(ret);
	glCompileShader(frag_shader);
	glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &err);
	if (err == 0)
		glshader_log_error(frag_shader, GL_FRAGMENT_SHADER);
	return (frag_shader);
}
