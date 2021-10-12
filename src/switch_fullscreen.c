/*
** EPITECH PROJECT, 2018
** switch fullscreen
** File description:
** Switch between fullscreen and bordered mode
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	create_fullscreen(win_t*w, sfVideoMode m, char *t)
{
	w->win = sfRenderWindow_create(m, t, sfClose | sfFullscreen, NULL);
}

void	create_bordered(win_t*w, sfVideoMode m, char *t)
{
	w->win = sfRenderWindow_create(m, t, sfClose, NULL);
}

void	switch_fullscreen(win_t*w)
{
	sfVideoMode	m = w->mode;
	char	*t = "FF42";

	sfRenderWindow_close(w->win);
	sfRenderWindow_destroy(w->win);
	if (w->fullscreen == 0) {
		create_fullscreen(w, m, t);
		w->fullscreen = 1;
	}
	else {
		create_bordered(w, m, t);
		w->fullscreen = 0;
	}
	sfRenderWindow_setFramerateLimit(w->win, 60);
	sfRenderWindow_setMouseCursorVisible(w->win, sfFalse);
}
