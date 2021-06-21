/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:12:35 by alena             #+#    #+#             */
/*   Updated: 2021/04/29 00:12:02 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_struct1(t_cub *cub)
{
	if (cub->mlx && cub->img)
	{
		mlx_destroy_image(cub->mlx, cub->img);
		mlx_destroy_image(cub->mlx, cub->no.tex_img);
		mlx_destroy_image(cub->mlx, cub->so.tex_img);
		mlx_destroy_image(cub->mlx, cub->we.tex_img);
		mlx_destroy_image(cub->mlx, cub->ea.tex_img);
		mlx_destroy_image(cub->mlx, cub->sprite.tex_img);
	}
	free(cub->no.tex);
	free(cub->so.tex);
	free(cub->we.tex);
	free(cub->ea.tex);
	free(cub->sprite.tex);
	if (cub->save_bmp == 1)
		free(cub->mlx);
}

void	free_struct(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->my_map)
	{
		while (cub->my_map[++i])
			free(cub->my_map[i]);
	}
	free(cub->my_map);
	if (cub->dist_to_wall)
		free(cub->dist_to_wall);
	if (cub->count_x)
		free(cub->count_x);
	if (cub->count_y)
		free(cub->count_y);
	if (cub->dist_spr)
		free(cub->dist_spr);
	free_struct1(cub);
}
