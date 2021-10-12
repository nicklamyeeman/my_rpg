/*
** EPITECH PROJECT, 2018
** rpf
** File description:
** dmvaevent
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

void	toch_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 9;
}

void	qvva_event(win_t *win, btle_t *btle, chara_t *perso, ennem_t *ennem)
{
	if (win->evt.type == sfEvtKeyPressed &&
		win->evt.key.code == sfKeyRight)
		ennem->num += 1;
	if ((ennem[ennem->num].name == NULL) ||
		(win->evt.type == sfEvtKeyPressed &&
		win->evt.key.code == sfKeyLeft))
		ennem->num -= 1;
	if (ennem->num < 0)
		ennem->num = 0;
	if (win->evt.type == sfEvtKeyPressed &&
	win->evt.key.code == sfKeyEscape) {
		sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
		win->f = 2;
	}
	if (win->evt.type == sfEvtKeyPressed &&
	win->evt.key.code == sfKeyReturn) {
		if (ennem_exist(win, btle, perso, ennem) == -1);
		else
			win->f = 5;
	}
}

void	vpae_event(win_t *win, btle_t *btle, ennem_t *ennem)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 7;
}

void	dmva_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 1;
}
