/*
** EPITECH PROJECT, 2018
** menu_events
** File description:
** Handle mouse events in the menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdio.h>
#include "rpg.h"

void	menu_events(win_t *w)
{
	while (sfRenderWindow_pollEvent(w->win, &w->evt)) {
		if (w->evt.type == sfEvtClosed)
			sfRenderWindow_close(w->win);
		if (w->evt.type == sfEvtMouseMoved) {
			w->x_mouse = w->evt.mouseMove.x;
			w->y_mouse = w->evt.mouseMove.y;
		}
		if (w->evt.type == sfEvtMouseButtonPressed)
			check_button_pressed(w);
		else if (w->evt.type == sfEvtMouseButtonReleased)
			reset_buttons(w);
	}
}
