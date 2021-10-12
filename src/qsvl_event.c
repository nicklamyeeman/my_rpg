/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** quel sort voulez lancer event
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

void	qsvl_s2event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyUp)
			sfSprite_setPosition(btle->turn.arros, v2f(70, 895));
}

void	qsvl_s1event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyDown)
			sfSprite_setPosition(btle->turn.arros, v2f(70, 965));
}

void	qsvl_event(win_t *win, btle_t *btle)
{
	sfVector2f	a = sfSprite_getPosition(btle->turn.arros);

	(a.x == 70 && a.y == 895) ? qsvl_s1event(win, btle) : 0;
	(a.x == 70 && a.y == 965) ? qsvl_s2event(win, btle) : 0;
	if (win->evt.type == sfEvtKeyPressed) {
		if (win->evt.key.code == sfKeyEscape) {
			sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
			win->f = 2;
		}
	}
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 11;
}