#include "../include/cubbster.h"

void	init_workspace(t_mlx *workspace, t_all *s_all)
{
	workspace->mlx = s_all->mlx;
	workspace->win = mlx_new_window(workspace->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!workspace->win)
		put_error(MEMORY_ERROR);
}