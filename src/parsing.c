//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

void parsing(char *map_name, t_all *s_all)
{
	int	fd;

	fd = check_map_file(map_name);
	set_params(map_name, s_all, fd);
	making_map(map_name, s_all, fd);
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

void	making_map(char *map_name, t_all *slg, int fd)
{
	size_t	i;

	i = 0;
	slg->heigth = count_strings(fd);
	close(fd);
	slg->map = malloc(sizeof(char *) * (slg->heigth + 1));
	if (!slg->map)
		ft_error(NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	while (i < slg->heigth)
	{
		slg->map[i] = get_next_line(fd);
		if (slg->map[i] == NULL)
			ft_error("Invalid map");
		i++;
	}
	slg->map[i] = NULL;
}

void	set_params(char *map_name, t_all *slg, int fd)
{

	while(is_map_beginning())
}

int	is_map_beginning(char *s)
{
	if (s == 0 || *s == 0)
		return (1);
	while(*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1')
			return (1);
		s++;
	}
	return (0);
}