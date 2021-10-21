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

void	event_stat(rpg_t *rp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyRight)
		rp->bol.per += (rp->bol.per == MENESTR) ? -4 : 1;
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyLeft)
		rp->bol.per -= (rp->bol.per == PALA) ? -4 : 1;
}

void	check_enter(rpg_t *rp, sfEvent ev)
{
	sfVector2f	v = sfView_getCenter(rp->cam.view);

	if (ev.key.code == sfKeyReturn) {
		if (rp->bol.in == QUIT)
			sfRenderWindow_close(rp->wina.win);
		if (rp->bol.in == 1)
			rp->bol.menu = STAT;
		if (rp->bol.in == OBJ) {
			v.x -= 720;
			v.y -= 240;
			sfSprite_setPosition(rp->sprite[3].sprite, v);
			rp->bol.menu = INV;
		}
	}
}

void	move_cursor_ev(rpg_t *rp, sfEvent ev)
{
	sfVector2f	pos = sfSprite_getPosition(rp->sprite[3].sprite);

	rp->bol.in = rp->bol.in % 5;
	if (ev.key.code == sfKeyDown) {
		if (rp->bol.in == 4)
			pos.y -= 500;
		rp->bol.in += 1;
		pos.y += 100;
		sfSprite_setPosition(rp->sprite[3].sprite, pos);
	}
	if (ev.key.code == sfKeyUp) {
		if (rp->bol.in == 0) {
			rp->bol.in = 5;
			pos.y += 500;
		}
		rp->bol.in -= 1;
		pos.y -= 100;
		sfSprite_setPosition(rp->sprite[3].sprite, pos);
	}
}

void	replace_menu(rpg_t *rp)
{
	sfVector2f	vec = sfView_getCenter(rp->cam.view);
	sfVector2f	pl = sfView_getCenter(rp->cam.view);
	sfVector2f	pos;

	vec = v2f(vec.x + 300, vec.y - 300);
	pl = v2f(pl.x - 1000, pl.y - 500);
	sfSprite_setPosition(rp->sprite[2].sprite, vec);
	sfSprite_setPosition(rp->sprite[4].sprite, pl);
	pos = sfSprite_getPosition(rp->sprite[2].sprite);
	pos = v2f(pos.x - 25, pos.y + 64);
	sfSprite_setPosition(rp->sprite[3].sprite, pos);
	sfSprite_setPosition(rp->sprite[6].sprite, pl);
}

int	menu_event(rpg_t *rp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed &&
		ev.key.code == sfKeyEscape && rp->bol.menu == STAT)
		return (rp->bol.menu = MENU);
	if (ev.type == sfEvtKeyPressed &&
	ev.key.code == sfKeyEscape && rp->bol.menu == INV) {
		rp->bol.obj = 0;
		replace_menu(rp);
		return (rp->bol.menu = MENU);
	}
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEscape) {
		rp->bol.in = 0;
		(rp->bol.menu != MENU) ? replace_menu(rp) : 0;
		rp->bol.menu = (rp->bol.menu + 1) % 2;
	}
	if (rp->bol.menu == MENU && ev.type == sfEvtKeyPressed) {
		move_cursor_ev(rp, ev);
		check_enter(rp, ev);
	}
	return (0);
}