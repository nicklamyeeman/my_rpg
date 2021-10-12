/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** items init
*/

#include <stdlib.h>
#include "rpg.h"

void	my_item_to_list(obj_t **list, char *sprite, char *texte, int i)
{
	obj_t	*elem = malloc(sizeof(obj_t));

	if (elem == NULL)
		return;
	elem->conso = i;
	elem->name = init_sprite(texte, 0, 0);
	elem->itms = init_sprite(sprite, 0, 0);
	if (elem->name.sprite == NULL || elem->itms.sprite == NULL)
		return;
	elem->next = *list;
	*list = elem;
	return;
}

int	init_items(obj_t **list)
{
	*list = NULL;
	my_item_to_list(list, "assets/ann.png", "assets/txta.png", ANNE);
	my_item_to_list(list, "assets/ann.png", "assets/txta.png", ANNE);
	my_item_to_list(list, "assets/bou.png", "assets/txtb.png", BOUC);
}
