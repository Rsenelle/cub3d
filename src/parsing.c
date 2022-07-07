//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

void parsing(char *map_name, t_all *s_all)
{
	int	fd;

	fd = check_map_file(map_name);
	set_params(s_all, fd);
	make_map_array(s_all, map_name);
//	printarray(s_all->map);
	check_map_borders(s_all);
	find_player(s_all);
}

int	check_map_file(char *map_name)
{
	int	fd;

	if ((ft_strlen(map_name) < 4) || ft_strncmp(map_name + (ft_strlen(map_name) - 4), ".cub", 4))
		ft_error("Invalid map file");
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	if (read(fd, NULL, 0) < 0)
		ft_error(NULL);
	return (fd);
}
