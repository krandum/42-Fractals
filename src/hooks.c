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

static void		double_scale(int button, int x, int y, t_view *v)
{
	if (button == SCROLL_UP)
	{
		x -= WIN_WIDTH / 2;
		y -= WIN_HEIGHT / 2;
		v->psi *= 1.1;
		v->theta += x / v->psi / 1.5;
		v->phi -= y / v->psi / 1.5;
	}
	else if (button == SCROLL_DOWN)
		v->psi /= 1.2;
	else if (button == BUTTON_L)
		M = (int)(M * 1.1) == M ? M + 1: M * 1.1;
	else if (button == BUTTON_R)
		M = (int)(M / 1.1) == M ? M - 1 : M / 1.2;
}

int				mouse_hook(int button, int x, int y, t_view *v)
{
	if (v->paused && v->fractal == get_mandeljulia)
		double_scale(button, x, y, v);
	else
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
		v->theta = ((float)x / WIN_WIDTH) * .84;
		v->phi = ((float)y / WIN_HEIGHT) * .84;
		reload(v);
	}
	return (0);
}

static void		double_move(int keycode, t_view *v)
{
	if (keycode == KEY_UP)
		v->phi += (W_H / 5.0) / v->scale;
	else if (keycode == KEY_DOWN)
		v->phi -= (W_H / 5.0) / v->scale;
	else if (keycode == KEY_LEFT)
		v->theta -= (W_W / 5.0) / v->scale;
	else if (keycode == KEY_RIGHT)
		v->theta += (W_W / 5.0) / v->scale;
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
	else if (v->paused && v->fractal == get_mandeljulia)
		double_move(keycode, v);
	else if (keycode == KEY_UP)
		v->y_shift += (W_H / 15.0) / v->scale;
	else if (keycode == KEY_DOWN)
		v->y_shift -= (W_H / 15.0) / v->scale;
	else if (keycode == KEY_LEFT)
		v->x_shift -= (W_W / 15.0) / v->scale;
	else if (keycode == KEY_RIGHT)
		v->x_shift += (W_W / 15.0) / v->scale;
	if (keycode == 8)
		v->roll += 4;
	else if (keycode == 7)
		v->roll -= 4;
	reload(v);
	return (0);
}
