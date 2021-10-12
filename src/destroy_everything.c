/*
** EPITECH PROJECT, 2018
** destroy_everything
** File description:
** Destroy everything: textures, musics, stage, ...
*/

#include <stdlib.h>
#include "rpg.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

void	destroy_everything(win_t *w)
{
	stage	*tmp = w->scene;

	suppr_stage(tmp);
	if (w->select != NULL)
		free(w->select);
	if (w->class_select != NULL)
		free(w->class_select);
	sfMusic_destroy(w->audio.theme);
	sfRenderWindow_destroy(w->win);
}
