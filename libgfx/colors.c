/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:05:12 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/15 15:05:14 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

static int	get_color(t_view *v, double iter)
{
	double			f;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (iter == 0)
		iter++;
	f = M_PI * 2.0;
	red = (cos(f * iter / v->z_max) + 1.0) * 127;
	green = (sin(f * iter / v->z_max) + 1.0) * 127;
	blue = (-cos(f * iter / v->z_max) + 1.0) * 127;
	return (red << 16 | ((green << 8) & 0xFF00) | (blue & 0xFF));
}

void		ft_color_pixel(t_view *v, int x, int y, int iter)
{
	int		i;
	int		color;

	if (iter != v->z_max)
		color = get_color(v, iter);
	else
		color = 0xFFFFFF;
	i = (x * 4) + (y * v->size_line);
	v->pixels[i] = color;
	v->pixels[++i] = color >> 8;
	v->pixels[++i] = color >> 16;
}
