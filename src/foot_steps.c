/*
** EPITECH PROJECT, 2018
** foot_steps
** File description:
** Create sound for footsteps
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

char	*retrieve_name_tile(player_t *p, map_t *map)
{
	map_t	*t = map;

	while (t != NULL) {
		if (t->x == p->x + p->mvx && t->y == p->y + p->mvy)
			return (t->name);
		t = t->next;
	}
	return (NULL);
}

void	foot_steps(player_t *p, map_t *map, sfMusic **m, int *is_sound)
{
	if (is_in_it("grass", retrieve_name_tile(p, map))) {
		*m = sfMusic_createFromFile("./ressources/audio/grass.ogg");
		*is_sound = 1;
		sfMusic_play(*m);
	}
	if (is_in_it("wood", retrieve_name_tile(p, map))) {
		*m = sfMusic_createFromFile("./ressources/audio/wood.ogg");
		*is_sound = 1;
		sfMusic_play(*m);
	}
}
