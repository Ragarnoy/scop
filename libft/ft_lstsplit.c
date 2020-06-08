/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:10:22 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:14:22 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ret_w(const char *s, char c, size_t start)
{
	size_t len;
	size_t pos;

	pos = start;
	len = 0;
	while (s[pos] && s[pos] != c)
	{
		len++;
		pos++;
	}
	return (ft_strsub(s, start, len));
}

static void		ft_send(t_list **lst, const char *s, char c, size_t i)
{
	(*lst)->next = ft_lstnew(ret_w(s, c, i), ft_strlen(ret_w(s, c, i)));
	*lst = (*lst)->next;
}

t_list			*ft_lstsplit(const char *s, char c)
{
	size_t	i;
	t_list	*elem;
	t_list	*begin;

	elem = NULL;
	if (((i = 0) == 0) && !s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!elem)
			{
				elem = ft_lstnew(ret_w(s, c, i), ft_strlen(ret_w(s, c, i)));
				begin = elem;
			}
			else
				ft_send(&elem, s, c, i);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (begin);
}
