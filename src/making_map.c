//
// Created by Romaine Senelle on 6/25/22.
//

#include "../includes/cub3d.h"

t_list	*make_map_in_lists(char *map_name, int fd)
{
	t_list	*map;
	char	*s;

	map = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s || is_map(s))
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
	return (map);
}

void	make_map_array(t_all *s_all, char *map_name)
{
	size_t	i;
	t_list	*map_list;
	t_list	*head;
	int		fd;

	fd = check_fd(map_name);
	map_list = make_map_in_lists(map_name, fd);
	head = map_list;
	s_all->map_heigth = ft_lstsize(map_list);
	s_all->map = (char **)malloc(sizeof(char *) * (s_all->map_heigth + 1));
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
