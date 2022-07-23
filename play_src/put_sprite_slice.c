#include "../include/cubbster.h"
#include <stdio.h>

void	put_sprite_slice(t_image *img, t_image *texture, t_ray *ray, int x_texture, int half_sprite_height)
{
	int		color;
	ssize_t	y;
	int		y_texture;
	double	texture_step;

	texture_step = (double)(texture->height / 2) / (double)half_sprite_height;
	y = 0;
	while (y < half_sprite_height && y <= WIN_HEIGHT / 2)
	{
		y_texture = (texture->height / 2) - y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		if (!(color >> 24))
			put_pixel(img, ray->nbr, WIN_HEIGHT / 2 - y, color);
		y_texture = (texture->height / 2) + y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		if (!(color >> 24))
			put_pixel(img, ray->nbr, WIN_HEIGHT / 2 + y, color);
		y++;
	}
}

