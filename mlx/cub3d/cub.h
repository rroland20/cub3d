/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:27:43 by rroland           #+#    #+#             */
/*   Updated: 2021/03/20 17:19:05 by rroland          ###   ########.fr       */
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

typedef struct		s_map
{
	char			*content;
	struct s_map	*next;
}					t_map;

typedef struct	s_color_fc
{
	int			red;
	int			green;
	int			blue;
}				t_color_fc;

typedef struct s_texture
{
	char		*tex;
}				t_texture;


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
	char		**my_map;
	t_color_fc	floor;
	t_color_fc	ceil;
	t_texture	tx_no;
	t_texture	tx_so;
	t_texture	tx_we;
	t_texture	tx_ea;
	t_texture	tx_sprite;
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
int		pars_fc(t_color_fc *col, char *line, int i);
void	skip_spaces(char *line, int *i);
void	zeroing(t_cub *cub);
void	check_pars(int value, int *valid, char *line, int *i);
int		pars_nswe(t_texture *tx, char *line, int i);
int 	pars_map(t_map **map, char *line);
t_map	*ft_lstnew(char *content);
void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
int		ft_lstsize(t_map *lst);
void	free_one_list(t_map **map);
int		pars_nul(t_cub *cub, int tmp, int i, int tmp_2);

# endif