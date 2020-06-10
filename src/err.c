/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:52:51 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/10 17:47:42 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.h"

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
