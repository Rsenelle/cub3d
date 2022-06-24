NAME		=	cub3D

SRCS_F		=	main.c	get_next_line.c	get_next_line_utils.c

SRCS_D		=	src/

INCLUDE		=	-I./includes/ -I./libft/

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(addprefix $(SRCS_D),$(SRCS_F))

LIBFT		=	./libft/libft.a

$(NAME)		:	$(OBJS)
				@echo '✨ ✨ ✨ \n'`$(MAKE) -C $(dir $(LIBFT))`''
				@echo './cub3D was created!'`$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME)`''

all		:	$(NAME)

%.o		:	%.c
			@echo 'Some magic 🔮 '`$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@`''

clean	:
			@echo 'Washing away this shit 🧹 🧹 🧹 '`$(MAKE) clean -C $(dir $(LIBFT))`''
			@echo 'Cleaned all except file name!'`rm -rf $(OBJS) $(OBJS:.o=.d)`''

fclean	:	clean
			@echo 'Cleaning file name... \n'`$(MAKE) fclean -C $(dir $(LIBFT))`''
			@echo 'Cleaned all ♺ '`rm -rf $(NAME)`''

re		:	fclean all

.PHONY	:	all clean fclean re bonus