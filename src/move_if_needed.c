/*
** EPITECH PROJECT, 2018
** move_if_needed
** File description:
** Move if needed
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	smooth_move(player_t *p, pnj_t *pnj, sfTime time)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		tmp->x -= sfTime_asMilliseconds(time) * p->mvx / 500000;
		tmp->y -= sfTime_asMilliseconds(time) * p->mvy / 500000;
		tmp = tmp->next;
	}
	p->x += sfTime_asMilliseconds(time) * p->mvx / 500;
	p->y += sfTime_asMilliseconds(time) * p->mvy / 500;
}

void	smooth_move_reinit(player_t *p, pnj_t *pnj, sfTime time)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		tmp->x += sfTime_asMilliseconds(time) * p->mvx / 500000;
		tmp->y += sfTime_asMilliseconds(time) * p->mvy / 500000;
		tmp = tmp->next;
	}
}

void	move_if_needed(win_t *w, player_t *p, map_t *map, pnj_t *pnj)
{
	sfTime	time = sfClock_getElapsedTime(p->clock);
	float	x = p->x;
	float	y = p->y;

	while (sfTime_asMilliseconds(time) < 500) {
		smooth_move(p, pnj, time);
		sfRenderWindow_clear(w->win, sfBlack);
		p->rect.left = 20 * (sfTime_asMilliseconds(time) / 125);
		display_map(w, p, map, pnj);
		render_transition(w);
		sfRenderWindow_display(w->win);
		p->x = x;
		p->y = y;
		smooth_move_reinit(p, pnj, time);
		time = sfClock_getElapsedTime(p->clock);
	}
	p->rect.left = 0;
	p->x += p->mvx;
	p->y += p->mvy;
	p->mvx = 0;
	p->mvy = 0;
}
