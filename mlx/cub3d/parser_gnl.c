/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:48:19 by rroland           #+#    #+#             */
/*   Updated: 2021/04/12 21:23:10 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	zeroing(t_cub *cub)
{
	cub->width = -1;
	cub->height = -1;
	cub->floor.red = -1;
	cub->floor.green = -1;
	cub->floor.blue = -1;
	cub->ceil.red = -1;
	cub->ceil.green = -1;
	cub->ceil.blue = -1;
	cub->no.tex = 0;
	cub->so.tex = 0;
	cub->we.tex = 0;
	cub->ea.tex = 0;
	cub->max_map_size = 0;
	cub->sprite.tex = 0;
	cub->angle = 0;
	cub->c = 0;
	cub->my_cos = 0;
	cub->my_sin = 0;
	cub->count_sprite = 0;
	cub->save_bmp = 0;
}

void	skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

int	parser_gnl(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] == 'R')
		return (pars_resolution(cub, &line[i], i));
	else if (line[i] == '\0')
		return (0);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (pars_nswe(&(cub->no.tex), line, i));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (pars_nswe(&(cub->so.tex), line, i));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (pars_nswe(&(cub->we.tex), line, i));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (pars_nswe(&(cub->ea.tex), line, i));
	else if (line[i] == 'S')
		return (pars_nswe(&(cub->sprite.tex), line, (i - 1)));
	else if (line[i] == 'F')
		return (pars_fc(&(cub->floor), &line[i], i));
	else if (line[i] == 'C')
		return (pars_fc(&(cub->ceil), &line[i], i));
	else
		return (-1);
	return (0);
}

int	pars_nswe(char **tex, char *line, int i)
{
	int	valid;
	int	j;

	valid = 1;
	i += 2;
	j = -1;
	skip_spaces(line, &i);
	if (*tex != 0)
		valid = -1;
	*tex = ft_strdup(&line[i]);
	while (tex[0][++j] != 0)
		if (tex[0][j] == ' ')
			return (-1);
	j = ft_strlen(*tex);
	if ((*tex)[j - 4] != '.' || (*tex)[j - 3] != 'x'
		|| (*tex)[j - 2] != 'p' || (*tex)[j - 1] != 'm')
		valid = -1;
	return (valid);
}
