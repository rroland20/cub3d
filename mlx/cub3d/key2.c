/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:10:57 by rroland           #+#    #+#             */
/*   Updated: 2021/04/06 17:12:07 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
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

int	exita(int k)
{
	exit(0);
	return (k);
}
