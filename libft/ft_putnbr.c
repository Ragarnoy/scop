/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 11:41:27 by tlernoul          #+#    #+#             */
/*   Updated: 2016/12/02 17:23:36 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else if (nb <= -10)
	{
		ft_putnbr(nb / -10);
		ft_putchar((nb % -10) * -1 + '0');
	}
	else
	{
		if (nb > 0)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb * -1 + '0');
	}
}
