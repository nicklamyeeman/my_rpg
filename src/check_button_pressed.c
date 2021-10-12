/*
** EPITECH PROJECT, 2018
** check_button_pressed
** File description:
** Check if a button is pressed and change his state
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	check_if_pressed(win_t *w, stage *tmp, int x, int y)
{
	int	r = w->ratio;
	float	s = tmp->scale;

	if (same_strings(w->cur_scene, tmp->scene) != 1)
		return;
	if (x >= (tmp->x + tmp->box.width * s) / r || x <= tmp->x / r)
		return;
	if (y >= (tmp->y + tmp->box.height * s) / r || y <= tmp->y / r)
		return;
	if (same_strings(tmp->class, "button") == 1) {
		w->select = tmp->type;
		tmp->box.top += tmp->box.height;
	}
}

void	check_button_pressed(win_t *w)
{
	int	x = w->evt.mouseButton.x;
	int	y = w->evt.mouseButton.y;
	stage	*tmp = w->scene;

	if (w->evt.mouseButton.button == sfMouseLeft) {
		while (tmp != NULL) {
			check_if_pressed(w, tmp, x, y);
			tmp = tmp->next;
		}
	}
}