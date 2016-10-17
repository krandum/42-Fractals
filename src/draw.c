/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 15:19:27 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/15 15:19:29 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_view *view)
{
	int		y;
	int		x;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_color_pixel(view, x, y, view->fractal(view, x, y));
	}
}

void		reload(t_view *view)
{
	view->img = mlx_new_image(view->id, WIN_WIDTH + 100, WIN_HEIGHT + 100);
	view->pixels = mlx_get_data_addr(view->img, &(view->bits_per_pixel),
		&(view->size_line), &(view->endian));
	draw(view);
	mlx_put_image_to_window(view->id, view->win, view->img, 0, 0);
	mlx_destroy_image(view->id, view->img);
}

int			expose(t_view *v)
{
	reload(v);
	return (0);
}

void		create(t_view *view)
{
	view->scale = 1.0;
	view->z_max = 42;
	view->x_shift = 0.0;
	view->y_shift = 0.0;
	view->num_colors = 84;
	view->id = mlx_init();
	view->win = mlx_new_window(view->id, WIN_WIDTH, WIN_HEIGHT, "42-Fract'ol");
	view->paused = 0;

	ft_init_color_table(view, view->num_colors);
	mlx_expose_hook(view->win, expose, view);
	mlx_hook(view->win, 2, 3, key_hook, view);
	mlx_hook(view->win, 4, 5, mouse_hook, view);
	if (view->fractal == get_julia || view->fractal == get_catherine
		|| view->fractal == get_lauren)
		mlx_hook(view->win, 6, (1L << 6), mouse_move, view);
}
