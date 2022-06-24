//
// Created by Romaine Senelle on 6/24/22.
//

#ifndef CUBE3D_CUB3D_H
#define CUBE3D_CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_slg
{
	char		**map;
	char		**params;
	size_t		heigth;
	size_t		width;
	size_t		p;
	size_t		e;
	size_t		c;
	size_t		p_i;
	size_t		p_j;
	void		*mlx;
	void		*mlx_win;
	void		*field;
	void		*player;
	void		*ex;
	void		*coll;
	void		*wall;
	void		*closed_ex;
	void		*gameover;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			moves;

}


#endif