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
		free (s);
	}
	while (s)
	{
		if (!is_map(s))
			ft_error("Wrong map");
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(s)));
		free(s);
		s = get_next_line(fd);
	}
	if (!s && !map)
		ft_error("No map");
	free(s);
	close(fd);
	return(map);
}

void	make_map_array(t_all *s_all, char *map_name)
{
	size_t	i;
	t_list	*map_list;
	t_list	*head;

	map_list = make_map_in_lists(map_name);
	head = map_list;
	s_all->map_heigth = ft_lstsize(map_list);
	s_all->map = (char**)malloc(sizeof(char *) * (s_all->map_heigth + 1));
	if (!s_all->map)
		ft_error(NULL);
	i = 0;
	while (i < s_all->map_heigth)
	{
		s_all->map[i] = ft_strdup(map_list->str);
		map_list = map_list->next;
		i++;
	}
	ft_lstclear(&head, free);
	s_all->map[i] = NULL;
}

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

int	is_map_beginning(char *s)
{
	if (s == 0 || *s == 0)
		return (0);
	while(*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

