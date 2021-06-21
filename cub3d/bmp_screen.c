/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alena <alena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:21:00 by rroland           #+#    #+#             */
/*   Updated: 2021/04/29 00:03:16 by alena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	header_bmp(t_cub *cub, int fd)
{
	int	info;

	write(fd, "BM", 2);
	info = cub->width * cub->height * 4;
	write(fd, &info, 4);
	info = 0;
	write(fd, &info, 4);
	info = 54;
	write(fd, &info, 4);
	info = 40;
	write(fd, &info, 4);
	info = cub->width;
	write(fd, &info, 4);
	info = cub->height;
	write(fd, &info, 4);
	info = 1;
	write(fd, &info, 2);
	info = 32;
	write(fd, &info, 2);
	info = 0;
	write(fd, &info, 24);
}

void	make_screen(t_cub *cub)
{
	int	fd;
	int	i;

	fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		error_output2(6, cub);
	header_bmp(cub, fd);
	i = cub->height;
	while (i >= 0)
	{
		write(fd, cub->img_addr + i * cub->width * 4, 4 * cub->width);
		i--;
	}
	close(fd);
	exita(cub);
}
