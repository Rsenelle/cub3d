//
// Created by Romaine Senelle on 6/25/22.
//

#include "../includes/cub3d.h"

t_list	*make_map_in_lists(char *map_name)
{
	t_list	*map;
	char	*s;
	int 	fd;

	map = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	while (1)
	{
		s = get_next_line(fd);
		if (!s || is_map_beginning(s))
			break ;
	}
	while (s)
	{
		if (!is_map(s))
			ft_error("Wrong map");
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(s)));
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return(map);
}

//	s_all->heigth = count_strings_for_map(fd);
//	close(fd);
//	s_all->map = malloc(sizeof(char *) * (s_all->heigth + 1));
//	if (!s_all->map)
//		ft_error(NULL);
//	fd = open(map_name, O_RDONLY);
//	if (fd < 0)
//		ft_error(NULL);
//	while (i < s_all->heigth)
//	{
//		s_all->map[i] = get_next_line(fd);
//		if (s_all->map[i] == NULL)
//			ft_error("Invalid map");
//		i++;
//	}
//	s_all->map[i] = NULL;

int	is_map(char *s)
{
	if (s == 0 || *s == 0)
		return (0);
	while(*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1' && *s != '0' && *s != 'N' && \
		*s != 'W' && *s != 'E' && *s != 'S' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
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
