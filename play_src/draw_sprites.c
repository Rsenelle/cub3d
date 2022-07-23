#include "../include/cubbster.h"

static
void	get_sprite_info(t_state *state, t_sprite *sprite)
{
	double	x_sprite;
	double	y_sprite;

	x_sprite = ((double)sprite->x_block + 0.5) * BLOCK_SIZE;
	y_sprite = ((double)sprite->y_block + 0.5) * BLOCK_SIZE;
	sprite->center_ray_nbr = SCREEN_DIST * tan(atan((x_sprite - state->x_pos)
		/ (state->y_pos - y_sprite)) - state->angle * RAD) + START_RAY_NUM;
	sprite->distance = sqrt(pow(x_sprite - state->x_pos, 2)
		+ pow(y_sprite - state->y_pos, 2)) * cos(atan((sprite->center_ray_nbr
		- START_RAY_NUM) / SCREEN_DIST));
}

#define SPRITE_SIZE 50

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

void	draw_one_sprite(t_image *img, t_sprite *sprite, t_image *texture,  int half_sprite_height, double texture_step)
{
	int	x_texture;
	int	y_texture;
	int	color;
	int	x;
	int	y;

	x = - half_sprite_height;
	while (x < half_sprite_height)
	{
		x_texture = texture->width / 2 + texture_step * x;
		y = - half_sprite_height;
		if (sprite->center_ray_nbr + x >= 0 && sprite->center_ray_nbr + x < WIN_WIDTH)
		{
			while (y < half_sprite_height)
			{
				if (WIN_HEIGHT / 2 + y >= 0 && WIN_HEIGHT / 2 + y < WIN_HEIGHT)
				{
					y_texture = texture->height / 2 + texture_step * y;
					color = get_color(texture, x_texture, y_texture);
					if (!(color >> 24))
						put_pixel(img, sprite->center_ray_nbr + x, WIN_HEIGHT / 2 + y, color);
				}
				y++;
			}
		}
		x++;
	}
}

static
t_image	*choose_sprite_texture(t_textures *textures)
{
	static int	time;

	if (time == 240)
		time = 0;
	else
		time ++;
	if (time < 40)
		return (&textures->sprite0);
	else if (time < 80)
		return (&textures->sprite1);
	else if (time < 120)
		return (&textures->sprite2);
	else if (time < 160)
		return (&textures->sprite3);
	else if (time < 200)
		return (&textures->sprite4);
	else
		return (&textures->sprite5);
}

void	draw_sprites(t_image *img, t_state *state)
{
	t_list		*elem;
	int			half_sprite_height;
	double		texture_step;
	t_image		*texture;
	t_sprite	*sprite;

	elem = state->visible_sprites;
	while (elem)
	{
		get_sprite_info(state, elem->str);
		elem = elem->next;
	}
	elem = state->visible_sprites;
	while (elem)
	{
		sprite = elem->str;
		half_sprite_height = round((double)SPRITE_SIZE * 277.128129 / sprite->distance);
		texture = choose_sprite_texture(&state->textures);
		texture_step = min(texture->height, texture->width) * 0.5 / (double)half_sprite_height;
		draw_one_sprite(img, sprite, texture, half_sprite_height, texture_step);
		elem = elem->next;
	}
}
