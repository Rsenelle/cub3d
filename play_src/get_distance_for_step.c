#include "../include/cubbster.h"

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
}

static
void	set_x_ray(t_state *state, t_ray *x_ray)
{
	x_ray->is_vertical = 1;
	x_ray->distance = -1;
	if (sin(x_ray->radian) == 0)
		return ;
	x_ray->x_bar = (int)(state->x_pos / BLOCK_SIZE) * BLOCK_SIZE;
	if (x_ray->distance < 0 && x_ray->x_bar > 0 && x_ray->x_bar < state->map_width * BLOCK_SIZE)
	{
		x_ray->x_bar = x_ray->x_bar + (sin(x_ray->radian) > 0) * BLOCK_SIZE;
		check_x_direction(state, x_ray);
		x_ray->x_bar = x_ray->x_bar - (sin(x_ray->radian) < 0) * BLOCK_SIZE;
	}
}

static
void	set_y_ray(t_state *state, t_ray *y_ray)
{
	y_ray->is_vertical = 0;
	y_ray->distance = -1;
	if (cos(y_ray->radian) == 0)
		return ;
	y_ray->y_bar = (int)(state->y_pos / BLOCK_SIZE) * BLOCK_SIZE;
	if (y_ray->distance < 0 && y_ray->y_bar > 0 && y_ray->y_bar < state->map_height * BLOCK_SIZE)
	{
		y_ray->y_bar = y_ray->y_bar + (cos(y_ray->radian) < 0) * BLOCK_SIZE;
		check_y_direction(state, y_ray);
		y_ray->y_bar = y_ray->y_bar - (cos(y_ray->radian) > 0) * BLOCK_SIZE;
	}
}

double	get_distance_for_step(t_state *state, double ray_radian)
{
	t_ray	x_ray;
	t_ray	y_ray;

	x_ray.radian = ray_radian;
	set_x_ray(state, &x_ray);
	y_ray.radian = ray_radian;
	set_y_ray(state, &y_ray);
	if (x_ray.distance < 0 && y_ray.distance < 0)
		return (STEP_SIZE * state->speed);
	if (x_ray.distance < 0 || (y_ray.distance > 0 && y_ray.distance <= x_ray.distance))
		return (y_ray.distance);
	return (x_ray.distance);
}
