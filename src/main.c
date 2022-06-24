#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	int		i;
	t_all	s_all;

//	int fd;
//	i = 0
	if (argc == 2) {
		while (1) {
			parsing(argv[1], &s_all);
			exit(0);
		}
	}
	return 0;
}
