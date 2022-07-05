//
// Created by Romaine Senelle on 7/5/22.
//

#include "../includes/cub3d.h"

int	check_surround(char **map, int i, int j)
{
	if (map[i][j] )
}

int	check_map_borders(t_all *s_all)
{
	int		i;
	int		j;
	size_t	len;

	while (1)
	{
		i = 0;
		if (!is_map_border(s_all->map[0]) || !is_map_border(s_all->map[s_all->map_heigth - 1]))
			ft_error("Wrong borders 0");
		while (i < s_all->map_heigth - 1)
		{

			len = ft_strlen(s_all->map[i]);
			j = 0;
			while(j < len - 1)
			{
				if (s_all->map[i][j] == '0')
					check_surround(s_all->map, i, j);
				j++;
			}
			i++;
		}
		exit(0);
	}
}
