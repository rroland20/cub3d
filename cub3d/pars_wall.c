/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:56:46 by rroland           #+#    #+#             */
/*   Updated: 2021/04/13 22:47:34 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pars_texture1(t_cub *cub)
{
	int	k;

	k = 0;
	cub->no.addr = mlx_get_data_addr(cub->no.tex_img, &(cub->bpp), \
	&(cub->no.size_line), &k);
	cub->so.addr = mlx_get_data_addr(cub->so.tex_img, &(cub->bpp), \
	&(cub->so.size_line), &k);
	cub->we.addr = mlx_get_data_addr(cub->we.tex_img, &(cub->bpp), \
	&(cub->we.size_line), &k);
	cub->ea.addr = mlx_get_data_addr(cub->ea.tex_img, &(cub->bpp), \
	&(cub->ea.size_line), &k);
	cub->sprite.addr = mlx_get_data_addr(cub->sprite.tex_img, &(cub->bpp), \
	&(cub->sprite.size_line), &k);
}

int	pars_texture(t_cub *cub)
{
	cub->no.tex_img = mlx_xpm_file_to_image(cub->mlx, cub->no.tex, \
	&(cub->no.width), &(cub->no.height));
	cub->so.tex_img = mlx_xpm_file_to_image(cub->mlx, cub->so.tex, \
	&(cub->so.width), &(cub->so.height));
	cub->we.tex_img = mlx_xpm_file_to_image(cub->mlx, cub->we.tex, \
	&(cub->we.width), &(cub->we.height));
	cub->ea.tex_img = mlx_xpm_file_to_image(cub->mlx, cub->ea.tex, \
	&(cub->ea.width), &(cub->ea.height));
	cub->sprite.tex_img = mlx_xpm_file_to_image(cub->mlx, cub->sprite.tex, \
	&(cub->sprite.width), &(cub->sprite.height));
	if (!(cub->no.tex_img) || !(cub->so.tex_img) || !(cub->we.tex_img)
		|| !(cub->ea.tex_img) || !(cub->sprite.tex_img))
		return (-1);
	pars_texture1(cub);
	return (0);
}

void	locating_the_player(t_cub *cub)
{
	if (cub->player == 'N')
		cub->angle = 3 * M_PI / 2;
	else if (cub->player == 'S')
		cub->angle = M_PI / 2;
	else if (cub->player == 'W')
		cub->angle = M_PI;
	else if (cub->player == 'E')
		cub->angle = 0;
}
