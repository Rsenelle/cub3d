#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	s_all;

	if (argc == 2)
	{
		init_struct(&s_all);
		while (1)
		{
			parsing(argv[1], &s_all);
			exit (0);
		}
	}
	else
		ft_error("Too many arguments");
	return (0);
}
