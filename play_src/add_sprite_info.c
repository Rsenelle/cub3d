#include "../include/cubbster.h"

static
t_sprite	*find_existing_sprite(t_list *lst, int x_block, int y_block)
{
	t_list		*elem;
	t_sprite	*sprite;

	elem = lst;
	while (elem)
	{
		sprite = (t_sprite *)(elem->str);
		if (sprite->x_block == x_block && sprite->y_block == y_block)
			return (sprite);
		elem = elem->next;
	}
	return (NULL);
}

void	add_sprite_info(t_ray *ray, t_state *state)
{
	t_sprite	*sprite;
	t_list		*new;

	sprite = find_existing_sprite(state->visible_sprites,
		ray->x_block, ray->y_block);
	if (sprite)
		return ;
	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		put_error(MEMORY_ERROR);
	sprite->x_block = ray->x_block;
	sprite->y_block = ray->y_block;
	new = ft_lstnew(sprite);
	if (!new)
		put_error(MEMORY_ERROR);
	ft_lstadd_back(&state->visible_sprites, new);
}
