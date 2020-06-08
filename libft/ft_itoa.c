/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:37:19 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:13:20 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		mult;

	mult = 1;
	i = ft_getndigits(n) - 1;
	if (!(s = ft_strnew(ft_getndigits(n))))
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		mult = -1;
	}
	while ((n >= 10 || n <= -10) && (i != 0))
	{
		s[i] = (n % 10) * mult + '0';
		n = n / 10;
		i--;
	}
	s[i] = n * mult + '0';
	i--;
	return (s);
}
