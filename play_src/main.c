#include "../include/cubbster.h"

typedef struct s_render {
	t_mlx		*workspace;
	t_image		*img;
	t_state		*state;
}	t_render;

int	render_next_frame(t_render *render)
{
	draw_state(render->workspace, render->img, render->state);
	return (0);
}

void	set_start_state(t_state *state)
{
	state->visible_sprites = NULL;
	state->speed = 1;
	state->coins_count = 0;
	state->coins_need = 4;
}

int	main(int argc, char **argv)
{
	t_render	render;
	t_image		img;
	t_state		state;
	t_mlx		workspace;
	t_all		s_all;

	if (argc != 2)
		ft_error(INVALID_ARG_COUNT);
	init_struct(&s_all);
	parsing(argv[1], &s_all, &state);
	set_new_window(&workspace, &s_all, &img);
	set_hooks_for_drawing(&workspace, &state);
	mlx_mouse_get_pos(workspace.win, &state.x_mouse, &state.y_mouse);
	set_start_state(&state);
	render.workspace = &workspace;
	render.img = &img;
	render.state = &state;
	mlx_loop_hook(workspace.mlx, render_next_frame, &render);
	mlx_loop(workspace.mlx);
	return (0);
}
