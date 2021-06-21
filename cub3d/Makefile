# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alena <alena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 14:58:27 by rroland           #+#    #+#              #
#    Updated: 2021/04/28 22:20:55 by alena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -g -Wall -Wextra -Werror -I ../mlx_linux/


SOURCE = cub3d.c get_next_line.c dop_func.c parser_gnl.c pars_rfc.c \
parser_map.c key.c grafic.c pars_wall.c dop_func2.c key2.c read_file.c \
read_map.c mlx_func.c draw_sprite.c bmp_screen.c zero.c side_of_the_world.c \
draw.c draw_sprite_1.c free_struct.c

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc -g $(OBJECTS) -o $(NAME) -L. ../mlx_linux/libmlx.a -lm -lXext -lX11
%.o:%.c
	@gcc $(FLAGS) -c $(SOURCE)
clean:
	@rm -rf $(OBJECTS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
