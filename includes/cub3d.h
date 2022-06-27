//
// Created by Romaine Senelle on 6/24/22.
//

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_all
{
	char		**map;
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
	int			floor;
	int 		ceilling;
	size_t		p_i;
	size_t		p_j;
}			t_all;

void	init_struct(t_all *s_all);
void	parsing(char *map_name, t_all *s_all);
int		ft_error(char *str);
int		check_map_file(char *map_name);
void	making_map(char *map_name, t_all *slg, int fd);
int		is_map_beginning(char *s);
void	check_param(char *s, t_all *s_all);
char	*skip_space(char *s);
void	set_params(t_all *s_all, int fd);
int		create_trgb(int t, int r, int g, int b);
int		consist_of_num_or_coma(char *s);
int		parse_color(char *color);
int		count_strings_for_map(int fd);



#endif