/*
** EPITECH PROJECT, 2018
** init_window
** File description:
** initialise the window
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "rpg.h"

win_t	init_window(win_t w)
{
	w.width = 1;
	w.height = 1;
	w.ratio = 1;
	w.mode.width = 1920;
	w.mode.height = 1080;
	w.mode.bitsPerPixel = 32;
	w.fullscreen = 0;
	w.win = sfRenderWindow_create(w.mode, "FF42", sfClose, NULL);
	w.select = NULL;
	w.class_select = NULL;
	w.alpha = 255;
	w.loop = 0;
	w.cur_scene = "intro";
	w.f = 0;
	w.boss = 0;
	sfRenderWindow_setFramerateLimit(w.win, 60);
	sfRenderWindow_setMouseCursorVisible(w.win, sfFalse);
	return (w);
}
