/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:19:53 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/13 17:04:07 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		ft_lstlen(t_list **len)
{
	int i;

	i = 0;
	while ((*len)->next)
	{
		(*len) = (*len)->next;
		i++;
	}
	return (i);
}

t_list			*ft_lstfold(void (*f), t_list **tab)
{
	int		*i;
	int		p;
	t_list	*elem;

	p = 0;
	if (!(i = (int*)malloc(sizeof(*i) * (ft_lstlen(tab)))))
		elem = NULL;
	if (!(tab) || (!(f)))
		return (NULL);
	while ((*tab)->next)
	{
		i = (*tab)->content;
		p++;
		*tab = (*tab)->next;
	}
	return (elem);
}
