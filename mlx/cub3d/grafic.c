/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:54:32 by rroland           #+#    #+#             */
/*   Updated: 2021/04/11 19:49:29 by rroland          ###   ########.fr       */
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

unsigned int		give_c(t_cub *cub, t_textures tex, double y, double x)
{
	unsigned int	color;
	color = *(unsigned int *)(tex.addr + (int)y * tex.size_line
	+ (int)x * (cub->bpp / 8));
	return (color);
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
	{
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
	}
	else if (dir > M_PI / 2 && dir <= M_PI)
	{
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
	}
	else if (dir > M_PI && dir <= 3 * M_PI / 2)
	{
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
	}
	else if (dir > 3 * M_PI / 2 && dir <= 2 * M_PI)
	{
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
	}
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

void	draw_wall(t_cub *cub, int x, double dir, t_textures tex)
{
	int		y;
	double	hgt;
	double	dist;
	double	kall;
	double	q;

	kall = 0;
	dir += 0;
	cub->hitxy = cub->hitxy * tex.width;
	dist = sqrt((pow(cub->x - cub->x_end, 2)) + (pow(cub->y - cub->y_end, 2)));
	cub->dist_to_wall[x] = dist;
	hgt = cub->width / 2 / tan(M_PI / 6) / (dist * cos(dir - cub->angle));
	q = hgt;
	if (hgt > cub->height)
	{
		kall = (double)tex.height / hgt * (-1 * \
		((double)cub->height - hgt) / 2);
		hgt = cub->height;
	}	
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

int		ft_slit_check(t_cub *cub, double dir, int i)
{
	t_cub test;
	t_cub test2;

	if (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '0')
	{
		test.x_end = cub->x - (cub->my_cos) * cub->c;
		test.y_end = cub->y + (cub->my_sin) * cub->c;
		test2.x_end = cub->x + (cub->my_cos) * cub->c;
		test2.y_end = cub->y - (cub->my_sin) * cub->c;
		if (cub->my_map[(int)(test.y_end)][(int)(test.x_end)] == '1'
	&& cub->my_map[(int)(test2.y_end)][(int)(test2.x_end)] == '1')
		{
			//printf ("Ya Tut!\n");
			draw_wall(cub, i, dir, side_of_the_world(cub, dir, cub->c));
			return (0);
		}
	}
	return (1);
}

void	sort_distance(t_cub *cub, int j)
{
	int	i;
	int	k;
	double	big_tmp;

	i = 0;
	while (i < j)
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
		i++;
	}
}

void	draw_sprite_1(t_cub *cub, int ii, double tmp_x, int size)
{
	unsigned int color;
	double max;
	int jj;
	double tmp_y;

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
		color = give_c(cub, cub->sprite, tmp_y, tmp_x);
		if (color != 0)
			my_mlx_pixel_put(ii, jj, color, cub);
		jj++;
		tmp_y += (double)cub->sprite.height / (double)size;
	}
}
void	draw_sprite(t_cub *cub, int j)
{
	int i;
	double	width;
	double	dir_spr;
	double	coll_spr;
	int	size;
	int ii;
	double tmp_x;

	i = 0;
	cub->dist_spr = malloc(sizeof(double) * (cub->count_sprite + 1));
	while (i != cub->count_sprite)
	{
		cub->dist_spr[i] = sqrt((pow(cub->x - cub->count_x[i], 2)) + (pow(cub->y - cub->count_y[i], 2)));
		i++;
	}
	sort_distance(cub, j);
	width = cub->width / 2 / tan(M_PI / 6);
	while (j--)
	{
		dir_spr = atan2(cub->count_y[j] - cub->y, cub->count_x[j] - cub->x) - cub->angle;
		while (dir_spr >= 2 * M_PI)
			dir_spr -= 2 * M_PI;
		while (dir_spr < 0)
			dir_spr += 2 * M_PI;	
		size = width / (cos(dir_spr) * cub->dist_spr[j]);
		coll_spr = (double)cub->width  / 2 + tan(dir_spr) * width - (double)size / 2;
		if (size <= 0 || coll_spr >= cub->width)
			continue ;
		ii = coll_spr;
		while (ii < coll_spr + size && ii < cub->width)
		{
			if (ii >= 0)
			{
				if (cub->dist_to_wall[ii] <= cub->dist_spr[j] && ++ii)
					continue;
				tmp_x = cub->sprite.width * (ii - coll_spr) / size;
				draw_sprite_1(cub, ii, tmp_x, size);
			}
			ii++;
		}
	}
}

int	rendering(t_cub *cub)
{
	int		i;
	int		v;
	int		a;
	int		flag;
	double	dir;
	double	r;
	int		j;
	int		k;

	i = 0;
	flag = 0;
	a = 0;
	v = 0;
	j = 0;
	cub->x_end = cub->x;
	cub->y_end = cub->y;
	key_run(cub);
	dir = cub->angle - (M_PI / 6);
	while (i < cub->width)
	{
		while (dir >= 2 * M_PI)
			dir -= 2 * M_PI;
		while (dir < 0)
			dir += 2 * M_PI;
		cub->c = 0;
		cub->my_cos = cos(dir);
		cub->my_sin = sin(dir);
		r = 0.01;
		flag = 0;
		while (1)
		{
			cub->x_end = cub->x + (cub->c * cub->my_cos);
			cub->y_end = cub->y + (cub->c * cub->my_sin);
			// if (flag != 1 && (fabs(ceil(cub->y_end) - cub->y_end) <= 0.01 && fabs(ceil(cub->x_end) - cub->x_end) <= 0.01))
			// {
			// 	r = 0.0001;
			// 	flag = 1;
			// }
			if ((cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
			|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' '))
			{
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
				draw_wall(cub, i, dir, side_of_the_world(cub, dir, cub->c));
				break ;
			}
			if (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '2')
			{
				k = 0;
				flag = 1;
				cub->x_sprite = floor(cub->x_end) + 0.5;
				cub->y_sprite = floor(cub->y_end) + 0.5;
				if (j == 0)
				{
					cub->count_x[j] = cub->x_sprite;
					cub->count_y[j] = cub->y_sprite;
					j++;
				}
				else
				{
					while (k != cub->count_sprite)
					{
						if (cub->count_x[k] == cub->x_sprite && cub->count_y[k] == cub->y_sprite)
							flag = 0;
					k++;
					}
					if (flag != 0)
					{
						cub->count_x[j] = cub->x_sprite;
						cub->count_y[j] = cub->y_sprite;
						j++;
					}
				}
			}
			cub->c += r;
		}
		i++;
		dir += (M_PI / 3) / cub->width;
	}
	draw_sprite(cub, j);
	i = 0;
	while (i != cub->count_sprite)
	{
		cub->count_x[i] = 0;
		cub->count_y[i] = 0;
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	return (0);
}

// cub->x_end = cub->x + (cub->c * cub->my_cos);
// 			cub->y_end = cub->y;
// 			if (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
// 			|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' ')
// 			{
// 				while (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
// 				|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' ')
// 				{
// 					cub->c -= 0.0001;
// 					cub->x_end = cub->x + (cub->c * cub->my_cos);
// 				}
// 				while (!(cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
// 				|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' '))
// 				{
// 					cub->c += 0.000001;
// 					cub->x_end = cub->x + (cub->c * cub->my_cos);
// 				}
// 				cub->x_end = cub->x;
// 				cub->y_end = cub->y + (cub->c * cub->my_sin);
// 				draw_wall(cub, i, dir, side_of_the_world(cub, dir, cub->c));
// 				break ;
// 			}
// 				cub->y_end = cub->y + (cub->c * cub->my_sin);
// 			if (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
// 			|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' ')
// 			{
// 				while (cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
// 				|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' ')
// 				{
// 					cub->c -= 0.0001;
// 					cub->y_end = cub->y + (cub->c * cub->my_sin);
// 				}
// 				while (!(cub->my_map[(int)cub->y_end][(int)cub->x_end] == '1'
// 				|| cub->my_map[(int)cub->y_end][(int)cub->x_end] == ' '))
// 				{
// 					cub->c += 0.000001;
// 					cub->y_end = cub->y + (cub->c * cub->my_sin);
// 				}
// 				cub->x_end = cub->x + (cub->c * cub->my_cos);
// 				draw_wall(cub, i, dir, side_of_the_world(cub, dir, cub->c));
// 				break ;
// 			}
// 			cub->c += 0.01;