/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_of_the_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 01:06:34 by rroland           #+#    #+#             */
/*   Updated: 2021/04/14 01:12:48 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	side_of_the_world_4(t_cub *cub, double xx, double yy)
{
	int	num_texture;

	num_texture = 0;
	if (ceil(xx) - xx > yy - floor(yy))
	{
		cub->hitxy = ceil(cub->x_end) - cub->x_end;
		num_texture = 1;
	}
	else
	{
		cub->hitxy = ceil(cub->y_end) - cub->y_end;
		num_texture = 4;
	}
	return (num_texture);
}

static int	side_of_the_world_3(t_cub *cub, double xx, double yy)
{
	int	num_texture;

	num_texture = 0;
	if (xx - floor(xx) > yy - floor(yy))
	{
		cub->hitxy = ceil(cub->x_end) - cub->x_end;
		num_texture = 1;
	}
	else
	{
		cub->hitxy = ceil(cub->y_end) - cub->y_end;
		num_texture = 3;
	}
	return (num_texture);
}

static int	side_of_the_world_2(t_cub *cub, double xx, double yy)
{
	int	num_texture;

	num_texture = 0;
	if (xx - floor(xx) > ceil(yy) - yy)
	{
		cub->hitxy = ceil(cub->x_end) - cub->x_end;
		num_texture = 2;
	}
	else
	{
		cub->hitxy = ceil(cub->y_end) - cub->y_end;
		num_texture = 3;
	}
	return (num_texture);
}

static int	side_of_the_world_1(t_cub *cub, double xx, double yy)
{
	int	num_texture;

	num_texture = 0;
	if (ceil(xx) - xx > ceil(yy) - yy)
	{
		cub->hitxy = ceil(cub->x_end) - cub->x_end;
		num_texture = 2;
	}
	else
	{
		cub->hitxy = ceil(cub->y_end) - cub->y_end;
		num_texture = 4;
	}
	return (num_texture);
}

t_textures	side_of_the_world(t_cub *cub, double dir, double c)
{
	double	xx;
	double	yy;
	int		num_texture;

	xx = cub->x + ((c - 0.000001) * cos(dir));
	yy = cub->y + ((c - 0.000001) * sin(dir));
	num_texture = 0;
	if (dir > 0 && dir <= M_PI / 2)
		num_texture = side_of_the_world_1(cub, xx, yy);
	else if (dir > M_PI / 2 && dir <= M_PI)
		num_texture = side_of_the_world_2(cub, xx, yy);
	else if (dir > M_PI && dir <= 3 * M_PI / 2)
		num_texture = side_of_the_world_3(cub, xx, yy);
	else if (dir > 3 * M_PI / 2 && dir <= 2 * M_PI)
		num_texture = side_of_the_world_4(cub, xx, yy);
	if (num_texture == 1)
		return (cub->no);
	else if (num_texture == 2)
		return (cub->so);
	else if (num_texture == 3)
		return (cub->we);
	else if (num_texture == 4)
		return (cub->ea);
	return (cub->no);
}
