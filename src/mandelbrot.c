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

int		get_mandelbrot(t_view *v, double r, double im)
{
	double	z_real;
	double	z_imag;
	double	z_r2;
	double	z_i2;
	int		i;

	r = ((3.0 * r / WIN_WIDTH - 2.0) / v->scale)
		+ (v->x_shift / WIN_WIDTH);
	im = ((2.0 * im / WIN_HEIGHT - 1.0) / v->scale)
		+ (v->y_shift / WIN_HEIGHT);
	z_real = 0.0;
	z_imag = 0.0;
	z_r2 = 0.0;
	z_i2 = 0.0;
	i = -1;
	while (z_r2 + z_i2 <= 4.0 && ++i < v->z_max)
	{
		z_imag = (z_real + z_imag) * (z_real + z_imag) - z_r2 - z_i2 + im;
		z_real = z_r2 - z_i2 + r;
		z_r2 = z_real * z_real;
		z_i2 = z_imag * z_imag;
	}
	return (i);
}
