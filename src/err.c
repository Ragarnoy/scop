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

void	glShaderLogError(int shader, int shaderType)
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

void	glProgramLogError(int program)
{
	char infoLog[512];

	ft_putendl("ERROR::SHADER::PROGRAM::LINKING_FAILED");
	glGetProgramInfoLog(program, 512, NULL, infoLog);
	ft_putendl(infoLog);
	shutdown(3); // TODO err case for shader program compile error
}
void	printAndTerminate(char *str)
{
	ft_putendl(str);
	glfwTerminate();
}

int	shutdown(int err)
{
	if (err == 0)
		ft_putendl("Usage : scop [file.obj]");
	if (err == 1)
		printAndTerminate("Uninitialized window.");
	if (err == 2)
		printAndTerminate("Glad was not loaded.");
	exit(64);
}
