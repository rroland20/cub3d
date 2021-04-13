/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 01:35:38 by rroland           #+#    #+#             */
/*   Updated: 2021/04/14 01:36:16 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned int	wall_color(t_cub *cub, t_textures tex, int y)
{
	int				pos;
	unsigned int	color;

	pos = (y * tex.size_line + (int)cub->hitxy * 4);
	color = *(unsigned int *)((tex.addr) + pos);
	return (color);
}

unsigned int	sprite_color(t_cub *cub, t_textures tex, double y, double x)
{
	unsigned int	color;

	color = *(unsigned int *)(tex.addr + (int)y * tex.size_line \
		+ (int)x * (cub->bpp / 8));
	return (color);
}

static double	draw_wall_2(t_cub *cub, double *hgt, t_textures tex)
{
	double	kall;

	kall = 0;
	if (*hgt > cub->height)
	{
		kall = (double)tex.height / *(hgt) * (-1 * \
		((double)cub->height - *(hgt)) / 2);
		*(hgt) = cub->height;
	}	
	return (kall);
}

void	draw_wall(t_cub *cub, int x, double dir, t_textures tex)
{
	int		y;
	double	hgt;
	double	dist;
	double	kall;
	double	q;

	dir += 0;
	cub->hitxy = cub->hitxy * tex.width;
	dist = sqrt((pow(cub->x - cub->x_end, 2)) + (pow(cub->y - cub->y_end, 2)));
	cub->dist_to_wall[x] = dist;
	hgt = cub->width / 2 / tan(M_PI / 6) / (dist * cos(dir - cub->angle));
	q = hgt;
	kall = draw_wall_2(cub, &hgt, tex);
	y = -1;
	while (++y < (cub->height - hgt) / 2)
		my_mlx_pixel_put(x, y, cub->color_ceil, cub);
	y--;
	while (++y < (cub->height + hgt) / 2)
	{
		my_mlx_pixel_put(x, y, wall_color(cub, tex, (int)kall), cub);
		kall += ((double)tex.height / (double)q);
	}
	y--;
	while (++y < cub->height)
		my_mlx_pixel_put(x, y, cub->color_floor, cub);
}
