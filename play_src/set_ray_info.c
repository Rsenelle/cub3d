#include "../include/cubbster.h"

 /*
static
void	check_x_direction(t_state *state, t_ray *x_ray)
{
	x_ray->y_bar = (cos(x_ray->radian) / sin(x_ray->radian)) * (state->x_pos - x_ray->x_bar) + state->y_pos;
	x_ray->x_block = x_ray->x_bar / BLOCK_SIZE - (sin(x_ray->radian) < 0);
	x_ray->y_block = x_ray->y_bar / BLOCK_SIZE;
	if (x_ray->x_block < 0 || x_ray->x_block >= state->map_width
		|| x_ray->y_block < 0 || x_ray->y_block >= state->map_height)
		return ;
	if (state->map[x_ray->y_block][x_ray->x_block] == BLOCK)
		x_ray->distance = sqrt(pow(x_ray->x_bar - state->x_pos, 2) + pow(x_ray->y_bar - state->y_pos, 2));
	if (state->map[x_ray->y_block][x_ray->x_block] == SPRITE)
		add_sprite_info(x_ray, state);
}

static
void	check_y_direction(t_state *state, t_ray *y_ray)
{
	y_ray->x_bar = (sin(y_ray->radian) / cos(y_ray->radian)) * (state->y_pos - y_ray->y_bar) + state->x_pos;
	y_ray->x_block = y_ray->x_bar / BLOCK_SIZE;
	y_ray->y_block = y_ray->y_bar / BLOCK_SIZE - (cos(y_ray->radian) > 0);
	if (y_ray->x_block < 0 || y_ray->x_block >= state->map_width
		|| y_ray->y_block < 0 || y_ray->y_block >= state->map_height)
		return;
	if (state->map[y_ray->y_block][y_ray->x_block] == BLOCK)
		y_ray->distance = sqrt(pow(y_ray->x_bar - state->x_pos, 2) + pow(y_ray->y_bar - state->y_pos, 2));
	if (state->map[y_ray->y_block][y_ray->x_block] == SPRITE)
		add_sprite_info(y_ray, state);
}

static
void	set_x_ray(t_state *state,double ray_radian, t_ray *x_ray)
{
	x_ray->radian = ray_radian;
	x_ray->is_vertical = 1;
	x_ray->distance = -1;
	if (sin(x_ray->radian) == 0)
		return;
	x_ray->x_bar = (int)(state->x_pos / BLOCK_SIZE) * BLOCK_SIZE;
	while (x_ray->distance < 0 && x_ray->x_bar > 0 && x_ray->x_bar < state->map_width * BLOCK_SIZE)
	{
		x_ray->x_bar = x_ray->x_bar + (sin(x_ray->radian) > 0) * BLOCK_SIZE;
		check_x_direction(state, x_ray);
		x_ray->x_bar = x_ray->x_bar - (sin(x_ray->radian) < 0) * BLOCK_SIZE;
	}
}

static
void	set_y_ray(t_state *state, double ray_radian, t_ray *y_ray)
{
	y_ray->radian = ray_radian;
	y_ray->is_vertical = 0;
	y_ray->distance = -1;
	if (cos(y_ray->radian) == 0)
	{
		printf("cos\n");
		return;
	}
	y_ray->y_bar = (int)(state->y_pos / BLOCK_SIZE) * BLOCK_SIZE;
	while (y_ray->distance < 0 && y_ray->y_bar > 0 && y_ray->y_bar < state->map_height * BLOCK_SIZE)
	{
		y_ray->y_bar = y_ray->y_bar + (cos(y_ray->radian) < 0) * BLOCK_SIZE;
		check_y_direction(state, y_ray);
		y_ray->y_bar = y_ray->y_bar - (cos(y_ray->radian) > 0) * BLOCK_SIZE;
	}
}

void	set_ray_info(t_state *state, int ray_nbr, t_ray *ray)
{
	double ray_radian;
	t_ray   x_ray;
	t_ray   y_ray;

	ray_radian = atan(((double)ray_nbr - START_RAY_NUM) / SCREEN_DIST) + state->angle * RAD;
	set_x_ray(state, ray_radian, &x_ray);
	set_y_ray(state, ray_radian, &y_ray);
	if (x_ray.distance < 0 || (y_ray.distance > 0 && y_ray.distance <= x_ray.distance))
		*ray = y_ray;
	else
		*ray = x_ray;
}
*/

void	set_angle_params(t_state *state, t_ray *ray)
{
	ray->radian = atan(((double)ray->nbr - START_RAY_NUM) / SCREEN_DIST)
		+ state->angle * RAD;
	ray->sin = sin(ray->radian);
	ray->cos = cos(ray->radian);
}

bool	check_block(t_state *state, t_ray *ray)
{
	if (ray->x_block >= 0 && ray->x_block < state->map_width
		&& ray->y_block >= 0 && ray->y_block < state->map_height)
	{
		if (state->map[ray->y_block][ray->x_block] == BLOCK)
			return (1);
		else if (state->map[ray->y_block][ray->x_block] == SPRITE)
			update_sprite_info(state, ray);
	}
	return (0);
}

void	check_closest_x_barrier(t_state *state, t_ray *ray, int *x_bar, double *y)
{
	ray->x_block = *x_bar / BLOCK_SIZE - (ray->sin < 0);
	ray->y_block = *y / BLOCK_SIZE;
	if (check_block(state, ray))
	{
		ray->x_bar = *x_bar;
		ray->y_bar = *y;
		ray->is_vertical = 1;
		ray->distance = sqrt(pow(ray->x_bar - state->x_pos, 2) + pow(ray->y_bar
			- state->y_pos, 2)) * cos(state->angle * RAD - ray->radian);
	}
	*x_bar += ((ray->sin > 0) - (ray->sin < 0)) * BLOCK_SIZE;
	*y = (ray->cos / ray->sin) * (state->x_pos - (double)(*x_bar)) + state->y_pos;
}

void	check_closest_y_barrier(t_state *state, t_ray *ray, double *x, int *y_bar)
{
	ray->x_block = *x / BLOCK_SIZE;
	ray->y_block = *y_bar / BLOCK_SIZE - (ray->cos > 0);
	if (check_block(state, ray))
	{
		ray->x_bar = *x;
		ray->y_bar = *y_bar;
		ray->is_vertical = 0;
		ray->distance = sqrt(pow(ray->x_bar - state->x_pos, 2) + pow(ray->y_bar
			- state->y_pos, 2)) * cos(state->angle * RAD - ray->radian);
	}
	*y_bar += ((ray->cos < 0) - (ray->cos > 0)) * BLOCK_SIZE;
	*x = (ray->sin / ray->cos) * (state->y_pos - (double)(*y_bar)) + state->x_pos;
}

void	set_ray_info(t_state *state, t_ray *ray)
{
	int 	x_bar;
	int 	y_bar;
	double 	x;
	double 	y;

	set_angle_params(state, ray);
	clear_sprites_info(state->visible_sprites);
	x_bar = (int)(state->x_pos / BLOCK_SIZE) * BLOCK_SIZE
			+ (ray->sin > 0) * BLOCK_SIZE;
	y = (ray->cos / ray->sin) * (state->x_pos - (double)x_bar) + state->y_pos;
	y_bar = (int)(state->y_pos / BLOCK_SIZE) * BLOCK_SIZE
			+ (ray->cos < 0) * BLOCK_SIZE;
	x = (ray->sin / ray->cos) * (state->y_pos - (double)y_bar) + state->x_pos;
	ray->distance = -1;
	while (ray->distance < 0)
	{
		if (ray->sin != 0)
			while (fabs(state->y_pos - y) < fabs(state->y_pos- (double)y_bar)
				&& ray->distance < 0)
				check_closest_x_barrier(state, ray, &x_bar, &y);
		if (ray->cos != 0 && ray->distance < 0)
			while (fabs(state->x_pos - (double)x_bar) >= fabs(state->x_pos - x)
				&& ray->distance < 0)
				check_closest_y_barrier(state, ray, &x, &y_bar);
	}
}
