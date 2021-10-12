/*
** EPITECH PROJECT, 2018
** rpf
** File description:
** qdfv event
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

void	qdfv_hgevent(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyRight)
			sfSprite_setPosition(btle->turn.arros, v2f(1500, 800));
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyDown)
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 940));
}

void	qdfv_hdevent(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyLeft)
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyDown)
			sfSprite_setPosition(btle->turn.arros, v2f(1500, 940));
}

void	qdfv_bgevent(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyRight)
			sfSprite_setPosition(btle->turn.arros, v2f(1500, 940));
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyUp)
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
}

void	qdfv_bdevent(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyLeft)
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 940));
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyUp)
			sfSprite_setPosition(btle->turn.arros, v2f(1500, 800));
}

void	qdfv_event(win_t *win, btle_t *btle)
{
	sfVector2f	a = sfSprite_getPosition(btle->turn.arros);

	(a.x == 1030 && a.y == 800) ? qdfv_hgevent(win, btle) : 0;
	(a.x == 1500 && a.y == 800) ? qdfv_hdevent(win, btle) : 0;
	(a.x == 1030 && a.y == 940) ? qdfv_bgevent(win, btle) : 0;
	(a.x == 1500 && a.y == 940) ? qdfv_bdevent(win, btle) : 0;
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 3;
}