/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** display win
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

void	dead_perso(win_t *win, btle_t *btle, chara_t *perso)
{
	sfVector2f	p;

	sfRenderWindow_drawSprite(win->win, perso[4].perss, NULL);
	if (perso[4].hplt <= 0) {
		p = sfSprite_getPosition(perso[4].perss);
		sfSprite_setPosition(btle->rips, p);
		sfRenderWindow_drawSprite(win->win, btle->rips, NULL);
	}
	else
		draw_auras(win, perso, 4);
	sfRenderWindow_drawSprite(win->win, perso[1].perss, NULL);
	if (perso[1].hplt <= 0) {
		p = sfSprite_getPosition(perso[1].perss);
		sfSprite_setPosition(btle->rips, p);
		sfRenderWindow_drawSprite(win->win, btle->rips, NULL);
	}
	else
		draw_auras(win, perso, 1);
}

void	isdead_perso(win_t *win, btle_t *btle, chara_t *perso)
{
	sfVector2f	p;

	if (perso[0].hplt <= 0) {
		p = sfSprite_getPosition(perso[0].perss);
		p.y += 60;
		p.x += 30;
		sfSprite_setPosition(btle->rips, p);
		sfRenderWindow_drawSprite(win->win, btle->rips, NULL);
	}
	else
		draw_auras(win, perso, 0);
	sfRenderWindow_drawSprite(win->win, perso[3].perss, NULL);
	if (perso[3].hplt <= 0) {
		p = sfSprite_getPosition(perso[3].perss);
		sfSprite_setPosition(btle->rips, p);
		sfRenderWindow_drawSprite(win->win, btle->rips, NULL);
	}
	else
		draw_auras(win, perso, 3);
	dead_perso(win, btle, perso);
}

void	dead_ennem(win_t *win, btle_t *btle, ennem_t *ennem, int i)
{
	sfVector2f	p;

	sfRenderWindow_drawSprite(win->win, ennem[i].ennes, NULL);
	if (ennem[i].hplt <= 0) {
		p = sfSprite_getPosition(ennem[i].ennes);
		sfSprite_setScale(btle->rips, v2f(0.7, 0.7));
		sfSprite_setPosition(btle->rips, p);
		sfRenderWindow_drawSprite(win->win, btle->rips, NULL);
	}
}