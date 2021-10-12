/*
** EPITECH PROJECT, 2018
** move_player
** File description:
** move the player
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

int	no_pnj(int x, int y, pnj_t *pnj)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		if (tmp->x == x && tmp->y == y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	can_walk_on(int x, int y, map_t *map, pnj_t *pnj)
{
	map_t	*tmp = map;

	if (!no_pnj(x, y, pnj))
		return (0);
	while (tmp != NULL) {
		if (tmp->x == x && tmp->y == y && tmp->wall == 0)
			return (1);
		else if (tmp->x == x && tmp->y == y)
			return (0);
		tmp = tmp->next;
	}
	return (0);
}

void	move_player(player_t *p, map_t *map, pnj_t *pnj)
{
	if (sfKeyboard_isKeyPressed(sfKeyS) && p->mvy == 0 && p->mvx == 0) {
		if (can_walk_on(p->x, p->y + 1, map, pnj))
			p->mvy += 1;
		p->rect.top = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyZ) && p->mvy == 0 && p->mvx == 0) {
		if (can_walk_on(p->x, p->y - 1, map, pnj))
			p->mvy -= 1;
		p->rect.top = 25;
	}
	if (sfKeyboard_isKeyPressed(sfKeyD) && p->mvy == 0 && p->mvx == 0) {
		if (can_walk_on(p->x + 1, p->y, map, pnj))
			p->mvx += 1;
		p->rect.top = 3 * 25;
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ) && p->mvy == 0 && p->mvx == 0) {
		if (can_walk_on(p->x - 1, p->y, map, pnj))
			p->mvx -= 1;
		p->rect.top = 2 * 25;
	}
}
