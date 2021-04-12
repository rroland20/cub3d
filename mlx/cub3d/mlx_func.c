/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:18:47 by rroland           #+#    #+#             */
/*   Updated: 2021/04/06 18:23:33 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mlx_func(t_cub *cub)
{
	int	k;

	cub->mlx_win = mlx_new_window(cub->mlx, cub->width, \
	cub->height, "cub3D");
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->img_addr = mlx_get_data_addr(cub->img, &(cub->bpp), \
	&(cub->size_line), &k);
	mlx_hook(cub->mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, key_wringing_out, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 17, exita, cub);
	mlx_loop_hook(cub->mlx, rendering, cub);
	mlx_loop(cub->mlx);
	close(cub->fd);
}
