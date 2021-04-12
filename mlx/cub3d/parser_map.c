/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:46:40 by rroland           #+#    #+#             */
/*   Updated: 2021/04/12 16:08:58 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pars_map(t_cub *cub, t_map **map, char *line)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	if (line[i] == '\0' && !(*map))
		return (1);
	if (line[i] == '\0')
		valid = 1;
	while (line[i] != '\0')
	{
		if ((line[i] != ' ') && (line[i] != '1') && (line[i] != '0')
			&& (line[i] != '2') && (line[i] != 'N') && (line[i] != 'S')
			&& (line[i] != 'W') && (line[i] != 'E'))
			valid = -1;
		i++;
	}
	if (i > cub->max_map_size)
		cub->max_map_size = i;
	ft_lstadd_back(map, ft_lstnew(ft_strdup(line)));
	return (valid);
}

int	check_wall(t_cub *cub, int tmp, int i)
{
	if (cub->my_map[tmp][i] == ' ')
		return (-1);
	if (cub->my_map[tmp][i] == '1')
		return (1);
	return (0);
}

int	pars_nul(t_cub *cub, int tmp, int i)
{
	int	valid;
	int	tmp_cpy;
	int	i_cpy;

	valid = 0;
	tmp_cpy = tmp;
	i_cpy = i;
	while (cub->my_map[tmp][i_cpy] != '\0')
	{
		if ((valid += check_wall(cub, tmp, i_cpy)) != 0)
			break ;
		i_cpy++;
	}
	i_cpy = i;
	while (i_cpy != -1)
	{
		if ((valid += check_wall(cub, tmp, i_cpy)) != 1)
			break ;
		i_cpy--;
	}
	while (cub->my_map[tmp] != 0)
	{
		if ((valid += check_wall(cub, tmp, i)) != 2)
			break ;
		tmp++;
	}
	while (tmp_cpy != -1)
	{
		if ((valid += check_wall(cub, tmp_cpy, i)) != 3)
			break ;
		tmp_cpy--;
	}
	return (valid);
}
