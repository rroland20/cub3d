/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:18:47 by rroland           #+#    #+#             */
/*   Updated: 2021/04/29 00:10:03 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mlx_func(t_cub *cub)
{
	int	k;

	if (cub->save_bmp == 0)
		cub->mlx_win = mlx_new_window(cub->mlx, cub->width, \
	cub->height, "cub3D");
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->img_addr = mlx_get_data_addr(cub->img, &(cub->bpp), \
	&(cub->size_line), &k);
	if (cub->save_bmp == 1)
		rendering(cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, key_wringing_out, cub);
	mlx_hook(cub->mlx_win, 33, 256, exita, cub);
	mlx_loop_hook(cub->mlx, rendering, cub);
	mlx_loop(cub->mlx);
	close(cub->fd);
}
