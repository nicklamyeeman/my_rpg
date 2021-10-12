/*
** EPITECH PROJECT, 2018
** render_mouse
** File description:
** Display the mouse cursor with an image
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"
#include <SFML/Graphics.h>

void	render_mouse(win_t *w)
{
	sfTexture	*mouse;
	sfSprite	*sprite = sfSprite_create();
	float	x = w->x_mouse * w->width;
	float	y = w->y_mouse * w->height;

	mouse = sfTexture_createFromFile("ressources/mouse.png", NULL);
	sfSprite_setTexture(sprite, mouse, sfTrue);
	sfSprite_setPosition(sprite, create_vector(x, y));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfTexture_destroy(mouse);
	sfSprite_destroy(sprite);
}
