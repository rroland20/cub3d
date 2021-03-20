/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:46:40 by rroland           #+#    #+#             */
/*   Updated: 2021/03/20 18:39:08 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int pars_map(t_map **map, char *line)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	if (line[i] == '\0')
		valid = -1;
	while (line[i] != '\0')
	{
		if((line[i] != ' ') && (line[i] != '1') && (line[i] != '0')
		&& (line[i] != '2') && (line[i] != 'N') && (line[i] != 'S')
		&& (line[i] != 'W') && (line[i] != 'E'))
				valid = -1;
		i++;
	}

	ft_lstadd_back(map, ft_lstnew(ft_strdup(line)));
	// printf("%s\n", map->content);
	return (valid);
}

int pars_nul(t_cub *cub, int tmp, int i, int tmp_2)
{
	int valid;
	int save;
	int tt;
	int ii;
tmp_2 = 0;
	valid = -1;
	save = i;
	tt = tmp;
	ii = i;
	while (cub->my_map[tmp][i] != '\0')
	{
		if (cub->my_map[tmp][i] == '1')
			valid = 1;
		i++;
		printf("%d\n", i);
	}
	while (save != 0)
	{
		if (cub->my_map[tmp][save] == '1')
			valid = 1;
		save--;
	}
	// while (tmp != tmp_2)
	// {
	// 	if (cub->my_map[tmp][ii] == '1')
	// 		valid = 1;
	// 	tmp++;
	// }
	// while (tt != 0)
	// {
	// 	if (cub->my_map[tt][ii] == '1')
	// 		valid = 1;
	// 	tmp--;
	// }
	return (valid);
}

