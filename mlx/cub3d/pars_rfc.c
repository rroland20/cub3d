/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rfc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:50:47 by rroland           #+#    #+#             */
/*   Updated: 2021/03/14 19:11:44 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		pars_resolution(t_cub *cub, char *line, int i)
{
	i++;
	if ((cub->width = ft_atoi(line, &i)) == -1 || cub->width > 2560 ||
		(cub->height = ft_atoi(line, &i)) == -1 || cub->height > 1395)
	{
		printf("Error resolution\n");
		exit(1);
	}
	if (line[i] != '\0')
	{
		printf("Error resolution\n");
		exit(1);
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

int		pars_floor(t_cub *cub, char *line, int i)
{
	int valid;

	valid = 1;
	i++;
	cub->f_red = ft_atoi(line, &i);
	check_pars(cub->f_red, &valid, line, &i);
	if (line[i] == ',')
	{
		i++;
		cub->f_green = ft_atoi(line, &i);
		check_pars(cub->f_green, &valid, line, &i);
		if (line[i] == ',')
		{
			i++;
			cub->f_blue = ft_atoi(line, &i);
			check_pars(cub->f_blue, &valid, line, &i);
			// printf("%d %d %d\n", cub->f_red, cub->f_green, cub->f_blue);
		}
	}
	else
		valid = -1;
	return (valid);
}

int		pars_ceilling(t_cub *cub, char *line, int i)
{
	int valid;

	valid = 1;
	i++;
	cub->c_red = ft_atoi(line, &i);
	check_pars(cub->c_red, &valid, line, &i);
	if (line[i] == ',')
	{
		i++;
		cub->c_green = ft_atoi(line, &i);
		check_pars(cub->c_green, &valid, line, &i);
		if (line[i] == ',')
		{
			i++;
			cub->c_blue = ft_atoi(line, &i);
			check_pars(cub->c_blue, &valid, line, &i);
			// printf("%d %d %d\n", cub->c_red, cub->c_green, cub->c_blue);
		}
	}
	else
		valid = -1;
	return (valid);
}
