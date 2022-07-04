//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

int	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	if (str)
		ft_putendl_fd(str, 2);
	else
		perror(0);
	exit (-1);
}

char	*skip_space(char *s)
{
	while(*s == ' ' || *s == '\t')
		s++;
	return (s);
}

int	consist_of_num_or_coma(char *s)
{
	size_t coma;

	coma = 0;
	if (s == 0 || *s == 0)
		return (0);
	while (*s) {
		if (*s == ',')
			coma++;
		if ((*s <= '0' || *s >= '9') && *s != ',')
			return (0);
		s++;
	}
	if (coma != 2)
		return (0);
	return (1);
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
