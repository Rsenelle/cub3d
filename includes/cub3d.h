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

typedef struct	s_image {
	void	*mlx;
	void	*img;
	char	*addr;
	int		*heigth;
	int		*width;
	int		*bits_per_pixel;
	int		*line_length;
	int		*endian;
}				t_image;

typedef struct s_all
{
	char		**map;
	size_t		map_heigth;
	size_t		map_width;
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
	t_image		n_img;
	t_image		s_img;
	t_image		e_img;
	t_image		w_img;
}			t_all;


void	init_struct(t_all *s_all);
void	parsing(char *map_name, t_all *s_all);
int		check_map_file(char *map_name);

////params_parse
void	choose_param(char *s, t_all *s_all);
void	set_params(t_all *s_all, int fd);
int		create_trgb(int t, int r, int g, int b);
int		parse_color(char *color);
void		get_textures(t_all *s_all);

////map_parse
t_list	*make_map_in_lists(char *map_name);
void	make_map_array(t_all *s_all, char *map_name);
int		is_map(char *s);
int		is_map_beginning(char *s);

////utils
void	printarray(char **map);
void	printlist(t_list *lst);
int		consist_of_num_or_coma(char *s);
char	*skip_space(char *s);
int		ft_error(char *str);



#endif