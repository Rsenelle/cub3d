//
// Created by Romaine Senelle on 6/24/22.
//

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_all
{
	char		**map;
	char		**params;
	size_t		heigth;
	size_t		width;
	size_t		n;
	size_t		s;
	size_t		e;
	size_t		w;
	char		*no;
	char		*we;
	char		*ea;
	char		*so;
	char		*floor;
	char		*ceilling;
	size_t		p_i;
	size_t		p_j;
}			t_all;

void parsing(char *map_name, t_all *s_all);
int	ft_error(char *str);
int	check_map_file(char *map_name);
void	making_map(char *map_name, t_all *slg, int fd);

#endif