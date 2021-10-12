/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** create transitions as fade in and fade out
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

sfColor	fade_in(win_t *w)
{
	sfColor	color = sfColor_fromRGBA(0, 0, 0, w->alpha);

	if (w->alpha > 250)
		w->alpha = 255;
	else
		w->alpha += 8;
	return (color);
}

sfColor	fade_out(win_t *w)
{
	sfColor	color = sfColor_fromRGBA(0, 0, 0, w->alpha);

	if (w->alpha < 8)
		w->alpha = 0;
	else
		w->alpha -= 8;
	return (color);
}

void	render_transition(win_t *w)
{
	char	*black = "./ressources/misc/black.png";
	sfTexture	*texture;
	sfSprite	*sprite = sfSprite_create();

	texture = sfTexture_createFromFile(black , NULL);
	sfSprite_setColor(sprite, fade_out(w));
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setScale(sprite, create_vector(12, 12));
	sfSprite_setPosition(sprite, create_vector(0, 0));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}
