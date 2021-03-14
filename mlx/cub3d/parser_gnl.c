/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:48:19 by rroland           #+#    #+#             */
/*   Updated: 2021/03/14 19:53:00 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void zeroing(t_cub *cub)
{
	cub->width = -1;
	cub->height = -1;
	cub->f_red = -1;
	cub->f_green = -1;
	cub->f_blue = -1;
	cub->c_red = -1;
	cub->c_green = -1;
	cub->c_blue = -1;
}

void skip_spaces(char *line, int *i)
{
	while(line[*i] == ' ')
		(*i)++;
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
		valid = 1;
	else if (line[i] == 'N' && line[i + 1] == 'O')
		{
			printf("%c\n", line[i]);
			// printf("%d\n", i);
			valid = pars_north(cub, &line[i], i);
		}
	// else if (line[i] == 'S' && line[i + 1] == 'O')
	// 	pars_south(cub, &line[i]);
	// else if (line[i] == 'W' && line[i + 1] == 'E')
	// 	pars_west(cub, &line[i]);
	// else if (line[i] == 'E' && line[i + 1] == 'A')
	// 	pars_east(cub, &line[i]);
	// else if (line[i] == 'S')
	// 	pars_sprite(cub, &line[i]);
	else if (line[i] == 'F')
		valid = pars_floor(cub, &line[i], i);
	else if (line[i] == 'C')
		valid = pars_ceilling(cub, &line[i], i);
	else
	{
		printf("Error identifier\n");
		exit(1);
	}
	return(valid);
}

int pars_north(t_cub *cub, char *line, int i)
{
	int valid;

	valid = 1;
	cub = 0;
	// line = 0;
	// i++;
	printf("%c\n", line[i]);
	// printf("%d\n", i);
	return (valid);
}