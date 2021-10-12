/*
** EPITECH PROJECT, 2018
** settings
** File description:
** Handle the setting menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdio.h>
#include "rpg.h"

void	settings(win_t *w)
{
	w->loop = 1;
	suppr_stage(w->scene);
	w->scene = load_scene(w->scene, "settings");
	w->alpha = 255;
	while (w->loop) {
		sfRenderWindow_clear(w->win, sfBlack);
		menu_events(w);
		if (!sfRenderWindow_isOpen(w->win))
			w->loop = 0;
		render_stage(w);
		render_mouse(w);
		sfRenderWindow_display(w->win);
	}
	suppr_stage(w->scene);
	w->scene = load_scene(w->scene, "menu");
	w->cur_scene = "menu";
}
