/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rfc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:50:47 by rroland           #+#    #+#             */
/*   Updated: 2021/04/28 23:17:42 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pars_resolution_norm(t_cub *cub)
{
	if (cub->save_bmp != 1)
	{
		if (cub->width > 1366)
			cub->width = 1366;
		if (cub->height > 768)
			cub->height = 768;
	}
}

int	pars_resolution(t_cub *cub, char *line, int i)
{
	int	valid;

	valid = 1;
	i++;
	while (line[i] == ' ')
		i++;
	if (cub->width != -1 || cub->height != -1 || line[i] == '0')
		valid = -1;
	cub->width = ft_atoi(line, &i);
	cub->height = ft_atoi(line, &i);
	if (cub->width < 1 || cub->height < 1)
		valid = -1;
	pars_resolution_norm(cub);
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			valid = -1;
		i++;
	}
	return (valid);
}

void	check_pars(int value, int *valid, char *line, int *i)
{
	if (value > 255 || value < 0)
		*valid = -1;
	while (line[*i] == ' ' && line[*i] != '\0')
		++(*i);
}

int	pars_fc(t_color_fc *col, char *line, int i, int valid)
{
	i++;
	if (col->red != -1 || col->green != -1 || col->blue != -1)
		valid = -1;
	col->red = ft_atoi(line, &i);
	check_pars(col->red, &valid, line, &i);
	if (line[i] == ',')
	{
		i++;
		col->green = ft_atoi(line, &i);
		check_pars(col->green, &valid, line, &i);
		if (line[i] == ',')
		{
			i++;
			col->blue = ft_atoi(line, &i);
			check_pars(col->blue, &valid, line, &i);
			if (line[i] != '\0')
				valid = -1;
		}
		else
			valid = -1;
	}
	else
		valid = -1;
	return (valid);
}
