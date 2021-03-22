/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:08:49 by rroland           #+#    #+#             */
/*   Updated: 2021/03/22 19:19:40 by rroland          ###   ########.fr       */
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

char *ft_strjoin_map(char *str, int num)
{
	char *str_new;

	while (num != 0)
	{
		str_new = ft_strjoin(str, " ");
		if (str)
			free(str);
		str = str_new;
		num--;
	}
	return (str_new);
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
			}
			else
			{
				valid = pars_map(cub, &map, cub->line);
				if (valid == -1)
				{
					printf("Error valid\n");
					exit(1);
				}
			}
			free(cub->line);
		}
		valid = pars_map(cub, &map, cub->line);
		free(cub->line);
		tmp = ft_lstsize(map);
		sum = tmp;
		cub->my_map = malloc(sizeof(char *) * (tmp + 1));
		cub->my_map[tmp] = 0;
		tmp = 0;
		int size_len;
		while(tmp != sum)
		{ 
			size_len = ft_strlen(map->content);
			if (size_len < cub->max_map_size)
				cub->my_map[tmp] = ft_strjoin_map(ft_strdup(map->content), cub->max_map_size - size_len);
			else
				cub->my_map[tmp] = ft_strdup(map->content);
			free_one_list(&map);
			tmp++;
		}
		tmp = 0;
		cub->check_double = 0;
		while (cub->my_map[tmp] != 0)
		{
			i = -1;
			while (cub->my_map[tmp][++i] != '\0')
				if (cub->my_map[tmp][i] == '0' || cub->my_map[tmp][i] == 'N' ||
				cub->my_map[tmp][i] == 'S' || cub->my_map[tmp][i] == 'W' ||
				cub->my_map[tmp][i] == 'E' || cub->my_map[tmp][i] == '2')
				{
					if (cub->my_map[tmp][i] == 'N' || cub->my_map[tmp][i] == 'S' ||
					cub->my_map[tmp][i] == 'W' || cub->my_map[tmp][i] == 'E')
						cub->check_double += 1;
					if ((pars_nul(cub, tmp, i)) != 4)
					{
						printf("steni net\n");
						exit(1);
					}
				}
			tmp++;
		}
		if (cub->check_double != 1)
		{
			printf("MNOGO IGROKOV\n");
			exit(1);
		}
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
	return (0);
}
