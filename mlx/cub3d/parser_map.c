/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:46:40 by rroland           #+#    #+#             */
/*   Updated: 2021/04/12 18:08:01 by rroland          ###   ########.fr       */
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

int	pars_nul1(t_cub *cub, int valid, int tmp, int i)
{
	int	tmp_cpy;

	tmp_cpy = tmp;
	while (cub->my_map[tmp] != 0)
	{
		valid += check_wall(cub, tmp, i);
		if (valid != 2)
			break ;
		tmp++;
	}
	while (tmp_cpy != -1)
	{
		valid += check_wall(cub, tmp_cpy, i);
		if (valid != 3)
			break ;
		tmp_cpy--;
	}
	return (valid);
}

int	pars_nul(t_cub *cub, int tmp, int i)
{
	int	valid;
	int	i_cpy;

	valid = 0;
	i_cpy = i;
	while (cub->my_map[tmp][i_cpy] != '\0')
	{
		valid += check_wall(cub, tmp, i_cpy);
		if (valid != 0)
			break ;
		i_cpy++;
	}
	i_cpy = i;
	while (i_cpy != -1)
	{
		valid += check_wall(cub, tmp, i_cpy);
		if (valid != 1)
			break ;
		i_cpy--;
	}
	valid = pars_nul1(cub, valid, tmp, i);
	return (valid);
}
