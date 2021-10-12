/*
** EPITECH PROJECT, 2018
** launch_menu
** File description:
** Initialise the menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdio.h>
#include "rpg.h"

void	launch_menu(void)
{
	win_t	w = init_window(w);

	roll_intro(w);
	w.cur_scene = "menu";
	w.scene = load_scene(w.scene, "menu");
	w.audio = init_audio("./ressources/menu/menu.ogg");
	if (w.scene == NULL)
		sfRenderWindow_close(w.win);
	while (sfRenderWindow_isOpen(w.win)) {
		sfRenderWindow_clear(w.win, sfBlack);
		menu_events(&w);
		render_stage(&w);
		render_mouse(&w);
		sfRenderWindow_display(w.win);
	}
	destroy_everything(&w);
}
