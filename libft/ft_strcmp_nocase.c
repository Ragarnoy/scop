/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_nocase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 23:49:03 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/07 00:06:50 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_nocase(const char *s1, const char *s2)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i])
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i]
				&& ft_tolower((int)s1[i]) != ft_tolower((int)s2[i]))
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	}
	return (((unsigned char*)s1)[i] - ((unsigned char *)s2)[i]);
}
