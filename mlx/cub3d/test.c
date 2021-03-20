/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:08:49 by rroland           #+#    #+#             */
/*   Updated: 2021/03/20 18:39:17 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub, char *img_addr)
{
	char	*dst;
	if (x < 0 || y < 0 || x >= 2000 || y >= 2000)
		return ;
	
	dst = img_addr + y * cub->size_line + x * 4;
	*(unsigned int*)dst = color;
}

int     key_press(int key, t_cub *cub)
{
    if (key == ESC)
        exit(0);
    if (key == W)
        cub->y -= 1;
	if (key == S)
        cub->y += 1;
	if (key == A)
        cub->x -= 1;
	if (key == D)
        cub->x += 1;
    cub->x += 0;
    printf("%d\n", key);
    return(0);
}

int     key_wringing_out(int key, t_cub *cub)
{
    cub->x += 0;
    return(key);
}

int exita(int k)
{
    exit(0);
    return (k);
}

int kall;
int kall_2;

int do_some_shit(t_cub *cub)
{
    int x;
    int y;

	
	x = 0;
	y = 0;
   	while (x != 1200)
    {
       y = 0;
		while (y != 1200)
		{
			my_mlx_pixel_put(x, y, 0x000000, cub, cub->img_addr);
			(y)++;
		}
		(x)++;
    }

	x = 100;
	if (kall_2 != 1)
	{
		if (cub->y > 45 && cub->y < 51)
		{
			kall = 50;
			kall_2 = 1;
		}
		if (!(cub->y > 45 && cub->y < 51))
		{
			while (x != 120)
			{
			y = 40;
				while (y != 60)
				{
					my_mlx_pixel_put(x, y, 0xFF0000, cub, cub->img_addr);
					(y)++;
				}
				(x)++;
			}
		}
	}
    x = cub->x;
    y = cub->y;
    while (x != cub->x + kall)
    {
       y = cub->y;
		while (y != cub->y  + kall)
		{
			my_mlx_pixel_put(x, y, 0xFFFFFF, cub, cub->img_addr);
			(y)++;
		}
		(x)++;
    }
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
    return (0);
}

void free_one_list(t_map **map)
{
	t_map *tmp;

	tmp = *map;
	*map = (*map)->next;
	free(tmp->content);
	free(tmp);
}

int main(int argc, char **argv)
{
	int i;
	t_cub *cub;
	t_map *map;
	int tmp;
	int sum;
	int valid;

    cub = malloc(sizeof(t_cub));
	map = 0;
	i = 0;
	zeroing(cub);
	if (argc == 2)
	{
		int k;

		sum = 0;
		kall = 25;
 		kall_2 = 0;
    	cub->x = 100;
    	cub->y = 100;
		cub->mlx = mlx_init();
		cub->fd = open(argv[1], O_RDONLY);
		while(get_next_line(cub->fd, &cub->line) == 1)
		{
			if (sum < 8)
			{
				valid = parser_gnl(cub, cub->line);
				if (valid == -1)
				{
					printf("Error valid\n");
					exit(1);
				}
				else	
					sum = valid + sum;
				// printf("%d\n", sum);
			}
			else
			{
				valid = pars_map(&map, cub->line);
				if (valid == -1)
				{
					printf("Error valid\n");
					exit(1);
				}
			}
			free(cub->line);
		}
		valid = pars_map(&map, cub->line);
		free(cub->line);
		tmp = ft_lstsize(map);
		cub->my_map = malloc(sizeof(char *) * (tmp + 1));
		cub->my_map[tmp] = 0;
		int tmp_2;
		tmp_2 = tmp;
		tmp = 0;
		while(tmp != tmp_2)
		{
			cub->my_map[tmp] = ft_strdup(map->content);
			free_one_list(&map);
			tmp++;
		}
		tmp = 0;
			printf("%d\n", tmp_2);
		while (tmp != tmp_2)
		{
			i = 0;
			// printf("OK\n");
			while (cub->my_map[tmp][i] != '\0')
			{
				if (cub->my_map[tmp][i] == '1')
					i++;
				if (cub->my_map[tmp][i] == '0')
				{
					// printf("OK!\n");
					valid = pars_nul(cub, tmp, i, tmp_2);
					i++;
				}
			}
			tmp++;
		}
		if (valid == 1)
			printf("OKi\n");
		// while(cub->my_map[tmp] != 0)
		// {
		// 	printf("%s\n", cub->my_map[tmp]);
		// 	tmp++;
		// }
		// printf("%d\n", tmp);
    	cub->mlx_win = mlx_new_window(cub->mlx, cub->width, cub->height, "cub3D");
    	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
    	cub->img_addr = mlx_get_data_addr(cub->img, &(cub->bpp), &(cub->size_line), &k);
    	mlx_hook(cub->mlx_win, 2, 1L << 0, key_press, cub);
    	mlx_hook(cub->mlx_win, 3, 1L << 1, key_wringing_out, cub);
    	mlx_hook(cub->mlx_win, 17, 1L << 17, exita, cub);
    	mlx_loop_hook(cub->mlx, do_some_shit, cub);
    	mlx_loop(cub->mlx);
		close(cub->fd);
	}
	else if (argc == 1)
	{
    	int k;
    	
 		kall = 25;
 		kall_2 = 0;
    	cub->x = 100;
    	cub->y = 100;
    	cub->mlx = mlx_init();
    	cub->mlx_win = mlx_new_window(cub->mlx, 2560, 1395, "cub3D");
    	cub->img = mlx_new_image(cub->mlx, 2560, 1395);
    	cub->img_addr = mlx_get_data_addr(cub->img, &(cub->bpp), &(cub->size_line), &k);
    	mlx_hook(cub->mlx_win, 2, 1L << 0, key_press, cub);
    	mlx_hook(cub->mlx_win, 3, 1L << 1, key_wringing_out, cub);
    	mlx_hook(cub->mlx_win, 17, 1L << 17, exita, cub);
    	mlx_loop_hook(cub->mlx, do_some_shit, cub);
		printf("%d %d %d %d\n", cub->x, cub->y, cub->width, cub->height);
    	mlx_loop(cub->mlx);
	}
	return (0);
}
