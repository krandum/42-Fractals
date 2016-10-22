/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 19:07:35 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/15 19:07:36 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define POW(a, b) ({for(int i=1;i<b;i++)a*=a;a;})

int			get_julia(t_view *v, long double x, long double y)
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
		r = r * r - im * im + v->theta;
		im = 2 * t * im + v->phi;
	}
	return (i);
}

int			get_catherine(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	xt;
	long double	yt;
	int		i;

	x = ((4 * r / WIN_WIDTH - 2) / v->scale) + ((v->x_shift / WIN_WIDTH));
	y = ((-3 * im / WIN_HEIGHT + 1.5) / v->scale) + ((v->y_shift / WIN_HEIGHT));
	i = -1;
	while (++i < v->z_max && x * x + y * y <= 4.0)
	{
		xt = x * x * x - 3 * x * y * y + v->theta;
		yt = 3 * x * x * y - y * y * y + v->theta + v->phi / 2.0;
		x = xt;
		y = yt;
	}
	return (i);
}

int			get_lauren(t_view *v, long double r, long double im)
{
	long double	x;
	long double	y;
	long double	xt;
	long double	yt;
	int		i;

	x = ((4 * r / WIN_WIDTH - 2) / v->scale) + ((v->x_shift / WIN_WIDTH));
	y = ((-3 * im / WIN_HEIGHT + 1.5) / v->scale) + ((v->y_shift / WIN_HEIGHT));
	i = -1;
	while (++i < v->z_max && x * x + y * y <= 4.0)
	{
		xt = (x * x * x * x) - (6 * x * x * y * y) + (y * y * y * y) + v->theta;
		yt = (4 * x * x * x * y) - (4 * x * y * y * y) + v->theta
			+ v->phi / 2.0;
		x = xt;
		y = yt;
	}
	return (i);
}
