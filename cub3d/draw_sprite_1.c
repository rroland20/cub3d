/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 02:45:37 by rroland           #+#    #+#             */
/*   Updated: 2021/04/28 16:56:30 by alena            ###   ########.fr       */
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

double	norm_dir(double dir)
{
	while (dir >= 2 * M_PI)
		dir -= 2 * M_PI;
	while (dir < 0)
		dir += 2 * M_PI;
	return (dir);
}
