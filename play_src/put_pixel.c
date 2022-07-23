#include "../include/cubbster.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr
			  + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}