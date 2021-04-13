/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:27:11 by rroland           #+#    #+#             */
/*   Updated: 2021/04/14 00:37:30 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	zeroing_3(t_cub *cub)
{
	cub->width_spr = 0;
	cub->coll_spr = 0;
	cub->save_bmp = 0;
	cub->y_sprite = 0;
}

static void	zeroing_2(t_cub *cub)
{
	cub->we.size_line = 0;
	cub->no.tex = 0;
	cub->so.tex = 0;
	cub->we.tex = 0;
	cub->ea.tex = 0;
	cub->dist_to_wall = 0;
	cub->mlx_win = 0;
	cub->size_line = 0;
	cub->img_addr = 0;
	cub->color_ceil = 0;
	cub->color_floor = 0;
	cub->max_map_size = 0;
	cub->sprite.tex = 0;
	cub->angle = 0;
	cub->c = 0;
	cub->my_cos = 0;
	cub->my_sin = 0;
	cub->my_map = 0;
	cub->check_double = 0;
	cub->count_sprite = 0;
	cub->count_x = 0;
	cub->count_y = 0;
	cub->dist_spr = 0;
	cub->x_sprite = 0;
	zeroing_3(cub);
}

static void	zeroing_1(t_cub *cub)
{
	cub->ea.size_line = 0;
	cub->fd = 0;
	cub->run.w = 0;
	cub->run.s = 0;
	cub->run.a = 0;
	cub->run.d = 0;
	cub->run.left = 0;
	cub->run.right = 0;
	cub->player = 0;
	cub->bpp = 0;
	cub->mlx = 0;
	cub->img = 0;
	cub->line = 0;
	cub->x_end = 0;
	cub->y_end = 0;
	cub->hitxy = 0;
	cub->width = -1;
	cub->height = -1;
	cub->floor.red = -1;
	cub->floor.green = -1;
	cub->floor.blue = -1;
	cub->ceil.red = -1;
	cub->ceil.green = -1;
	cub->ceil.blue = -1;
	zeroing_2(cub);
}

void	zeroing(t_cub *cub)
{
	cub->x = 0;
	cub->y = 0;
	cub->no.addr = 0;
	cub->so.addr = 0;
	cub->we.addr = 0;
	cub->ea.addr = 0;
	cub->sprite.addr = 0;
	cub->no.width = 0;
	cub->so.width = 0;
	cub->we.width = 0;
	cub->ea.width = 0;
	cub->sprite.width = 0;
	cub->no.height = 0;
	cub->so.height = 0;
	cub->we.height = 0;
	cub->ea.height = 0;
	cub->sprite.height = 0;
	cub->no.tex_img = 0;
	cub->so.tex_img = 0;
	cub->we.tex_img = 0;
	cub->ea.tex_img = 0;
	cub->sprite.tex_img = 0;
	cub->no.size_line = 0;
	cub->so.size_line = 0;
	zeroing_1(cub);
}

void	free_one_list(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	*map = (*map)->next;
	free(tmp->content);
	free(tmp);
}
