//
// Created by Romaine Senelle on 6/25/22.
//

#include "../includes/cub3d.h"

void	init_struct(t_all *s_all)
{
	s_all->map = NULL;
	s_all->heigth = 0;
	s_all->width = 0;
	s_all->n = 0;
	s_all->s = 0;
	s_all->e = 0;
	s_all->w = 0;
	s_all->no = NULL;
	s_all->we = NULL;
	s_all->ea = NULL;
	s_all->so = NULL;
	s_all->floor = 0;
	s_all->ceilling = 0;
	s_all->p_i = 0;
	s_all->p_j = 0;
}
