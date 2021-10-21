/*
** EPITECH PROJECT, 2018
** game_events
** File description:
** Handle inputs in the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	turn_pnj_y(player_t *p, pnj_t *pnj)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		if (p->x == tmp->x && p->y - 1 == tmp->y &&
		p->rect.top == 1 * 25) {
			tmp->direction = 0;
			p->speaking_with = tmp->name;
		}
		if (p->x == tmp->x && p->y + 1 == tmp->y &&
		p->rect.top == 0 * 25) {
			tmp->direction = 2;
			p->speaking_with = tmp->name;
		}
		tmp = tmp->next;
	}
}

void	turn_pnj_x(player_t *p, pnj_t *pnj)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		if (p->x - 1 == tmp->x && p->y == tmp->y &&
		p->rect.top == 2 * 25) {
			tmp->direction = 1;
			p->speaking_with = tmp->name;
		}
		if (p->x + 1 == tmp->x && p->y == tmp->y &&
		p->rect.top == 3 * 25) {
			tmp->direction = 3;
			p->speaking_with = tmp->name;
		}
		tmp = tmp->next;
	}
}

void	dev_event(sfEvent event, player_t *p)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyNum1) {
		p->x = 45;
		p->y = 38;
	}
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyNum2) {
		p->x = 55;
		p->y = 38;
	}
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyNum3) {
		p->x = 49;
		p->y = 8;
	}
}

void	speak_event(win_t *w, player_t *p, pnj_t *pnj, sfEvent event)
{
	if (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyE) {
		turn_pnj_x(p, pnj);
		turn_pnj_y(p, pnj);
		if (p->speaking_with != NULL) {
			p->line += 1;
			load_dialog(p, pnj);
		}
		if (p->dialog == NULL) {
			special_event(w, p, pnj);
			p->speaking_with = NULL;
			p->line = 0;
		}
	}
}

void	game_events(win_t *w, player_t *p, rpg_t *rp, pnj_t *pnj)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(w->win, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(w->win);
			w->loop = 0;
		}
		speak_event(w, p, pnj, event);
		dev_event(event, p);
		if (w->boss == 2) {
			my_item_to_list
			(&rp->obj, "assets/epe.png", "assets/txte.png", EPEE);
			w->boss = 3;
		}
		(rp->bol.stat != 1) ? menu_event(rp, event) : 0;
		(rp->bol.menu == STAT) ? event_stat(rp, event): 0;
		(rp->bol.menu == INV) ? event_inv(rp, event): 0;
	}
}
