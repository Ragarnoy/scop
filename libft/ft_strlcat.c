/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:46:17 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:18:56 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t s;

	s = ft_strlen(dest);
	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	if (s > n)
		return (n + ft_strlen(src));
	while (i < (n - 1) && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (s + ft_strlen(src));
}
