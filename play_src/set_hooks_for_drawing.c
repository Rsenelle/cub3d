/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks_for_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:35 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:33:37 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubbster.h"

static
void	count_steps(int keycode, t_state *state, double *x_step, double *y_step)
{
	double  direction_radian;

	if (keycode == KEY_W)
		direction_radian = (double)state->angle * RAD;
	else if (keycode == KEY_D)
		direction_radian = (double)(state->angle + 90) * RAD;
	else if (keycode == KEY_S)
		direction_radian = (double)(state->angle + 180) * RAD;
	else
		direction_radian = (double)(state->angle + 270) * RAD;
	*x_step = STEP_SIZE * sin(direction_radian) * (double)state->speed;
	*y_step = STEP_SIZE * (-cos(direction_radian)) * (double)state->speed;
}

static
void	key_move(int keycode, t_state *state)
{
	double x_step;
	double y_step;
	double available_x_distance;
	double available_y_distance;

	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_D || keycode == KEY_S)
	{
		count_steps(keycode, state, &x_step, &y_step);
		available_x_distance = get_distance_for_step(state, (270 - ((x_step > 0) * 180)) * RAD);
		available_y_distance = get_distance_for_step(state, ((y_step > 0) * 180) * RAD);
		if (available_x_distance < fabs(x_step) + 1.0)
			x_step = (available_x_distance - 1.0) * (double)(((x_step > 0) * 2) - 1);
		if (available_y_distance < fabs(y_step) + 1.0)
			y_step = (available_y_distance - 1.0) * (double)(((y_step > 0) * 2) - 1);
		state->x_pos += x_step;
		state->y_pos += y_step;
		collect_coin(state);
	}
}

static
void	key_rotate(int keycode, t_state *state)
{
	if (keycode == KEY_RIGHT)
	{
		state->angle += state->speed;
		state->angle = state->angle % 360;
	}
	else if (keycode == KEY_LEFT)
	{
		state->angle -= state->speed;
		state->angle = (state->angle + 360) % 360;
	}
}

static
int	key_action(int keycode, t_state *state)
{
	key_move(keycode, state);
	key_rotate(keycode, state);
	if (keycode == KEY_PLUS && state->speed < 5)
		state->speed++;
	if (keycode == KEY_MINUS && state->speed > 1)
		state->speed--;
	return (0);
}

void	set_hooks_for_drawing(t_mlx *workspace, t_state *state)
{
	mlx_hook(workspace->win, 2, 1L << 0, key_action, state);
}
