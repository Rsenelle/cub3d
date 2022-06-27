//
// Created by Romaine Senelle on 6/25/22.
//

#include "../includes/cub3d.h"

void	making_map(char *map_name, t_all *s_all, int fd)
{
	size_t	i;

	i = 0;
	s_all->heigth = count_strings_for_map(fd);
	close(fd);
	s_all->map = malloc(sizeof(char *) * (s_all->heigth + 1));
	if (!s_all->map)
		ft_error(NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	while (i < s_all->heigth)
	{
		s_all->map[i] = get_next_line(fd);
		if (s_all->map[i] == NULL)
			ft_error("Invalid map");
		i++;
	}
	s_all->map[i] = NULL;
}

int	count_strings_for_map(int fd)
{
	int		amount;
	char	*s;

	amount = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free(s);
		amount++;
	}
	return (amount);
}
