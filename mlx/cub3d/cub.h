/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:27:43 by rroland           #+#    #+#             */
/*   Updated: 2021/04/14 14:10:32 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define RIGHT 124
# define LEFT 123
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_map
{
	struct s_map	*next;
	char			*content;
}					t_map;

typedef struct s_color_fc
{
	int				red;
	int				blue;
	int				green;
}					t_color_fc;

typedef struct s_run
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				left;
	int				right;
}					t_run;

typedef struct s_textures
{
	char			*tex;
	char			*addr;
	int				width;
	int				height;
	void			*tex_img;
	int				size_line;
}					t_textures;

typedef struct s_cub
{
	double			x;
	double			y;
	double			c;
	t_textures		no;
	t_textures		so;
	t_textures		we;
	t_textures		ea;
	int				fd;
	t_run			run;
	double			my_cos;
	double			my_sin;
	char			player;
	int				bpp;
	void			*mlx;
	void			*img;
	t_color_fc		ceil;
	double			angle;
	char			*line;
	double			x_end;
	double			y_end;
	double			hitxy;
	t_color_fc		floor;
	int				width;
	int				height;
	t_textures		sprite;
	double			*dist_to_wall;
	void			*mlx_win;
	char			**my_map;
	int				size_line;
	char			*img_addr;
	int				color_ceil;
	int				color_floor;
	int				max_map_size;
	int				check_double;
	int				count_sprite;
	double			*count_x;
	double			*count_y;
	double			*dist_spr;
	double			x_sprite;
	double			y_sprite;
	double			width_spr;
	double			coll_spr;
	int				save_bmp;
}					t_cub;

int					exita(t_cub *cub);
void				read_map(t_cub *cub);
void				mlx_func(t_cub *cub);
void				zeroing(t_cub *cub);
void				key_run(t_cub *cub);
double				norm_dir(double dir);
int					k(char *str, int num);
int					rendering(t_cub *cub);
int					ft_lstsize(t_map *lst);
char				*recording(char *buff);
void				error_output(int code);
void				make_screen(t_cub *cub);
void				error_output2(int code);
t_map				*ft_lstlast(t_map *lst);
void				ft_putstr(const char *s);
size_t				ft_strlen(const char *c);
int					pars_texture(t_cub *cub);
void				pars_texture1(t_cub *cub);
t_map				*ft_lstnew(char *content);
void				free_one_list(t_map **map);
char				*ft_strdup(const char *str);
int					key_press(int key, t_cub *cub);
void				draw_sprite(t_cub *cub, int j);
void				skip_spaces(char *line, int *i);
void				locating_the_player(t_cub *cub);
int					ft_atoi(const char *str, int *i);
void				sort_distance(t_cub *cub, int j);
void				read_file(t_cub *cub, t_map *map);
int					get_next_line(int fd, char **line);
int					parser_gnl(t_cub *cub, char *line);
char				*ft_strjoin_map(char *str, int num);
int					pars_nul(t_cub *cub, int tmp, int i);
int					key_wringing_out(int key, t_cub *cub);
int					check_wall(t_cub *cub, int tmp, int i);
void				ft_lstadd_back(t_map **lst, t_map *new);
void				dop_to_while(t_cub *cub, int tmp, int i);
int					pars_nswe(char **tex, char *line, int i);
int					read_in(int fd, char **rec, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
int					pars_fc(t_color_fc *col, char *line, int i);
int					pars_map(t_cub *cub, t_map **map, char *line);
int					pars_resolution(t_cub *cub, char *line, int i);
int					pars_nul1(t_cub *cub, int valid, int tmp, int i);
void				draw_sprite_1(t_cub *cub, int i, int size, int j);
t_textures			side_of_the_world(t_cub *cub, double dir, double c);
void				check_pars(int value, int *valid, char *line, int *i);
void				draw_wall(t_cub *cub, int x, double dir, t_textures tex);
unsigned int		sprite_color(t_cub *cub, t_textures tex, double y,
						double x);
void				my_mlx_pixel_put(int x, int y,
						unsigned int color, t_cub *cub);

#endif