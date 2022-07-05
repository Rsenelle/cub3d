cmake_minimum_required(VERSION 3.21)
project(Cube3D C)

set(CMAKE_C_STANDARD 99)

add_executable(Cube3D src/main.c src/utils.c includes/cub3d.h src/parsing.c
        src/init_struct.c
        src/making_map.c
        src/set_params.c
        src/check_map_borders.c
        libft/ft_atoi.c
        libft/ft_lstadd_back.c
        libft/ft_lstclear.c
        libft/ft_lstnew.c
        libft/ft_lstsize.c
        libft/ft_putendl_fd.c
        libft/ft_strdup.c
        libft/ft_strlen.c
        libft/ft_strncmp.c
        libft/ft_lstdelone.c
        libft/ft_lstlast.c
        src/get_next_line.c
        src/get_next_line_utils.c
        minilibx/mlx_new_image.m
        minilibx/mlx_xpm.c
        libmlx.a
        )
