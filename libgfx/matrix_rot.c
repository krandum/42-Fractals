/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 20:47:50 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/10 20:47:50 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

static void	ft_mat_rotx(float mat[4][4], float theta)
{
	ft_mat_bzero(mat);
	mat[0][0] = 1;
	mat[1][1] = cos(theta);
	mat[1][2] = sin(theta);
	mat[2][1] = -sin(theta);
	mat[2][2] = cos(theta);
	mat[3][3] = 1;
}

static void	ft_mat_roty(float mat[4][4], float phi)
{
	ft_mat_bzero(mat);
	mat[0][0] = cos(phi);
	mat[0][2] = -sin(phi);
	mat[1][1] = 1;
	mat[2][0] = sin(phi);
	mat[2][2] = cos(phi);
	mat[3][3] = 1;
}

static void	ft_mat_rotz(float mat[4][4], float psi)
{
	ft_mat_bzero(mat);
	mat[0][0] = cos(psi);
	mat[0][1] = sin(psi);
	mat[1][0] = -sin(psi);
	mat[1][1] = cos(psi);
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void		ft_mat_rotate(float mat[4][4], float theta, float phi, float psi)
{
	float	rotx[4][4];
	float	roty[4][4];
	float	rotz[4][4];
	float	mat1[4][4];
	float	mat2[4][4];

	ft_mat_rotx(rotx, theta);
	ft_mat_roty(roty, phi);
	ft_mat_rotz(rotz, psi);
	ft_mat_mult(mat, roty, mat1);
	ft_mat_mult(mat1, rotx, mat2);
	ft_mat_mult(mat2, rotz, mat);
}

void		ft_vec_mat_mult(t_3dp *src, float mat[4][4], t_3dp *dst)
{
	dst->x = src->x * mat[0][0] + src->y * mat[1][0] + src->z * mat[2][0]
		+ mat[3][0];
	dst->y = src->x * mat[0][1] + src->y * mat[1][1] + src->z * mat[2][1]
		+ mat[3][1];
	dst->z = src->x * mat[0][2] + src->y * mat[1][2] + src->z * mat[2][2]
		+ mat[3][2];
}
