/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:48:33 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/07 20:02:39 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_retwords(const char *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	ret = (char**)ft_memalloc(sizeof(char*) * ft_countwords(s, c));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			ret[j++] = ft_strsub(s, i, ft_strlenc(s + i, c));
		while (s[i] && s[i] != c)
			i++;
	}
	return (ret);
}
