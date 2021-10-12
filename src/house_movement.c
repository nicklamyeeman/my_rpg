/*
** EPITECH PROJECT, 2018
** house movement
** File description:
** Make the player enter or exit from houses
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

int	enter_house(win_t *w, player_t *p, map_t *map)
{
	if (p->x == 13 && p->y == 39) {
		p->x = 45;
		p->y = 40;
		p->mvy = -1;
		return (1);
	}
	if (p->x == 27 && p->y == 39) {
		p->x = 55;
		p->y = 40;
		p->mvy = -1;
		return (1);
	}
	return (0);
}

int	exit_house(win_t *w, player_t *p, map_t *map)
{
	if (p->x == 45 && p->y == 40) {
		p->x = 13;
		p->y = 39;
		p->mvy = 1;
		return (1);
	}
	if (p->x == 55 && p->y == 40) {
		p->x = 27;
		p->y = 39;
		p->mvy = 1;
		return (1);
	}
	return (0);
}

void	house_movement(win_t *w, player_t *p, map_t *map)
{
	map_t	*tmp = map;

	while (tmp != NULL && tmp->x != p->x && tmp->y != p->y)
		tmp = tmp->next;
	if (tmp == NULL)
		return;
	if (enter_house(w, p, tmp)) {
		w->alpha = 255;
		return;
	}
	if (exit_house(w, p, tmp)) {
		w->alpha = 255;
		return;
	}
}
