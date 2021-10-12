/*
** EPITECH PROJECT, 2018
** delete_from_map
** File description:
** Delete a right clicked sprite
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "proto.h"

void	cut_sprite(map_s **map, map_s *tmp)
{
	map_s	*tmp2 = *map;

	if (tmp == *map) {
		sfTexture_destroy(tmp->texture);
		*map = tmp->next;
		return;
	}
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	sfTexture_destroy(tmp->texture);
	tmp2->next = tmp->next;
}

void	delete_from_map(map_s **map, int x, int y)
{
	map_s	*tmp = *map;

	x /= 20;
	y /= 20;
	while (tmp != NULL) {
		if (tmp->x == x && tmp-> y == y) {
			cut_sprite(map, tmp);
			return;
		}
		tmp = tmp->next;
	}
}
