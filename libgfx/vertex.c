/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:29:19 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/10 21:29:20 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

t_2dp		*ft_get_2d_point(float x, float y)
{
	t_2dp	*out;

	out = (t_2dp*)malloc(sizeof(t_2dp));
	out->x = x;
	out->y = y;
	return (out);
}

t_3dp		*ft_get_3d_point(float x, float y, float z)
{
	t_3dp	*out;

	out = (t_3dp*)malloc(sizeof(t_3dp));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vertex	*ft_get_vertex(float x, float y, float z)
{
	t_vertex	*out;

	out = (t_vertex*)malloc(sizeof(t_vertex));
	out->local = ft_get_3d_point(x, y, z);
	out->world = ft_get_3d_point(0, 0, 0);
	out->aligned = ft_get_3d_point(0, 0, 0);
	out->projected = ft_get_3d_point(0, 0, 0);
	return (out);
}
