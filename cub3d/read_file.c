/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:15:47 by rroland           #+#    #+#             */
/*   Updated: 2021/04/28 22:10:32 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_output2(int code, t_cub *cub)
{
	if (code == 1)
		ft_putstr("Error filename\n");
	else if (code == 2)
		ft_putstr("Error opening file with texture\n");
	else if (code == 3)
		ft_putstr("Error wrong number of arguments\n");
	else if (code == 4)
		ft_putstr("Error opening file with map\n");
	else if (code == 5)
		ft_putstr("Error in screenshot creation\n");
	else if (code == 6)
		ft_putstr("Error opening BMP file\n");
	if (code != 3)
		exita(cub);
	else
		exit(1);
}

void	error_output(int code, t_cub *cub)
{
	if (code == 1)
		ft_putstr("Error valid parameters\n");
	else if (code == 2)
		ft_putstr("Error valid map\n");
	else if (code == 3)
		ft_putstr("Error: not closed world map\n");
	else if (code == 4)
		ft_putstr("Error: many players\n");
	else if (code == 5)
		ft_putstr("Error: no player\n");
	else if (code == 6)
		ft_putstr("Error memory allocation\n");
	exita(cub);
}

void	read_file2(t_cub *cub, t_map *map)
{
	int	tmp;
	int	sum;
	int	size_len;

	tmp = ft_lstsize(map);
	sum = tmp;
	memch(cub->my_map = malloc(sizeof(char *) * (tmp + 1)), cub);
	cub->my_map[tmp] = 0;
	memch(cub->dist_to_wall = malloc(sizeof(double) * (cub->width + 1)), cub);
	tmp = 0;
	while (tmp != sum)
	{
		size_len = ft_strlen(map->content);
		if (size_len < cub->max_map_size)
			cub->my_map[tmp] = ft_strjoin_map(ft_strdup(map->content), \
			cub->max_map_size - size_len);
		else
			cub->my_map[tmp] = ft_strdup(map->content);
		free_one_list(&map);
		tmp++;
	}
}

void	read_file(t_cub *cub, t_map *map)
{
	int	sum;
	int	valid;

	sum = 0;
	while (get_next_line(cub->fd, &cub->line) == 1)
	{
		if (sum < 8)
		{
			valid = parser_gnl(cub, cub->line);
			if (valid == -1)
				error_output(1, cub);
			else
				sum = valid + sum;
		}
		else
		{
			valid = pars_map(cub, &map, cub->line);
			if (valid == -1)
				error_output(2, cub);
		}
		free(cub->line);
	}
	valid = pars_map(cub, &map, cub->line);
	free(cub->line);
	read_file2(cub, map);
}
