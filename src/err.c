/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:52:51 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/12 17:03:38 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

void		glshader_log_error(int shader, int shader_type)
{
	char	info_log[512];

	glGetShaderInfoLog(shader, 512, NULL, info_log);
	if (shader_type == GL_VERTEX_SHADER)
		ft_putendl("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
	else
		ft_putendl("ERROR::SHADER::FRAG::COMPILATION_FAILED");
	ft_putendl(info_log);
	shutdown(3);
}

void		glprogram_log_error(int program)
{
	char	info_log[512];

	ft_putendl("ERROR::SHADER::PROGRAM::LINKING_FAILED");
	glGetProgramInfoLog(program, 512, NULL, info_log);
	ft_putendl(info_log);
	shutdown(3);
}

void		print_and_terminate(char *str)
{
	ft_putendl(str);
}

int			shutdown(int err)
{
	if (err == 0)
		ft_putendl("Usage : scop [file.obj]");
	if (err == 1)
		print_and_terminate("Uninitialized window.");
	if (err == 2)
		print_and_terminate("Glad was not loaded.");
	if (err == 3)
		print_and_terminate("Shader compilation error.");
	if (err == 4)
		print_and_terminate("Failed to parse/open obj.");
	if (err == 5)
		print_and_terminate("Failed to setup shader.");
	if (err == 6)
		print_and_terminate("Failed to setup vertex.");
	if (err == 7)
		print_and_terminate("Could not load the texture.");
	exit(64);
}
