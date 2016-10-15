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

static void		scale(int button, int x, int y, t_view *v)
{
	if (button == BUTTON_L || button == SCROLL_UP)
	{
		x -= WIN_WIDTH / 2;
		y -= WIN_HEIGHT / 2;
		v->scale *= 1.1;
		v->x_shift += x / v->scale / 2.27;
		v->y_shift += y / v->scale / 2.27;
	}
	else if (button == BUTTON_R || button == SCROLL_DOWN)
		v->scale /= 1.2;
}

int				mouse_hook(int button, int x, int y, t_view *v)
{
	scale(button, x, y, v);
	reload(v);
	return (0);
}

int				key_hook(int keycode, t_view *view)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(view->id, view->win);
		exit(0);
	}
	return (0);
}
