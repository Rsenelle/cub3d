//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

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

int main ()
{
	char *s;

	s = "220,100,0";
	printf("result: %d", consist_of_num_or_coma(s));
}

