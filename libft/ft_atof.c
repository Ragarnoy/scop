/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:56:11 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/22 16:40:21 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		decimal(const char *str, int i, double ret)
{
	unsigned long 	dec;

	dec = 1;
	i++;
	while (ft_isdigit(str[i]))
	{
		dec *= 10;
		ret += (double)(str[i++] - '0') / (double)dec;
	}
	return (ret);
}

double		ft_atof(const char *str)
{
	double			ret;
	double			sign;
	int				i;

	i = 0;
	sign = 1;
	ret = 0.0f;
	if (!str)
		return (0.0f);
	while (!ft_isdigit(str[i]))
	{
<<<<<<< HEAD
        if (str[i] == '-')
            sign = -1.0f;
        i++;
    }
=======
		if (str[i] == '-')
			sign = -1.0f;
		i++;
	}
>>>>>>> feature/makefile
	while (ft_isdigit(str[i]))
	{
		ret *= 10;
		ret += (double)(str[i++] - '0');
	}
	if (str[i] == '.')
		ret = decimal(str, i, ret);
	return (ret * sign);
}
