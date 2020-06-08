/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsv_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:40:44 by tlernoul          #+#    #+#             */
/*   Updated: 2017/12/21 18:54:03 by tlernoul         ###   ########.fr       */
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

static	int		gethexa(t_hsv hsv, float x, float c)
{
	float	m;
	t_rgb	rgb;

	m = hsv.v - c;
	if (hsv.h >= 0 && hsv.h <= 1)
		rgb = getrgb(m, c, x, 0);
	if (hsv.h >= 1 && hsv.h <= 2)
		rgb = getrgb(m, x, c, 0);
	if (hsv.h >= 2 && hsv.h <= 3)
		rgb = getrgb(m, 0, c, x);
	if (hsv.h >= 3 && hsv.h <= 4)
		rgb = getrgb(m, 0, x, c);
	if (hsv.h >= 4 && hsv.h <= 5)
		rgb = getrgb(m, x, 0, c);
	if (hsv.h >= 5 && hsv.h <= 6)
		rgb = getrgb(m, c, 0, x);
	return ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}

int				ft_hsv_to_rgb(t_hsv hsv)
{
	float	x;
	float	c;

	if (hsv.h < 0 || hsv.s > 1.0 || hsv.s < 0 || hsv.v > 1.0 || hsv.v < 0)
		return (-1);
	if (hsv.h > 360)
		hsv.h = fmod(hsv.h, 360);
	hsv.h = hsv.h / 60;
	c = hsv.v * hsv.s;
	x = c * (1.0 - fabs(fmod(hsv.h, 2.0) - 1.0));
	return (gethexa(hsv, x, c));
}
