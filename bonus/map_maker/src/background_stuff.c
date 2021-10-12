/*
** EPITECH PROJECT, 2018
** background_stuff
** File description:
** Display the background
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "proto.h"

void	background_stuff(sfRenderWindow *w, int *x, int *y)
{
	sfTexture	*texture_bg;
	sfSprite	*sprite = sfSprite_create();

	texture_bg = sfTexture_createFromFile("bg.png", NULL);
	sfSprite_setTexture(sprite, texture_bg, sfTrue);
	sfSprite_setPosition(sprite, create_vector2f(*x, *y));
	sfRenderWindow_drawSprite(w, sprite, NULL);
	sfSprite_setPosition(sprite, create_vector2f(*x - 1919, *y));
	sfRenderWindow_drawSprite(w, sprite, NULL);
	sfTexture_destroy(texture_bg);
	sfSprite_destroy(sprite);
	*x += 1;
	if (*x >= 1920)
		*x = 0;
}
