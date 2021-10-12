/*
** EPITECH PROJECT, 2018
** intro
** File description:
** Display the intro
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdio.h>
#include "rpg.h"

void	event_intro(win_t w, sfMusic *m)
{
	sfEvent	evt;

	while (sfRenderWindow_pollEvent(w.win, &evt))
		if (evt.type == sfEvtKeyPressed)
			sfMusic_stop(m);
}

void	roll_intro(win_t w)
{
	sfMusic	*m = sfMusic_createFromFile("./ressources/intro/intro.ogg");

	w.scene = load_scene(w.scene, "intro");
	sfMusic_play(m);
	while (sfMusic_getStatus(m) == sfPlaying) {
		event_intro(w, m);
		sfRenderWindow_clear(w.win, sfBlack);
		render_stage(&w);
		sfRenderWindow_display(w.win);
	}
	sfMusic_destroy(m);
	suppr_stage(w.scene);
}
