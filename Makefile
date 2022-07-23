CC		=	cc
NAME	=	cubbster
HEADERS =	include/cubbster.h include/cub3d.h
SRC 	=	$(wildcard play_src/*.c) $(wildcard parse_src/*.c)
OBJ		=	$(SRC:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -Iminilibx/mlx.h -Ilibfl/libft.h -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all