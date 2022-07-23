#include "../include/cubbster.h"

void	collect_coin(t_state *state)
{
	int	x_block;
	int	y_block;

	x_block = (int)state->x_pos / BLOCK_SIZE;
	y_block = (int)state->y_pos / BLOCK_SIZE;
	if (state->map[y_block][x_block] == SPRITE)
	{
		state->map[y_block][x_block] = SPACE;
		state->coins_count++;
	}
}
