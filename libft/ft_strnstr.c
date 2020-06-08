/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:14:11 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:20:08 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t f;

	i = 0;
	f = 0;
	if (len == 0)
		return (0);
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (i == len)
			return (0);
		while (to_find[f] == str[i + f])
		{
			if (i + f == len)
				return (0);
			f++;
			if (to_find[f] == '\0')
				return ((char*)str + i);
		}
		f = 0;
		i++;
	}
	return (0);
}
