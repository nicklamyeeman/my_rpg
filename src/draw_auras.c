/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** auras
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <fcntl.h>
#include "rpg.h"

void	draw_auras(win_t *win, chara_t *perso, int k)
{
	perso[k].autim = sfClock_getElapsedTime(perso[k].auclo);
	if (sfTime_asSeconds(perso[k].autim) > 0.3) {
		if (perso[k].aurec.left == 500 * 3)
			perso[k].aurec.left = 0;
		else
			perso[k].aurec.left += 500;
		sfSprite_setTextureRect(perso[k].auras, perso[k].aurec);
		sfClock_restart(perso[k].auclo);
	}
	sfRenderWindow_drawSprite(win->win, perso[k].auras, NULL);
}