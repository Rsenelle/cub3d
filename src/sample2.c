//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

char	*skip_space(char *s)
{
	while(*s == ' ' || *s == '\t')
		s++;
	return (s);
}

int	is_map(char *s)
{
	if (s == 0 || *s == 0)
		return (0);
	s = skip_space(s);
	if (!*s)
	{
		while(1);
		return (0);
	}

	while(*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1' && *s != '0' && *s != 'N' && \
		*s != 'W' && *s != 'E' && *s != 'S' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}


int main (int argc, char **argv)
{
	char *s;

	s = "         ";
	printf ("result: %d\n", is_map(s));
	return 0;
}

