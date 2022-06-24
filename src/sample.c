//
// Created by Romaine Senelle on 6/24/22.
//

#include <stdio.h>

int	is_map_beginning(char *s)
{
	if (s == 0 || *s == 0)
		return (1);
	while(*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1')
			return (1);
		s++;
	}
	return (0);
}

int main ()
{
	char *s;

	s = "";
	printf("result: %d", is_map_beginning(s));
}

