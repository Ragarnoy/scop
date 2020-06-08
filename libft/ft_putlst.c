/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:43:49 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:16:16 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *elem)
{
	while (elem)
	{
		ft_putstr("Content = ");
		ft_putstr(elem->content);
		ft_putchar('\n');
		ft_putstr("Size = ");
		ft_putnbr(elem->content_size);
		ft_putchar('\n');
		elem = elem->next;
	}
}
