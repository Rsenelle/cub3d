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

