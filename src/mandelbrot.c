/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:17:29 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/12 14:17:30 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_mandelbrot(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	t;
	int		i;

	r = ((3.0 * r / W_W - 2.0) / v->scale) + (v->x_shift / W_W);
	im = ((-2.0 * im / W_H + 1.0) / v->scale) + (v->y_shift / W_H);
	x = 0;
	y = 0;
	i = -1;
	while (x * x + y * y <= 4.0 && ++i < v->z_max)
	{
		t = x * x - y * y + r;
		y = 2 * x * y + im;
		x = t;
	}
	return (i);
}

int		get_slayderix(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	xt;
	long double	yt;
	int		i;

	r = ((3.0 * r / W_W - 2.0) / v->scale) + (v->x_shift / W_W);
	im = ((-2.0 * im / W_H + 1.0) / v->scale) + (v->y_shift / W_H);
	x = 0;
	y = 0;
	i = -1;
	while (x * x + y * y <= 4.0 && ++i < v->z_max)
	{
		xt = x * x * x - 3 * x * y * y + r;
		yt = 3 * x * x * y - y * y * y + im;
		if (x == xt && y == yt)
		{
			i = v->z_max;
			break;
		}
		x = xt;
		y = yt;
	}
	return (i);
}

int		get_quadslash(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	xt;
	long double	yt;
	int		i;

	r = ((3.0 * r / W_W - 2.0) / v->scale) + (v->x_shift / W_W);
	im = ((-2.0 * im / W_H + 1.0) / v->scale) + (v->y_shift / W_H);
	x = 0;
	y = 0;
	i = -1;
	while (x * x + y * y <= 4.0 && ++i < v->z_max)
	{
		xt = (x * x * x * x) - (6 * x * x * y * y) + (y * y * y * y) + r;
		yt = (4 * x * x * x * y) - (4 * x * y * y * y) + im;
		if (x == xt && y == yt)
		{
			i = v->z_max;
			break;
		}
		x = xt;
		y = yt;
	}
	return (i);
}

int		get_burning_ship(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	xt;
	long double	yt;
	int		i;

	r = ((4.0 * r / W_W - 2.0) / v->scale) + (v->x_shift / W_W);
	im = ((-4.0 * (1 - im / W_H) + 2.0) / v->scale) - (v->y_shift / W_H);
	x = 0;
	y = 0;
	i = -1;
	while (x * x + y * y <= 4.0 && ++i < v->z_max)
	{
		xt = fabsl(x) * fabsl(x) - fabsl(y) * fabsl(y) + r;
		yt = 2 * fabsl(x) * fabsl(y) + im;
		if (x == xt && y == yt)
		{
			i = v->z_max;
			break;
		}
		x = xt;
		y = yt;
	}
	return (i);
}
