/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:48:19 by rroland           #+#    #+#             */
/*   Updated: 2021/03/22 16:10:55 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void zeroing(t_cub *cub)
{
	cub->width = -1;
	cub->height = -1;
	cub->floor.red = -1;
	cub->floor.green = -1;
	cub->floor.blue = -1;
	cub->ceil.red = -1;
	cub->ceil.green = -1;
	cub->ceil.blue = -1;
	cub->tx_no = 0;
	cub->tx_so = 0;
	cub->tx_we = 0;
	cub->tx_ea = 0;
	cub->max_map_size = 0;
	cub->tx_sprite = 0;
}

void skip_spaces(char *line, int *i)
{
	while(line[*i] == ' ')
	{
		(*i)++;
	}
}

int parser_gnl(t_cub *cub, char *line)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	skip_spaces(line, &i);
	if (line[i] == 'R')
		valid = pars_resolution(cub, &line[i], i);
	else if (line[i] == '\0')
		valid = 0;
	else if (line[i] == 'N' && line[i + 1] == 'O')
		valid = pars_nswe(cub->tx_no, line, i);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		valid = pars_nswe(cub->tx_so, line, i);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		valid = pars_nswe(cub->tx_we, line, i);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		valid = pars_nswe(cub->tx_ea, line, i);
	else if (line[i] == 'S')
		valid = pars_nswe(cub->tx_sprite, line, i);
	else if (line[i] == 'F')
		valid = pars_fc(&(cub->floor), &line[i], i);
	else if (line[i] == 'C')
		valid = pars_fc(&(cub->ceil), &line[i], i);
	else
	{
		printf("Error identifier\n");
		exit(1);
	}
	return(valid);
}

int pars_nswe(char *tex, char *line, int i)
{
	int valid;
	int j;

	valid = 1;
	i += 2;
	j = 0;
	skip_spaces(line, &i);
	if (tex != 0)	
		valid = -1;
	tex = ft_strdup(&line[i]);
	j = ft_strlen(tex);
	if (tex[j - 4] != '.' || tex[j - 3] != 'x' ||
	tex[j - 2] != 'p' || tex[j- 1] != 'm')
			valid = -1;
	return (valid);
}