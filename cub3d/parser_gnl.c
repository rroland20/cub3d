/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:48:19 by rroland           #+#    #+#             */
/*   Updated: 2021/04/28 23:35:14 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	if (line[i] == '\0')
		return (0);
	else if (line[i] == 'R')
		return (pars_resolution(cub, line, i));
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
		return (pars_fc(&(cub->floor), line, i, 1));
	else if (line[i] == 'C')
		return (pars_fc(&(cub->ceil), line, i, 1));
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
	return (valid);
}
