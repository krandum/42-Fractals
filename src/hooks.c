/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:15:43 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/15 16:15:45 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define M v->z_max

static void		scale(int button, int x, int y, t_view *v)
{
	if (button == SCROLL_UP)
	{
		x -= WIN_WIDTH / 2;
		y -= WIN_HEIGHT / 2;
		v->scale *= 1.1;
		v->x_shift += x / v->scale / 1.5;
		v->y_shift -= y / v->scale / 1.5;
	}
	else if (button == SCROLL_DOWN)
		v->scale /= 1.2;
	else if (button == BUTTON_L)
		M = (int)(M * 1.1) == M ? M + 1: M * 1.1;
	else if (button == BUTTON_R)
		M = (int)(M / 1.1) == M ? M - 1 : M / 1.2;
}

int				mouse_hook(int button, int x, int y, t_view *v)
{
	scale(button, x, y, v);
	reload(v);
	return (0);
}

int				mouse_move(int x, int y, t_view *v)
{
	if (!v->paused)
	{
		x -= WIN_WIDTH / 2;
		y -= WIN_HEIGHT / 2;
		v->theta = ((float)x / WIN_WIDTH) * 1.5;
		v->phi = ((float)y / WIN_HEIGHT) * 1.5;
		reload(v);
	}
	return (0);
}

int				key_hook(int keycode, t_view *v)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(v->id, v->win);
		exit(0);
	}
	else if (keycode == KEY_PAUSE)
		v->paused = !v->paused;
	else if (keycode == KEY_UP)
		v->y_shift += 15.0;
	else if (keycode == KEY_DOWN)
		v->y_shift -= 15.0;
	else if (keycode == KEY_LEFT)
		v->x_shift -= 15.0;
	else if (keycode == KEY_RIGHT)
		v->x_shift += 15.0;
	reload(v);
	return (0);
}
