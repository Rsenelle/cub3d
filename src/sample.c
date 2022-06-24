//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

int	*parse_color(char *color)
{
	int		res[3];
//	char	*dst;
	int		i;

	i = 0;
	if (!consist_of_num_or_coma(color))
		ft_error("Wrong floor or ceilling color");
	while (i < 3)
	{
		res[i] = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		color++;
		i++;
	}
	printf("%d %d %d\n", res[0], res[1], res[2]);
	return 0;
}

int main ()
{
	char *s;

	s = "220,100,0";
	parse_color(s);
}

