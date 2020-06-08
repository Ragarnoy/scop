/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:34:28 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/20 16:03:57 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *s, char c)
{
	size_t i;
	size_t chk;

	i = -1;
	while (s[++i] != c && s)
		if (s[i] == c)
			chk = 1;
	if (!chk)
		return (0);
	return (i);
}
