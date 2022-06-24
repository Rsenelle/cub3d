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