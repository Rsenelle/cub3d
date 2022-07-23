#include "../include/cubbster_errors.h"

void	put_error(char *str)
{
	size_t	len;

	write(2, "Error\n", 6);
	len = ft_strlen(str);
	write(2, str, len);
	write(2, "\n", 1);
	exit(1);
}