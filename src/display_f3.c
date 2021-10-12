/*
** EPITECH PROJECT, 2018
** prg
** File description:
** display f 2
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

void	crit_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.crits, NULL);
	sfSprite_setPosition(btle->nexts, v2f(490, 740));
	btle->netim = sfClock_getElapsedTime(btle->neclo);
	if (sfTime_asSeconds(btle->netim) > 0.3) {
		if (btle->nerec.left == 90)
			btle->nerec.left = 0;
		else
			btle->nerec.left += 90;
		sfSprite_setTextureRect(btle->nexts, btle->nerec);
		sfClock_restart(btle->neclo);
	}
	sfRenderWindow_drawSprite(win->win, btle->nexts, NULL);
}

void	ento_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vppps, NULL);
	sfSprite_setPosition(btle->nexts, v2f(1520, 740));
	btle->netim = sfClock_getElapsedTime(btle->neclo);
	if (sfTime_asSeconds(btle->netim) > 0.3) {
		if (btle->nerec.left == 90)
			btle->nerec.left = 0;
		else
			btle->nerec.left += 90;
		sfSprite_setTextureRect(btle->nexts, btle->nerec);
		sfClock_restart(btle->neclo);
	}
	sfRenderWindow_drawSprite(win->win, btle->nexts, NULL);
	sfText_setPosition(p[p->num].petex, v2f(310, 740));
	sfRenderWindow_drawText(win->win, p[p->num].petex, NULL);
	sfText_setPosition(btle->hptex, v2f(820, 740));
	sfRenderWindow_drawText(win->win, btle->hptex, NULL);
	if (p[p->num].hplt <= 0) {
		p[p->num].hplt = 0;
		sfRenderWindow_drawSprite(win->win, btle->turn.aekos, NULL);
	}
}

void	eavp_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.eavps, NULL);
	sfSprite_setPosition(btle->nexts, v2f(1390, 735));
	btle->netim = sfClock_getElapsedTime(btle->neclo);
	if (sfTime_asSeconds(btle->netim) > 0.3) {
		if (btle->nerec.left == 90)
			btle->nerec.left = 0;
		else
			btle->nerec.left += 90;
		sfSprite_setTextureRect(btle->nexts, btle->nerec);
		sfClock_restart(btle->neclo);
	}
	sfRenderWindow_drawSprite(win->win, btle->nexts, NULL);
	sfText_setPosition(p[p->num].petex, v2f(1140, 740));
	sfText_setCharacterSize(p[p->num].petex, 85);
	sfText_setPosition(ennem[btle->tmp->perso].entex, v2f(230, 740));
	sfText_setCharacterSize(ennem[btle->tmp->perso].entex, 85);
	sfRenderWindow_drawText(win->win, p[p->num].petex, NULL);
	sfRenderWindow_drawText(win->win, ennem[btle->tmp->perso].entex, NULL);
}

void	vprm_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vprms, NULL);
	sfSprite_setPosition(btle->nexts, v2f(1390, 765));
	btle->netim = sfClock_getElapsedTime(btle->neclo);
	if (sfTime_asSeconds(btle->netim) > 0.3) {
		if (btle->nerec.left == 90)
			btle->nerec.left = 0;
		else
			btle->nerec.left += 90;
		sfSprite_setTextureRect(btle->nexts, btle->nerec);
		sfClock_restart(btle->neclo);
	}
	sfText_setCharacterSize(p[p->num].petex, 80);
	sfRenderWindow_drawSprite(win->win, btle->nexts, NULL);
	sfText_setPosition(p[p->num].petex, v2f(290, 769));
	sfRenderWindow_drawText(win->win, p[p->num].petex, NULL);
	sfText_setPosition(btle->hptex, v2f(870, 769));
	sfRenderWindow_drawText(win->win, btle->hptex, NULL);
}

void	heal_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vprps, NULL);
	sfSprite_setPosition(btle->nexts, v2f(1390, 765));
	btle->netim = sfClock_getElapsedTime(btle->neclo);
	if (sfTime_asSeconds(btle->netim) > 0.3) {
		if (btle->nerec.left == 90)
			btle->nerec.left = 0;
		else
			btle->nerec.left += 90;
		sfSprite_setTextureRect(btle->nexts, btle->nerec);
		sfClock_restart(btle->neclo);
	}
	sfText_setCharacterSize(p[p->num].petex, 80);
	sfRenderWindow_drawSprite(win->win, btle->nexts, NULL);
	sfText_setPosition(p[p->num].petex, v2f(290, 769));
	sfRenderWindow_drawText(win->win, p[p->num].petex, NULL);
	sfText_setPosition(btle->hptex, v2f(870, 769));
	sfRenderWindow_drawText(win->win, btle->hptex, NULL);
}