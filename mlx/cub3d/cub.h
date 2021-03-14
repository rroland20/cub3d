/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:27:43 by rroland           #+#    #+#             */
/*   Updated: 2021/03/14 19:09:12 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_cub
{
    void		*mlx;
    void		*mlx_win;
    void		*img;
	char		*line;
	int			fd;
	int			size_line;
	char		*img_addr;
    int			bpp;
    int			x;
    int			y;
    int         width;
    int         height;
	int			f_red;
	int			f_green;
	int			f_blue;
	int			c_red;
	int			c_green;
	int			c_blue;
}               t_cub;

int		get_next_line(int fd, char **line);
int		key_hook(int keycode, t_cub *cub);
int		do_some_shit(t_cub *cub);
int		key_press(int key, t_cub *cub);
int		key_wringing_out(int key, t_cub *cub);
int		exita(int k);
void	my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub, char *img_addr);
int		k(char *str, int num);
int		read_in(int fd, char **rec, char **line);
char	*recording(char *buff);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *c);
int		ft_atoi(const char *str, int *i);
int		pars_resolution(t_cub *cub, char *line, int i);
int		parser_gnl(t_cub *cub, char *line);
int		pars_floor(t_cub *cub, char *line, int i);
int		pars_ceilling(t_cub *cub, char *line, int i);
void	skip_spaces(char *line, int *i);
void	zeroing(t_cub *cub);
void	check_pars(int value, int *valid, char *line, int *i);
int		pars_north(t_cub *cub, char *line, int i);

# endif