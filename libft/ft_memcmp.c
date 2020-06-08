/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:54:05 by tlernoul          #+#    #+#             */
/*   Updated: 2016/12/01 17:55:02 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
