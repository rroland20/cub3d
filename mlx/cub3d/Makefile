# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroland <rroland@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 14:58:27 by rroland           #+#    #+#              #
#    Updated: 2021/04/12 16:21:53 by rroland          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -g -Wall -Wextra -Werror -I -Imlx 

SOURCE = cub3d.c get_next_line.c dop_func.c parser_gnl.c pars_rfc.c \
parser_map.c key.c grafic.c pars_wall.c dop_func2.c key2.c read_file.c \
read_map.c mlx_func.c

OBJECTS = $(SOURCE:.c=.o)

all:
	@gcc $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(SOURCE) -o $(NAME)
	@rm -rf $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus