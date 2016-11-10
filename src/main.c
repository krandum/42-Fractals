/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:45:09 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/12 13:45:10 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_get_function(t_view *view, char *str)
{
	if (ft_strequ("M", str) || ft_strequ("Mandelbrot", str))
		view->fractal = get_mandelbrot;
	else if (ft_strequ("S", str) || ft_strequ("Slayderix", str))
		view->fractal = get_slayderix;
	else if (ft_strequ("Q", str) || ft_strequ("Quadslash", str))
		view->fractal = get_quadslash;
	else if (ft_strequ("J", str) || ft_strequ("Julia", str))
	{
		view->fractal = get_julia;
		view->theta = -0.7;
		view->phi = 0.27015;
	}
	else if (ft_strequ("C", str) || ft_strequ("Catherine", str))
		view->fractal = get_catherine;
	else if (ft_strequ("L", str) || ft_strequ("Lauren", str))
		view->fractal = get_lauren;
	else if (ft_strequ("B", str) || ft_strequ("Burning Ship", str))
		view->fractal = get_burning_ship;
	return (view->fractal == 0 ? 0 : 1);
}

#include <stdio.h>

int			main(int argc, char **argv)
{
	t_view	*view;

	view = (t_view*)ft_memalloc(sizeof(t_view));
	if (argc != 2 || !set_get_function(view, argv[1]))
	{
		ft_putendl("Usage: ./fractol [M/S/Q/J/L/B]");
		ft_putstr("\tor [Mandelbrot / Slayderix / Quadslash");
		ft_putendl(" / Julia / Catherine / Lauren / Burning Ship]");
		return (0);
	}
	create(view);
	reload(view);
	mlx_loop(view->id);
}

