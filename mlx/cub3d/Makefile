# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroland <rroland@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 14:58:27 by rroland           #+#    #+#              #
#    Updated: 2021/03/19 15:46:55 by rroland          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror -I -Imlx 

SOURCE = test.c get_next_line.c dop_func.c parser_gnl.c pars_rfc.c \
parser_map.c

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