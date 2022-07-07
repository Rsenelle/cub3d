# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 14:28:08 by rsenelle          #+#    #+#              #
#    Updated: 2022/07/07 14:29:05 by rsenelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRCS_F		=	main.c	get_next_line.c	get_next_line_utils.c	parsing.c	utils.c\
				init_struct.c	set_params.c	making_map.c	check_map_borders.c\
				find_player.c	parse_utils.c

SRCS_D		=	src/

INCLUDE		=	-I./includes/ -I./libft/ -I./minilibx

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall

OPENGL	=	-framework OpenGL -framework AppKit

MLX		=	./minilibx/libmlx.a

SRCS		=	$(addprefix $(SRCS_D),$(SRCS_F))

LIBFT		=	./libft/libft.a

$(NAME)		:	$(OBJS)
				@echo '✨ ✨ ✨ \n'`$(MAKE) -C $(dir $(LIBFT))`''
				make -C $(dir $(MLX))
				cp $(MLX) .
				@echo './cub3D was created!'`$(CC) $(CFLAGS) $(INCLUDE) $(MLX)  $(LIBFT) $(OBJS) $(OPENGL) -o $(NAME)`''

all		:	$(NAME)

%.o		:	%.c
			@echo 'Some magic 🔮 '`$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@`''

clean	:
			@echo 'Washing away this shit 🧹 🧹 🧹 '`$(MAKE) clean -C $(dir $(LIBFT))`''
			@echo ''`$(MAKE) clean -C $(dir $(MLX))`''
			@echo 'Cleaned all except file name!'`rm -rf $(OBJS) $(OBJS:.o=.d)`''

fclean	:	clean
			@echo 'Cleaning file name... \n'`$(MAKE) fclean -C $(dir $(LIBFT))`''
			@echo 'Cleaned all ♺ '`rm -rf $(NAME) libmlx.a`''

re		:	fclean all

.PHONY	:	all clean fclean re bonus