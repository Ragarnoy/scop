/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 19:50:16 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/16 17:16:35 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *app, char *end, int l)
{
	char *str;

	if (app && end)
		str = ft_strjoin(app, end);
	else if (app)
		str = ft_strdup(app);
	else if (end)
		str = ft_strdup(end);
	else
		return (NULL);
	if (l == 1 || l == 3)
		ft_strdel(&app);
	if (l == 2 || l == 3)
		ft_strdel(&end);
	return (str);
}
