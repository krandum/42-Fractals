/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.21.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3016/11/12 00:35:04 by palatorr          #+#    #+#             */
/*   Updated: 2016/11/12 00:35:06 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_carpet(t_view *v, long double x, long double y)
{
	int			i;
	long double	xscale;
	long double	yscale;
	long double	xoff;
	long double	yoff;

	i = 1;
	x = fabsl(x) / v->scale;
	y = fabsl(y) / v->scale;
	xscale = W_W / 3;
	yscale = W_H / 3;
	xoff = 0;
	yoff = 0;
	while (i < v->z_max / 10)
	{
		if (x >= xscale + xoff && x <= xscale * 2 + xoff &&
			y >= yscale + yoff && y <= yscale * 2 + yoff)
			return (i * 7);
		xoff += ((int)(x / xscale) % 3) * xscale;
		yoff += ((int)(y / yscale) % 3) * yscale;
		i++;
		xscale = W_W / (pow(3, i));
		yscale = W_H / (pow(3, i));
	}
	return (i * 7);
}

int		get_mandeljulia(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	t;
	int			i;

	t = (int)(r / (W_W / 36)) * (W_W / 36);
	x = ((2.0 * ((r - t) / (((int)(r / (W_W / 36)) * (W_W / 36) + (W_W / 36))
		- t)) - 1.0) / v->psi) + (v->theta / W_W);
	r = ((4.0 * t / W_W - 2) / v->scale) + (v->x_shift / W_W);
	t = (int)(im / (W_H / 36)) * (W_H / 36);
	y = ((2.0 * ((im - t) / (((int)(im / (W_H / 36)) * (W_H / 36) + (W_H / 36))
		- t)) - 1.0) / v->psi) - (v->phi / W_H);
	im = ((4.0 * t / W_H - 2) / v->scale) - (v->y_shift / W_H);
	i = -1;
	while (++i < v->z_max && x * x + y * y <= 4.0)
	{
		t = x * x - y * y + r;
		y = 2 * x * y + im;
		x = t;
	}
	return (i);
}

int		get_burning_julia(t_view *v, long double x, long double y)
{
	long double	r;
	long double	im;
	long double	t;
	int		i;

	r = ((4 * x / WIN_WIDTH - 2) / v->scale) + ((v->x_shift / WIN_WIDTH));
	im = ((-3 * y / WIN_HEIGHT + 1.5) / v->scale) + ((v->y_shift / WIN_HEIGHT));
	i = -1;
	while (++i < v->z_max && r * r + im * im <= 4.0)
	{
		t = ABS(r);
		r = r * r - im * im + v->theta;
		im = 2 * t * ABS(im) + v->phi;
	}
	return (i);
}

int		get_burning_lauren(t_view *v, long double x, long double y)
{
	long double	r;
	long double	im;
	long double	t;
	int		i;

	r = ((4 * x / WIN_WIDTH - 2) / v->scale) + ((v->x_shift / WIN_WIDTH));
	im = ((-3 * y / WIN_HEIGHT + 1.5) / v->scale) + ((v->y_shift / WIN_HEIGHT));
	i = -1;
	while (++i < v->z_max && r * r + im * im <= 4.0)
	{
		t = r;
		r = ABS(r * r - im * im) + v->theta;
		im = 2 * t * im + v->phi;
	}
	return (i);
}

int		get_expobrot(t_view *v, long double r, long double im)
{
	long double	t;
	int		i;

	r = ((3.0 * r / W_W - 2.0) / v->scale) + (v->x_shift / W_W);
	im = ((-2.0 * im / W_H + 1.0) / v->scale) + (v->y_shift / W_H);
	i = -1;
	while (++i < v->z_max && r * r + im * im <= 200.0)
	{
		t = exp(r) * cos(im) + v->theta;
		im = exp(r) * sin(im) + v->phi;
		r = t;
	}
	return (i);
}
