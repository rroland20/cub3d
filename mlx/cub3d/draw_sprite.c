/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:43:16 by rroland           #+#    #+#             */
/*   Updated: 2021/04/12 20:14:13 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sort_distance(t_cub *cub, int j)
{
	int		i;
	int		k;
	double	big_tmp;

	i = -1;
	while (++i < j)
	{
		k = i;
		while (k < j)
		{
			if (cub->dist_spr[i] > cub->dist_spr[k])
			{
				big_tmp = cub->dist_spr[i];
				cub->dist_spr[i] = cub->dist_spr[k];
				cub->dist_spr[k] = big_tmp;
				big_tmp = cub->count_x[i];
				cub->count_x[i] = cub->count_x[k];
				cub->count_x[k] = big_tmp;
				big_tmp = cub->count_y[i];
				cub->count_y[i] = cub->count_y[k];
				cub->count_y[k] = big_tmp;
			}
			k++;
		}
	}
}

void	draw_sprite_1(t_cub *cub, int ii, int size)
{
	unsigned int	color;
	double			max;
	int				jj;
	double			tmp_y;
	double			tmp_x;

	tmp_x = cub->sprite.width * (ii - cub->coll_spr) / size;
	max = (cub->height + size) / 2;
	jj = (cub->height - size) / 2;
	tmp_y = 0;
	if (jj < 0)
	{
		tmp_y = (double)cub->sprite.height / (double)size * (-jj);
		jj = 0;
		max = cub->height;
	}
	while (jj < max)
	{
		color = sprite_color(cub, cub->sprite, tmp_y, tmp_x);
		if (color != 0)
			my_mlx_pixel_put(ii, jj, color, cub);
		jj++;
		tmp_y += (double)cub->sprite.height / (double)size;
	}
}

static void	draw_sprite2(t_cub *cub, int j)
{
	int	i;

	i = 0;
	cub->dist_spr = malloc(sizeof(double) * (cub->count_sprite + 1));
	while (i != cub->count_sprite)
	{
		cub->dist_spr[i] = sqrt((pow(cub->x - cub->count_x[i], 2)) \
		+ (pow(cub->y - cub->count_y[i], 2)));
		i++;
	}
	sort_distance(cub, j);
	cub->width_spr = cub->width / 2 / tan(M_PI / 6);
}

static void	draw_sprite3(t_cub *cub, int j, int *size, double *dir_spr)
{
	*dir_spr = atan2(cub->count_y[j] - cub->y, cub->count_x[j] - cub->x) \
		- cub->angle;
	while (*dir_spr >= 2 * M_PI)
		*dir_spr -= 2 * M_PI;
	while (*dir_spr < 0)
		*dir_spr += 2 * M_PI;
	*size = cub->width_spr / (cos(*dir_spr) * cub->dist_spr[j]);
}

void	draw_sprite(t_cub *cub, int j)
{
	int		i;
	int		size;
	double	dir_spr;

	draw_sprite2(cub, j);
	while (j--)
	{
		draw_sprite3(cub, j, &size, &dir_spr);
		cub->coll_spr = (double)cub->width / 2 + tan(dir_spr) * cub->width_spr - \
		(double)size / 2;
		if (size <= 0 || cub->coll_spr >= cub->width)
			continue ;
		i = cub->coll_spr;
		while (i < cub->coll_spr + size && i < cub->width)
		{
			if (i >= 0)
			{
				if (cub->dist_to_wall[i] <= cub->dist_spr[j] && ++i)
					continue ;
				draw_sprite_1(cub, i, size);
			}
			i++;
		}
	}
}
