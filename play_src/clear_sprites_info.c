#include "../include/cubbster.h"

void	clear_sprites_info(t_list *sprites)
{
	t_list		*elem;
	t_sprite	*sprite;

	elem = sprites;
	while (elem)
	{
		sprite = elem->str;
		sprite->to_del = 1;
		elem = elem->next;
	}
}

