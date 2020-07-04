/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:11 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 09:57:09 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		decimal(const char *str, int i, float ret)
{
	unsigned long	dec;

	dec = 1;
	i++;
	while (ft_isdigit(str[i]))
	{
		dec *= 10;
		ret += (float)(str[i++] - '0') / (float)dec;
	}
	return (ret);
}

float		ft_atof(const char *str)
{
	float			ret;
	float			sign;
	int				i;

	i = 0;
	sign = 1;
	ret = 0.0f;
	if (!str)
		return (0.0f);
	while (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			sign = -1.0f;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret *= 10;
		ret += (float)(str[i++] - '0');
	}
	if (str[i] == '.')
		ret = decimal(str, i, ret);
	return (ret * sign);
}
