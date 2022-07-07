/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:15 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:55 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_all *s_all)
{
	s_all->map = NULL;
	s_all->map_heigth = 0;
	s_all->map_width = 0;
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
	s_all->mlx = mlx_init();
	s_all->plr.x = 0;
	s_all->plr.y = 0;
	s_all->plr.dir = 0;
}
