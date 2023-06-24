
NAME =	fdf

CC =	gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	src/

OBJ =	$(SRC:.c=.o)

LIB =	lib/libftprintf.a
	minilibx-linux/libmlx_Linux.a

$(NAME): $(OBJ)
	cd minilibx-linux && make
	$(CC) $(CFLAGS) $(LIB) $(OBJ ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clear
	cd minilibx-linux && make clean
	rm -f $(NAME)

re : fclean all
