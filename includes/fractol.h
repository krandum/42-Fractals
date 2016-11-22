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

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define BUTTON_L 1
# define BUTTON_R 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define KEY_PAUSE 49

void		create(t_view *view);
void		reload(t_view *view);
int			mouse_hook(int button, int x, int y, t_view *v);
int			key_hook(int keycode, t_view *view);
int			mouse_move(int x, int y, t_view *v);
int			get_mandelbrot(t_view *v, long double r, long double im);
int			get_slayderix(t_view *v, long double r, long double im);
int			get_quadslash(t_view *v, long double r, long double im);
int			get_julia(t_view *v, long double x, long double y);
int			get_catherine(t_view *v, long double x, long double y);
int			get_lauren(t_view *v, long double r, long double im);
int			get_burning_ship(t_view *v, long double r, long double im);
int			get_carpet(t_view *v, long double x, long double y);
int			get_mandeljulia(t_view *v, long double r, long double im);
int			get_burning_julia(t_view *v, long double x, long double y);
int			get_expobrot(t_view *v, long double r, long double im);
int			get_burning_lauren(t_view *v, long double x, long double y);

#endif
