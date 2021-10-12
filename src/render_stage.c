/*
** EPITECH PROJECT, 2018
** render
** File description:
** Render the scene, the mouse, ...
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	render_scene_elem(win_t *w, stage *tmp)
{
	sfSprite	*sprite = sfSprite_create();
	float	scale = tmp->scale;

	sfSprite_setTexture(sprite, tmp->texture, sfTrue);
	sfSprite_setTextureRect(sprite, tmp->box);
	sfSprite_setPosition(sprite, create_vector(tmp->x, tmp->y));
	sfSprite_setScale(sprite, create_vector(scale, scale));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfSprite_destroy(sprite);
}

void	render_stage(win_t *w)
{
	stage	*tmp = w->scene;

	while (tmp != NULL) {
		if (same_strings(w->cur_scene, tmp->scene))
			render_scene_elem(w, tmp);
		tmp = tmp->next;
	}
}
