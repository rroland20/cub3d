/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rfc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:50:47 by rroland           #+#    #+#             */
/*   Updated: 2021/03/18 20:48:32 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		pars_resolution(t_cub *cub, char *line, int i)
{
	i++;
	if ((cub->width = ft_atoi(line, &i)) == -1 || cub->width > 2560 ||
		(cub->height = ft_atoi(line, &i)) == -1 || cub->height > 1440)
	{
		printf("Error resolution\n");
		exit(1);
	}
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
		{
			printf("Error resolution\n");
			exit(1);
		}
		i++;
	}
	// printf("%d %d\n", cub->width, cub->height);
	return (1);
}

void	check_pars(int value, int *valid, char *line, int *i)
{
	if (value > 255 || value < 0)
		*valid = -1;
	while (line[*i] == ' ' && line[*i] != '\0')
		++(*i);
}

int		pars_fc(t_color_fc *col, char *line, int i)
{
	int valid;

	valid = 1;
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
			// printf("%d %d %d\n", col->red, col->green, col->blue);
		}
	}
	else
		valid = -1;
	return (valid);
}
