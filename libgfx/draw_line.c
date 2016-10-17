/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:18:48 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/10 21:18:49 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void		ft_draw_point(t_view *view, int x, int y, float z)
{
	float			which;
	unsigned int	color;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		which = ((z - view->z_min) / (view->z_max - view->z_min)) * (view->num_colors);
		color = view->colors[abs((int)which - 1)];
		mlx_pixel_put(view->id, view->win, x, y, color);
	}
}

/*
**	Returns one if it had to flip x and y. We do this to only have one drawline
**	function.
*/

static int	swap_vars(t_3dp *p0, t_3dp *p1)
{
	float	temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

void		ft_drawline_3d(t_view *view, t_3dp p0, t_3dp p1)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&p0, &p1);
	delta[0] = p1.x - p0.x;
	delta[1] = p1.y - p0.y;
	delta[2] = p1.z - p0.z;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		ft_draw_point(view, dir ? p0.y : p0.x, dir ? p0.x : p0.y, p0.z);
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		p0.z -= (p0.z > p1.z) ? -(delta[2] / delta[0]) : delta[2] / delta[0];
		p0.x += (p0.x > p1.x) ? -1.0 : 1.0;
	}
}
