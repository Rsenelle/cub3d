#include "../include/cubbster.h"

int	get_color(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	return(*(int *)dst);
}
