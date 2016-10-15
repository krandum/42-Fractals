/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:01:56 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/10 17:01:58 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void	ft_mat_bzero(float mat[4][4])
{
	ft_bzero(mat[0], sizeof(float) * 4);
	ft_bzero(mat[1], sizeof(float) * 4);
	ft_bzero(mat[2], sizeof(float) * 4);
	ft_bzero(mat[3], sizeof(float) * 4);
}

void	ft_get_id_matrix(float mat[4][4])
{
	ft_bzero(mat[0], sizeof(float) * 4);
	ft_bzero(mat[1], sizeof(float) * 4);
	ft_bzero(mat[2], sizeof(float) * 4);
	ft_bzero(mat[3], sizeof(float) * 4);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void	ft_mat_mult(float m1[4][4], float m2[4][4], float d[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			d[i][j] = m1[i][0] * m2[0][j]
				+ m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j]
				+ m1[i][3] * m2[3][j];
		}
	}
}

void	ft_mat_translate(float mat[4][4], float x, float y, float z)
{
	float	tran_mat[4][4];

	ft_mat_bzero(tran_mat);
	tran_mat[0][0] = 1;
	tran_mat[1][1] = 1;
	tran_mat[2][2] = 1;
	tran_mat[3][3] = 1;
	tran_mat[3][0] = x;
	tran_mat[3][1] = y;
	tran_mat[3][2] = z;
	ft_mat_mult(mat, tran_mat, mat);
}

void	ft_mat_scale(float mat[4][4], float x, float y, float z)
{
	float	scale_mat[4][4];

	ft_mat_bzero(scale_mat);
	scale_mat[0][0] = x;
	scale_mat[1][1] = y;
	scale_mat[2][2] = z;
	scale_mat[3][3] = 1;
	ft_mat_mult(mat, scale_mat, mat);
}
