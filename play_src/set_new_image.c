#include "../include/cubbster.h"

void	set_new_image(t_mlx *workspace, t_image *img)
{
	img->img_ptr = mlx_new_image(workspace->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img_ptr)
		put_error(IMG_INITIALIZATION_FAILED);
	img->addr = mlx_get_data_addr(img->img_ptr,
								  &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		put_error(IMG_INITIALIZATION_FAILED);
}