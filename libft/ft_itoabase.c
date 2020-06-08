/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:38:41 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/14 02:42:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fillarray(char str[][16])
{
	int i;

	i = -1;
	while (++i < 9)
		*str[i] = i;
	i = -1;
	while (++i < 5)
		*str[i] = 97 + i;
}

char	*ft_itoabase(int n, int base)
{
	char	str[16];
	char	*s;
	int		i;
	int		mult;

	mult = 1;
	fillarray(&str);
	i = ft_getndigits(n) - 1;
	if (!(s = ft_strnew(ft_getndigits(n))))
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		mult = -1;
	}
	while ((n >= base || n <= -base) && (i != 0))
	{
		s[i] = str[(n % base) * mult];
		n = n / base;
		i--;
	}
	s[i] = str[n * mult];
	i--;
	return (s);
}
