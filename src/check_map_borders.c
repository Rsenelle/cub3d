//
// Created by Romaine Senelle on 7/5/22.
//

#include "../includes/cub3d.h"

static int	line_has_zero_borders(char *s)
{
	char	*temp;

	temp = ft_strdup(skip_space(s));
	if (temp[0] == '1' && temp[ft_strlen(temp) - 1] == '1')
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

static int	spaces_around_zero(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
	map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || \
	map[i - 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ' || \
	map[i + 1][j - 1] == ' ' || map[i + 1][j + 1] == ' ')
		return (1);
	if (!map[i][j - 1] || !map[i][j + 1] ||
		!map[i - 1][j] || !map[i + 1][j] ||
		!map[i - 1][j - 1] || !map[i - 1][j + 1] ||
		!map[i + 1][j - 1] || !map[i + 1][j + 1])
		return (1);
	return (0);
}

void	check_map_borders(t_all *s_all)
{
	int		i;
	int		j;
	size_t	len;

	if (!is_map_border(s_all->map[0]) || \
	!is_map_border(s_all->map[s_all->map_heigth - 1]))
		ft_error("Wrong borders");
	i = 1;
	while (i < s_all->map_heigth - 1)
	{
		if (line_has_zero_borders(s_all->map[i]))
			ft_error("Wrong borders");
		len = ft_strlen(s_all->map[i]);
		j = 0;
		while (j < len - 1)
		{
			if (s_all->map[i][j] == '0' || s_all->map[i][j] == 'N' || \
					s_all->map[i][j] == 'W' || s_all->map[i][j] == 'E' || \
					s_all->map[i][j] == 'S')
				if (spaces_around_zero(s_all->map, i, j))
					ft_error("Wrong borders");
			j++;
		}
		i++;
	}
}
