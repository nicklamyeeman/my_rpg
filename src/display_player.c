/*
** EPITECH PROJECT, 2018
** display_player
** File description:
** Display the player
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	display_player(win_t *w, player_t *p)
{
	sfTexture	*texture;
	sfSprite	*sprite = sfSprite_create();

	texture = sfTexture_createFromFile("ressources/misc/char.png", NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, p->rect);
	sfSprite_setScale(sprite, create_vector(8, 8));
	sfSprite_setPosition(sprite, create_vector(5 * 192 - 76, 2 * 216 - 20));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
}
