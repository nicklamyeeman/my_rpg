/*
** EPITECH PROJECT, 2018
** check_select
** File description:
** Check what you clicked depending of the current scene
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	check_select_menu(win_t *w)
{
	if (same_strings(w->select, "newgame") == 1)
		new_game(w);
	if (same_strings(w->select, "quit") == 1)
		sfRenderWindow_close(w->win);
	if (same_strings(w->select, "settings") == 1) {
		w->cur_scene = "settings";
		settings(w);
	}
}

void	check_select_settings(win_t *w)
{
	if (same_strings(w->select, "back"))
		w->loop = 0;
	if (same_strings(w->select, "fullscreen"))
		switch_fullscreen(w);
}

void	check_select(win_t *w)
{
	if (w->select == NULL)
		return;
	if (same_strings(w->cur_scene, "settings") == 1)
		check_select_settings(w);
	if (same_strings(w->cur_scene, "menu") == 1)
		check_select_menu(w);
}
