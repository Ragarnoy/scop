/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:18:05 by tlernoul          #+#    #+#             */
/*   Updated: 2020/07/02 09:57:09 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scop.h"

float	deg_to_rad(float deg)
{
	return (deg / 180 * (float)M_PI);
}

float	rad_to_deg(float deg)
{
	return (deg / (float)M_PI * 180);
}
