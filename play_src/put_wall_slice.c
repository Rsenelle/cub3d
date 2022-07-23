#include "../include/cubbster.h"
#include <stdio.h>

void	put_wall_slice(t_image *img, t_image *texture, t_ray *ray, int x_texture)
{
	int		color;
	ssize_t	y;
	int		y_texture;
	int		half_wall_height;
	double	texture_step;

	half_wall_height = round((double)BLOCK_SIZE * 277.128129 / ray->distance);
	texture_step = (double)(texture->height / 2) / (double)half_wall_height;
	y = 0;
	while (y < half_wall_height && y <= WIN_HEIGHT / 2)
	{
		y_texture = (texture->height / 2) - y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		if (ray->is_vertical)
			color = (color >> 1) & 8355711;
		put_pixel(img, ray->nbr, WIN_HEIGHT / 2 - y, color);
		y_texture = (texture->height / 2) + y * texture_step;
		color = get_color(texture, x_texture, y_texture);
		if (ray->is_vertical)
			color = (color >> 1) & 8355711;
		put_pixel(img, ray->nbr, WIN_HEIGHT / 2 + y, color);
		y++;
	}
}
