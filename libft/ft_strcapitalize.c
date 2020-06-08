/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 19:41:08 by tlernoul          #+#    #+#             */
/*   Updated: 2016/12/22 18:29:41 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_strlowcase(char *str)
{
	char	*root;

	root = str;
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
			*str += 32;
		str++;
	}
	return (root);
}

char		*ft_strcapitalize(char *str)
{
	int		flag;
	int		i;

	i = 0;
	flag = 1;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		while (str[i] >= 'a' && *str <= 'z')
		{
			if (flag == 1)
			{
				flag = 0;
				if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
					str[i] -= 32;
			}
			i++;
		}
		flag = 1;
		i++;
	}
	return (str);
}
