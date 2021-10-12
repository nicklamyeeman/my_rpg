/*
** EPITECH PROJECT, 2018
** reset_buttons
** File description:
** reset buttons to their initial state
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	check_wrong_box(win_t *w, stage *tmp)
{
	int	x = w->evt.mouseButton.x;
	int	y = w->evt.mouseButton.y;
	float	s = tmp->scale;
	int	r = w->ratio;

	if (same_strings(w->select, tmp->type) != 1)
		return;
	if (x >= (tmp->x + tmp->box.width * s) / r || x <= tmp->x / r)
		return;
	if (y >= (tmp->y + tmp->box.height * s) / r || y <= tmp->y / r)
		return;
	check_select(w);
}

void	oneclick_blocker(win_t *w, stage *tmp)
{
	if (same_strings(w->cur_scene, tmp->scene) == 1) {
		check_wrong_box(w, tmp);
		tmp->box.top = 0;
	}
}

void	reset_buttons(win_t *w)
{
	stage	*tmp = w->scene;

	if (w->evt.mouseButton.button == sfMouseLeft) {
		while (tmp != NULL) {
			oneclick_blocker(w, tmp);
			tmp = tmp->next;
		}
	}
	w->select = NULL;
}