/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:02:17 by tlernoul          #+#    #+#             */
/*   Updated: 2016/11/29 18:35:31 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int f;

	i = 0;
	f = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i])
	{
		while (to_find[f] == str[i + f])
		{
			f++;
			if (to_find[f] == '\0')
				return ((char*)str + i);
		}
		f = 0;
		i++;
	}
	return (0);
}
