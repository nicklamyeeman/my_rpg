/*
** EPITECH PROJECT, 2018
** display_pnj
** File description:
** Display a pnj
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

float	compute_x_pnj(pnj_t *pnj, player_t *p)
{
	float	x = p->x - pnj->x;

	if (x < 0)
		x = (-x + 5) * 192 - 76;
	else
		x = (5 - x) * 192 - 76;
	return (x);
}

float	compute_y_pnj(pnj_t *pnj, player_t *p)
{
	float	y = p->y - pnj->y;

	if (y < 0)
		y = (-y + 2) * 216 - 20;
	else
		y = (2 - y) * 216 - 20;
	return (y);
}

void	display_pnj(win_t *w, pnj_t *pnj, player_t *p)
{
	sfTexture	*t = sfTexture_createFromFile(pnj->texture, NULL);
	sfSprite	*sprite = sfSprite_create();
	sfIntRect	box = {0, 0, 20, 25};
	float	x = compute_x_pnj(pnj, p);
	float	y = compute_y_pnj(pnj, p);

	box.left = 20 * pnj->direction;
	sfSprite_setTexture(sprite, t, sfTrue);
	sfSprite_setTextureRect(sprite, box);
	sfSprite_setScale(sprite, create_vector(8, 8));
	sfSprite_setPosition(sprite, create_vector(x, y));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(t);
}
