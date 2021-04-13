/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:54:32 by rroland           #+#    #+#             */
/*   Updated: 2021/04/14 02:48:13 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	count_zero(t_cub *cub)
{
	int	i;

	i = 0;
	while (i != cub->count_sprite)
	{
		cub->count_x[i] = 0;
		cub->count_y[i] = 0;
		i++;
	}
}

static void	coll_wall(t_cub *cub)
{
	cub->x_end = cub->x + (cub->c * cub->my_cos);
	cub->y_end = cub->y + (cub->c * cub->my_sin);
	while (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
	|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' ')
	{
		cub->c -= 0.0001;
		cub->x_end = cub->x + (cub->c * cub->my_cos);
		cub->y_end = cub->y + (cub->c * cub->my_sin);
	}
	while (!(cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
		|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' '))
	{
		cub->c += 0.000001;
		cub->x_end = cub->x + (cub->c * cub->my_cos);
		cub->y_end = cub->y + (cub->c * cub->my_sin);
	}
}

static void	render_help(int k, int flag, t_cub *cub, int *j)
{
	cub->x_sprite = floor(cub->x_end) + 0.5;
	cub->y_sprite = floor(cub->y_end) + 0.5;
	if (*j == 0)
	{
		cub->count_x[*j] = cub->x_sprite;
		cub->count_y[*j] = cub->y_sprite;
		(*j)++;
	}
	else
	{
		while (k != cub->count_sprite)
		{
			if (cub->count_x[k] == cub->x_sprite
				&& cub->count_y[k] == cub->y_sprite)
				flag = 0;
			k++;
		}
		if (flag != 0)
		{
			cub->count_x[*j] = cub->x_sprite;
			cub->count_y[*j] = cub->y_sprite;
			(*j)++;
		}
	}
}

int	render_help2(t_cub *cub, double dir, int i, int j)
{
	while (++i < cub->width)
	{
		dir = norm_dir(dir);
		cub->c = 0;
		cub->my_cos = cos(dir);
		cub->my_sin = sin(dir);
		while (1)
		{
			cub->x_end = cub->x + (cub->c * cub->my_cos);
			cub->y_end = cub->y + (cub->c * cub->my_sin);
			if ((cub->my_map[(int)(cub->y_end)][(int)cub->x_end] == '1'
			|| cub->my_map[(int)cub->y_end][(int)(cub->x_end)] == ' '))
			{
				coll_wall(cub);
				draw_wall(cub, i, dir, side_of_the_world(cub, dir, cub->c));
				break ;
			}
			if (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '2')
				render_help(0, 1, cub, &j);
			cub->c += 0.01;
		}
		dir += (M_PI / 3) / cub->width;
	}
	return (j);
}

int	rendering(t_cub *cub)
{
	int		i;
	double	dir;

	key_run(cub);
	dir = cub->angle - (M_PI / 6);
	count_zero(cub);
	draw_sprite(cub, render_help2(cub, dir, -1, 0));
	i = -1;
	while (++i != cub->count_sprite)
	{
		cub->count_x[i] = 0;
		cub->count_y[i] = 0;
	}
	if (cub->save_bmp == 1)
		make_screen(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	return (0);
}
