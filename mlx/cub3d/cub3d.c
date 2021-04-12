/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:13:27 by rroland           #+#    #+#             */
/*   Updated: 2021/04/12 21:26:45 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= cub->width || y >= cub->height)
		return ;
	dst = cub->img_addr + y * cub->size_line + x * 4;
	*(unsigned int *)dst = color;
}

void	free_one_list(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	*map = (*map)->next;
	free(tmp->content);
	free(tmp);
}

static void	check_filename(char *argv)
{
	int	i;
	int	fd;

	i = ft_strlen(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_output2(4);
	if (argv[i - 4] != '.' || argv[i - 3] != 'c'
		|| argv[i - 2] != 'u' || argv[i - 1] != 'b')
		error_output2(1);
}

static void	check_save(char *argv, t_cub *cub)
{
	char	*save;
	int		n;
	int		k;
	int		i;

	i = 0;
	save = "--save";
	n = ft_strlen(argv);
	k = ft_strlen(save);
	if (n != k)
		error_output2(5);
	while (i < n)
	{
		if (argv[i] == '\0' && save[i] == '\0')
			break;
		if (argv[i] != save[i])
			error_output2(5);
		i++;
	}
	cub->save_bmp = 1;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	t_map	*map;

	cub = malloc(sizeof(t_cub));
	map = 0;
	zeroing(cub);
	if (argc < 2 || argc > 3)
		error_output2(3);
	if (argc == 2)
	{
		check_filename(argv[1]);
		cub->mlx = mlx_init();
		cub->fd = open(argv[1], O_RDONLY);
		read_file(cub, map);
		read_map(cub);
		mlx_func(cub);
	}
	else if (argc == 3)
	{
		check_filename(argv[1]);
		check_save(argv[2], cub);
		cub->fd = open(argv[1], O_RDONLY);
		read_file(cub, map);
		cub->mlx = mlx_init();
		read_map(cub);
		mlx_func(cub);
	}
	return (0);
}
