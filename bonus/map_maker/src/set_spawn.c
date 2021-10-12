/*
** EPITECH PROJECT, 2018
** set_spawn
** File description:
** set the spawn attribute of a tile to 1
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"

void	set_spawn(map_s **map, int x, int y)
{
	map_s	*tmp = *map;

	x /= 20;
	y /= 20;
	while (tmp != NULL) {
		if (tmp->x == x && tmp->y == y)
			tmp->spawn = 1;
		tmp = tmp->next;
	}
}
