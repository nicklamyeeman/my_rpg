/*
** EPITECH PROJECT, 2018
** add_texture
** File description:
** add a texture in the linked list
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

int	check_if_wall_exist(map_s **map, int x, int y, char *t)
{
	map_s	*tmp = *map;
	map_s	*stock = NULL;
	char	*wall = "./texture/wall.png";

	if (same_strings(t, wall) != 1)
		return (0);
	while (tmp != NULL) {
		if (tmp->x == x && tmp->y == y &&
		same_strings(t, tmp->texture_name) != 1) {
			stock = tmp;
			tmp = NULL;
		}
		if (tmp != NULL)
			tmp = tmp->next;
	}
	if (stock == NULL || stock->wall == 1)
		return (1);
	else
		stock->wall = 1;
	return (0);
}

void	check_if_we_delete_first(map_s **map, int x, int y, char *t)
{
	map_s	*tmp = *map;

	if (same_strings(t, "./texture/wall.png"))
		return;
	while (tmp != NULL) {
		if (tmp->x == x && tmp->y == y) {
			x *= 20;
			y *= 20;
			delete_from_map(map, x, y);
			return;
		}
		tmp = tmp->next;
	}
}

void	add_texture(map_s **map, char *texture, int x, int y)
{
	map_s	*elem = malloc(sizeof(*elem));
	map_s	*tmp = *map;

	if (check_if_wall_exist(map, x / 20, y / 20, texture))
		return;
	check_if_we_delete_first(map, x / 20, y / 20, texture);
	elem->x = x / 20;
	elem->y = y / 20;
	elem->wall = 0;
	elem->spawn = 0;
	elem->texture_name = texture;
	elem->texture = sfTexture_createFromFile(texture, NULL);
	elem->next = NULL;
	if (*map == NULL) {
		*map = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}
