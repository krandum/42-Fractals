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

void		*threaded_artist(void *tmp)
{
	int		y;
	int		x;
	t_split	*s;

	s = (t_split*)tmp;
	y = s->y_start - 1;
	while (++y < s->y_end)
	{
		x = s->x_start - 1;
		while (++x < s->x_end)
			ft_color_pixel(s->view, x, y, s->view->fractal(s->view, x, y));
	}
	return (NULL);
}

void		draw(t_view *view)
{
	t_split	*splits;
	int		i;

	splits = (t_split*)ft_memalloc(sizeof(t_split) * 64);
	i = -1;
	while (++i < 64)
	{
		splits[i].x_start = (WIN_WIDTH / 8) * (i % 8);
		splits[i].x_end = (WIN_WIDTH / 8) * (i % 8 + 1);
		splits[i].y_start = (WIN_HEIGHT / 8) * (i / 8);
		splits[i].y_end = (WIN_HEIGHT / 8) * (i / 8 + 1);
		splits[i].view = view;
		pthread_create(&(splits[i].thread), NULL, threaded_artist,
			(void*)&splits[i]);
	}
	i = -1;
	while (++i < 64)
		pthread_join(splits[i].thread, NULL);
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
	view->z_max = 84;
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
