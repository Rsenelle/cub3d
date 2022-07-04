//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

//int	is_map_beginning(char *s)
//{
//	if (s == 0 || *s == 0)
//		return (0);
//	while(*s && *s != '\n')
//	{
//		if (*s != ' ' && *s != '1' && *s != '\t')
//			return (0);
//		s++;
//	}
//	return (1);
//}

void	printlist(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
		ft_error("NO LIST");
	while(lst)
	{
		printf("%d %s\n", i++, lst->str);
		lst=lst->next;
	}
}

void	printarray(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

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

int	make_map_array(t_list *map_list, t_all *s_all)
{
	size_t	i;

	s_all->heigth = ft_lstsize(map_list);
	s_all->map = malloc(sizeof(char *) * (s_all->heigth + 1));
	if (!s_all->map)
		ft_error(NULL);
	i = 0;
	while (i < s_all->heigth)
	{
		s_all->map[i] = map_list->str;
		map_list = map_list->next;
		i++;
	}
	ft_lstclear(&map_list, free);
	s_all->map[i] = NULL;
}

int main (int argc, char **argv)
{
	t_list	*sample;
	t_all	s_all;

	sample = make_map_in_lists(argv[1]);
	printlist(sample);
//	printf("\n");
//	make_map_array(sample, &s_all);
//	printarray(s_all.map);
	return 0;
}

