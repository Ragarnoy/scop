/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 11:41:27 by tlernoul          #+#    #+#             */
/*   Updated: 2016/12/02 17:38:17 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else if (nb <= -10)
	{
		ft_putnbr_fd(nb / -10, fd);
		ft_putchar_fd((nb % -10) * -1 + '0', fd);
	}
	else
	{
		if (nb > 0)
			ft_putchar_fd(nb + '0', fd);
		else
			ft_putchar_fd(nb * -1 + '0', fd);
	}
}
