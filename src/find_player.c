//
// Created by Ксения on 07.07.2022.
//

#include "../includes/cub3d.h"

static void	write_player_data(t_all *s_all, int x, int y, char dir)
{
	s_all->plr.x = (double)(x + 0.5);
	s_all->plr.y = (double)(y + 0.5);
	if (dir == 'N')
		s_all->plr.dir = 3 * M_PI_2;
	else if (dir == 'E')
		s_all->plr.dir = 2 * M_PI;
	else if (dir == 'S')
		s_all->plr.dir = M_PI_2;
	else if (dir == 'W')
		s_all->plr.dir = M_PI;
	else
		s_all->plr.dir = 3 * M_PI_2;
}

void	find_player(t_all *s_all)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (s_all->map[++i])
	{
		j = 0;
		while (s_all->map[i][j])
		{
			if (s_all->map[i][j] == 'N' || s_all->map[i][j] == 'S'
				|| s_all->map[i][j] == 'E' || s_all->map[i][j] == 'W')
			{
				count++;
				write_player_data(s_all, j, i, s_all->map[i][j]);
				s_all->map[i][j] = '0';
			}
			j++;
		}
	}
	if (count == 0)
		ft_error("Error: Player not found");
	if (count > 1)
		ft_error("Error: More than 1 player in map");
}
