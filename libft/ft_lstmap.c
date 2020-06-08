/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:35:54 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:13:41 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *begin;
	t_list *tmp;

	nlst = NULL;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!nlst)
		{
			if (!(nlst = ft_lstnew(tmp->content, tmp->content_size)))
				return (0);
			begin = nlst;
		}
		else
		{
			if (!(nlst->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (0);
			nlst = nlst->next;
		}
		lst = lst->next;
	}
	return (begin);
}
