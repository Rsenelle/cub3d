#include "../include/cubbster.h"

static
t_image	*choose_wall_texture(t_textures *textures, t_ray *ray)
{
	if (ray->is_vertical)
	{
		if (ray->sin < 0)
			return (&(textures->west));
		return (&(textures->east));
	}
	if (ray->cos < 0)
		return (&(textures->south));
	return (&(textures->north));
}

static
int	count_x_wall_texture(t_image *texture, t_ray *ray)
{
	double	x_map;

	if (ray->is_vertical)
	{
		x_map = fmod(ray->y_bar, BLOCK_SIZE);
		if (ray->sin < 0)
			x_map = (double)BLOCK_SIZE - x_map;
		return (x_map * (double)texture->width / (double)BLOCK_SIZE);
	}
	x_map = fmod(ray->x_bar, BLOCK_SIZE);
	if (ray->cos < 0)
		x_map = (double)BLOCK_SIZE - x_map;
	return (x_map * (double)texture->width / (double)BLOCK_SIZE);
}

void	delete_outdated_sprites(t_list **sprites)
{
	t_list	*prev;
	t_list	*elem;

	prev = NULL;
	elem = *sprites;
	while (elem)
	{
		if (((t_sprite *)elem->str)->to_del)
		{
			if (prev)
			{
				prev->next = elem->next;
				free(elem);
				elem = prev->next;
			}
			else
			{
				*sprites = elem->next;
				free(elem);
				elem = *sprites;
			}
		}
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}

static
t_image	*choose_sprite_texture(t_textures *textures)
{
	static int	time;

	if (time == 9600)
		time = 0;
	else
		time ++;
	if (time < 1600)
		return (&textures->sprite0);
	else if (time < 3200)
		return (&textures->sprite1);
	else if (time < 4800)
		return (&textures->sprite2);
	else if (time < 6400)
		return (&textures->sprite3);
	else if (time < 8000)
		return (&textures->sprite4);
	else
		return (&textures->sprite5);
}

//int	count_x_sprite_texture(t_image *texture, t_ray *ray, t_sprite *sprite)
//{
//	int btw;
//	int x;
//
//	btw = (ray->nbr - sprite->center_ray_nbr);
//	if (abs(btw) < sprite->half_sprite_height)
//		return (-1);
//	x = btw * texture->width * 0.5 / sprite->half_sprite_height;
//	return (texture->width * 0.5 + x);
//}

int	count_x_sprite_texture(t_image *texture, t_ray *ray, t_sprite *sprite)
{
	int btw;
	int x;

	btw = (ray->nbr - sprite->center_ray_nbr);
	if (abs(btw) > sprite->half_sprite_height)
		return (-1);
	x = btw * texture->width * 0.5 / (sprite->half_sprite_height);
	return (texture->width * 0.5 + x);
}

void	cast_one_ray(t_image *img, t_state *state, int ray_nbr)
{
	t_ray	ray;
	int		x_texture;
	t_image	*texture;
	t_list	*elem;

	ray.nbr = ray_nbr;
	set_ray_info(state, &ray);
	texture = choose_wall_texture(&state->textures, &ray);
	x_texture = count_x_wall_texture(texture, &ray);
	put_wall_slice(img, texture, &ray, x_texture);
	delete_outdated_sprites(&state->visible_sprites);
	texture = choose_sprite_texture(&state->textures);
	elem = state->visible_sprites;
	while (elem)
	{
		x_texture = count_x_sprite_texture(texture, &ray, elem->str);
		if (x_texture >= 0)
			put_sprite_slice(img, texture, &ray, x_texture, ((t_sprite *)elem->str)->half_sprite_height);
		elem = elem->next;
	}
}

void	cast_rays(t_image *img, t_state *state)
{
	int	ray_nbr;

	ray_nbr = 0;
	while (ray_nbr < WIN_WIDTH)
		cast_one_ray(img, state, ray_nbr++);
}
