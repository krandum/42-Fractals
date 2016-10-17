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

void		ft_color_pixel(t_view *v, int x, int y, int iter)
{
	int		i;
	int		color;

	if (iter != v->z_max)
		color = v->colors[iter % v->num_colors];
	else
		color = 0;
	i = (x * 4) + (y * v->size_line);
	v->pixels[i] = color;
	v->pixels[++i] = color >> 8;
	v->pixels[++i] = color >> 16;
}

void		ft_init_color_table(t_view *view, int colors)
{
	int				i;
	float			f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	view->colors = (t_color*)malloc(sizeof(t_color) * colors);
	f = 0;
	i = -1;
	while (++i < colors)
	{
		r = (unsigned char)((-cos(f) + 1.0) * 127.0);
		g = (unsigned char)((sin(f) + 1.0) * 127.0);
		b = (unsigned char)((cos(f) + 1.0) * 127.0);
		view->colors[i] = ((int)r) << 16 | ((int)g) << 8 | b;
		f += 2 * M_PI / colors;
	}
}
