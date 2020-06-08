/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsl_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:40:44 by tlernoul          #+#    #+#             */
/*   Updated: 2018/01/09 21:40:14 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_rgb	getrgb(float m, float r, float g, float b)
{
	t_rgb	rgb;

	rgb.r = roundf((r + m) * 255);
	rgb.g = roundf((g + m) * 255);
	rgb.b = roundf((b + m) * 255);
	return (rgb);
}

static	int		gethexa(t_hsl hsl, float x, float c)
{
	float	m;
	t_rgb	rgb;

	m = hsl.l - c / 2;
	if (hsl.h >= 0 && hsl.h <= 1)
		rgb = getrgb(m, c, x, 0);
	if (hsl.h >= 1 && hsl.h <= 2)
		rgb = getrgb(m, x, c, 0);
	if (hsl.h >= 2 && hsl.h <= 3)
		rgb = getrgb(m, 0, c, x);
	if (hsl.h >= 3 && hsl.h <= 4)
		rgb = getrgb(m, 0, x, c);
	if (hsl.h >= 4 && hsl.h <= 5)
		rgb = getrgb(m, x, 0, c);
	if (hsl.h >= 5 && hsl.h <= 6)
		rgb = getrgb(m, c, 0, x);
	return ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}

int				ft_hsl_to_rgb(t_hsl hsl)
{
	float	x;
	float	c;

	if (hsl.l > 1.0)
		hsl.l = 1.0;
	else if (hsl.l < 0)
		hsl.l = 0;
	if (hsl.s > 1.0)
		hsl.s = 1.0;
	else if (hsl.s < 0)
		hsl.s = 0;
	if (hsl.h < 0)
		hsl.h = fabs(hsl.h);
	if (hsl.h > 360)
		hsl.h = fmod(hsl.h, 360);
	hsl.h = hsl.h / 60;
	c = (1 - fabs((hsl.l * 2) - 1)) * hsl.s;
	x = c * (1.0 - fabs(fmod(hsl.h, 2.0) - 1.0));
	return (gethexa(hsl, x, c));
}
