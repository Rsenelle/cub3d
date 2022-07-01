//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

c

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
//		printf("first cycle: %s\n", s);
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

int main (int argc, char **argv)
{
	t_list *sample;

	(void)argc;
	sample = make_map_in_lists(argv[1]);
	printlist(sample);
}

