/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:10:57 by rroland           #+#    #+#             */
/*   Updated: 2021/04/28 22:14:07 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		exita(cub);
	if (key == W)
		cub->run.w = 1;
	if (key == S)
		cub->run.s = 1;
	if (key == A)
		cub->run.a = 1;
	if (key == D)
		cub->run.d = 1;
	if (key == LEFT)
		cub->run.left = 1;
	if (key == RIGHT)
		cub->run.right = 1;
	return (0);
}

int	key_wringing_out(int key, t_cub *cub)
{
	if (key == W)
		cub->run.w = 0;
	if (key == S)
		cub->run.s = 0;
	if (key == A)
		cub->run.a = 0;
	if (key == D)
		cub->run.d = 0;
	if (key == LEFT)
		cub->run.left = 0;
	if (key == RIGHT)
		cub->run.right = 0;
	return (0);
}

int	exita(t_cub *cub)
{
	free_struct(cub);
	free(cub);
	exit(0);
	return (0);
}

void	memch(void *a, t_cub *cub)
{
	if (a == NULL)
		error_output(6, cub);
}
