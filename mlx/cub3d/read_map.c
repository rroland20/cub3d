/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:59:19 by rroland           #+#    #+#             */
/*   Updated: 2021/04/10 19:58:11 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	read_map2(t_cub *cub)
{
	locating_the_player(cub);
	cub->color_ceil = (cub->ceil.red << 16) | (cub->ceil.green << 8) \
	| cub->ceil.blue;
	cub->color_floor = (cub->floor.red << 16) | (cub->floor.green << 8) \
	| cub->floor.blue;
	if (cub->check_double > 1)
		error_output(4);
	if (cub->check_double < 1)
		error_output(5);
	if (pars_texture(cub) == -1)
		error_output2(2);
}

void	dop_to_while(t_cub *cub, int tmp, int i)
{
	cub->check_double = 0;
	while (cub->my_map[tmp] != 0)
	{
		i = -1;
		while (cub->my_map[tmp][++i] != '\0')
			if (cub->my_map[tmp][i] == '0' || cub->my_map[tmp][i] == 'N'
				|| cub->my_map[tmp][i] == 'S' || cub->my_map[tmp][i] == 'W'
				|| cub->my_map[tmp][i] == 'E' || cub->my_map[tmp][i] == '2')
			{
				if (cub->my_map[tmp][i] == '2')
					cub->count_sprite += 1;
				if (cub->my_map[tmp][i] == 'N' || cub->my_map[tmp][i] == 'S'
				|| cub->my_map[tmp][i] == 'W' || cub->my_map[tmp][i] == 'E')
				{
					cub->x = i + 0.5;
					cub->y = tmp + 0.5;
					cub->player = cub->my_map[tmp][i];
					cub->check_double += 1;
				}
				if ((pars_nul(cub, tmp, i)) != 4)
					error_output(3);
			}
		tmp++;
	}
	cub->count_x = malloc(sizeof(double) * (cub->count_sprite + 1));
	cub->count_y = malloc(sizeof(double) * (cub->count_sprite + 1));
}

void	read_map(t_cub *cub)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	dop_to_while(cub, tmp, i);
	read_map2(cub);
}
