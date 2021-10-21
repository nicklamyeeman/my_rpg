/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** battle event
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <fcntl.h>
#include "rpg.h"

void	qvvs_event(win_t *win, btle_t *btle, chara_t *p)
{
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyRight)
			p->num += (p->num == 4) ? 0 : 1;
	}
	if ((p[p->num].name == NULL) || (win->evt.type == sfEvtKeyPressed &&
		win->evt.key.code == sfKeyLeft))
		p->num -= 1;
	if (p->num < 0)
		p->num = 0;
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyEscape) {
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
			win->f = 2;
		}
	}
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyReturn)
			win->f = 13;
	}
}

void	vprf_event(win_t *win)
{
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyReturn)
			win->f = 21;
	}
}

void	vplf_event(win_t *win)
{
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyReturn)
			win->f = 23;
	}
}

void	battle_event2(win_t *win, btle_t *btle)
{
	(win->f == 26) ? ento_event(win) : 0;
	(win->f == 28) ? crit_event(win) : 0;
	(win->f == 30) ? ratk_event(win) : 0;
	(win->f == 32) ? vpap_event(win, btle) : 0;
	(win->f == 34) ? adko_event(win) : 0;
	(win->f == 36) ? vvme_event(win) : 0;
	(win->f == 38) ? verx_event(win) : 0;
	(win->f == 40) ? fepn_event(win) : 0;
	(win->f == 42) ? vapc_event(win) : 0;
	(win->f == 44) ? bteq_event(win) : 0;
	if (win->evt.type == sfEvtClosed) {
		sfRenderWindow_close(win->win);
		win->loop = 0;
	}
}

void	battle_event(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	while (sfRenderWindow_pollEvent(win->win, &win->evt)) {
		if (win->evt.type == sfEvtClosed) {
			sfRenderWindow_close(win->win);
			win->loop = 0;
		}
		(win->f == 0) ? dmva_event(win) : 0;
		(win->f == 2) ? qdfv_event(win, btle) : 0;
		(win->f == 4) ? qvva_event(win, btle, p, ennem) : 0;
		(win->f == 6) ? vpae_event(win) : 0;
		(win->f == 8) ? toch_event(win) : 0;
		(win->f == 10) ? qsvl_event(win, btle) : 0;
		(win->f == 14) ? qvvs_event(win, btle, p) : 0;
		(win->f == 16) ? heal_event(win) : 0;
		(win->f == 18) ? vprm_event(win) : 0;
		(win->f == 20) ? vprf_event(win) : 0;
		(win->f == 22) ? vplf_event(win) : 0;
		(win->f == 24) ? eavp_event(win) : 0;
		(win->f >= 26) ? battle_event2(win, btle) : 0;
	}
}
