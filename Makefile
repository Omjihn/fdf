# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 16:10:49 by gbricot           #+#    #+#              #
#    Updated: 2023/06/28 14:05:11 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c \
	src/ft_init.c \
	src/ft_free_all.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c

OBJ =	$(SRC:.c=.o)

LIB =	lib/libftprintf.a \
	minilibx-linux/libmlx_Linux.a

$(NAME): $(OBJ)
	cd minilibx-linux && make
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	cd minilibx-linux && make clean
	rm -f $(NAME)

re : fclean all
