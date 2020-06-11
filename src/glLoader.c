/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glLoader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:00:13 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/11 16:35:29 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"
#include <fcntl.h>

void	glLogError(int shader, int shaderType)
{
	char infoLog[512];

	glGetShaderInfoLog(shader, 512, NULL, infoLog);
	if (shaderType == GL_VERTEX_SHADER)
		ft_putendl("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
	else
		ft_putendl("ERROR::SHADER::FRAG::COMPILATION_FAILED");
	ft_putendl(infoLog);
	shutdown(3); // TODO err case for shader compile error
}

int	loadVert(char *pth)
{
	int 	fd;
	int	vertShader;
	int	err;
	char	*str;
	char	*ret;

	fd = open(pth, O_RDONLY);
	while ((err = get_next_line(fd, &str)) > 0)
	{
		ret = ft_strappend(ret, str, 2);
	}
	if (err == -1)
		shutdown(3); // TODO err case for vert file read failure
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, (const char *const*)ret, NULL);
	glCompileShader(vertShader);
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &err);
	if (err == 0)
		glLogError(vertShader, GL_VERTEX_SHADER);
	return (vertShader);
}


int	loadFrag(char *pth)
{
	int 	fd;
	int	fragShader;
	int	err;
	char	*str;
	char	*ret;

	fd = open(pth, O_RDONLY);
	while ((err = get_next_line(fd, &str)) > 0)
	{
		ret = ft_strappend(ret, str, 2);
	}
	if (err == -1)
		shutdown(3); // TODO err case for frag file read failure
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, (const char *const*)ret, NULL);
	glCompileShader(fragShader);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &err);
	if (err == 0)
		glLogError(fragShader, GL_FRAGMENT_SHADER);
	return (fragShader);
}
