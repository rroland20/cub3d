/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:59:19 by rroland           #+#    #+#             */
/*   Updated: 2021/04/28 18:38:12 by alena            ###   ########.fr       */
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
		error_output(4, cub);
	if (cub->check_double < 1)
		error_output(5, cub);
	if (pars_texture(cub) == -1)
		error_output2(2, cub);
}

static int	check_chars(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == '2')
		return (1);
	return (0);
}

static int	check_chars1(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	dop_to_while(t_cub *cub, int tmp, int i)
{
	cub->check_double = 0;
	while (cub->my_map[tmp] != 0)
	{
		i = -1;
		while (cub->my_map[tmp][++i] != '\0')
		{
			if (check_chars(cub->my_map[tmp][i]))
			{
				if (cub->my_map[tmp][i] == '2')
					cub->count_sprite += 1;
				if (check_chars1(cub->my_map[tmp][i]))
				{
					cub->x = i + 0.5;
					cub->y = tmp + 0.5;
					cub->player = cub->my_map[tmp][i];
					cub->check_double += 1;
				}
				if ((pars_nul(cub, tmp, i)) != 4)
					error_output(3, cub);
			}
		}
		tmp++;
	}
	memch(cub->count_x = malloc(sizeof(double) * (cub->count_sprite + 1)), cub);
	memch(cub->count_y = malloc(sizeof(double) * (cub->count_sprite + 1)), cub);
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
