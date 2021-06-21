/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:56:35 by rroland           #+#    #+#             */
/*   Updated: 2021/04/14 14:07:02 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move(t_cub *cub, int kx, int ky)
{
	double	newx;
	double	newy;

	newx = (cub->x + kx * 0.25 * cos(cub->angle));
	newy = (cub->y + ky * 0.25 * sin(cub->angle));
	if (cub->my_map[(int)(cub->y)][(int)(newx)] != '1')
	{
		cub->x += kx * 0.05 * cos(cub->angle);
	}
	if (cub->my_map[(int)(newy)][(int)(cub->x)] != '1')
	{
		cub->y += ky * 0.05 * sin(cub->angle);
	}
}

void	move_side(t_cub *cub, int kx, int ky)
{
	double	newx;
	double	newy;

	newx = (cub->x + kx * 0.25 * sin(cub->angle));
	newy = (cub->y + ky * 0.25 * cos(cub->angle));
	if (cub->my_map[(int)(cub->y)][(int)(newx)] != '1')
	{
		cub->x += kx * 0.05 * sin(cub->angle);
	}
	if (cub->my_map[(int)(newy)][(int)(cub->x)] != '1')
	{
		cub->y += ky * 0.05 * cos(cub->angle);
	}
}

void	key_run(t_cub *cub)
{
	if (cub->run.w == 1)
		move(cub, 1, 1);
	if (cub->run.s == 1)
		move(cub, -1, -1);
	if (cub->run.a == 1)
		move_side(cub, 1, -1);
	if (cub->run.d == 1)
		move_side(cub, -1, 1);
	if (cub->run.left == 1)
	{
		cub->angle -= 0.05;
		while (cub->angle < 0)
			cub->angle += 2 * M_PI;
	}
	if (cub->run.right == 1)
	{
		cub->angle += 0.05;
		while (cub->angle > 2 * M_PI)
			cub->angle -= 2 * M_PI;
	}
}
