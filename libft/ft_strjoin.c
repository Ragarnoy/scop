/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:56:16 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:18:52 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *join;

	if (!(s1) || !(s2))
		return (0);
	if (!(join = (char*)malloc(sizeof(*join) * (ft_strlen(s1) +
						ft_strlen(s2)) + 1)))
		return (0);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}
