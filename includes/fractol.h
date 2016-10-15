/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:09:49 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/12 14:09:51 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "libgfx.h"

# define KEY_ESC 53

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2

# define BUTTON_L 1
# define BUTTON_R 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

void		create(t_view *view);
void		reload(t_view *view);
int			mouse_hook(int button, int x, int y, t_view *v);
int			key_hook(int keycode, t_view *view);
int			get_mandelbrot(t_view *v, double r, double im);

#endif
