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

void	verx_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 39;
}

void	vvme_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 37;
}

void	adko_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 2;
}

void	heal_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 17;
}

void	vpap_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyReturn) {
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
			win->f = 2;
		}
	}
}
