/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:13:27 by rroland           #+#    #+#             */
/*   Updated: 2021/04/11 18:58:49 by rroland          ###   ########.fr       */
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

void	check_filename(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 4] != '.' || argv[i - 3] != 'c'
		|| argv[i - 2] != 'u' || argv[i - 1] != 'b')
		error_output2(1);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	t_map	*map;

	cub = malloc(sizeof(t_cub));
	map = 0;
	zeroing(cub);
	if (argc == 2)
	{
		check_filename(argv[1]);
		cub->mlx = mlx_init();
		cub->fd = open(argv[1], O_RDONLY);
		read_file(cub, map);
		read_map(cub);
		mlx_func(cub);
	}
	return (0);
}
