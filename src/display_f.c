/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** display f
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

void	toch_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.tochs, NULL);
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
	sfText_setPosition(ennem[ennem->num].entex, v2f(210, 740));
	sfRenderWindow_drawText(win->win, ennem[ennem->num].entex, NULL);
	sfText_setPosition(btle->hptex, v2f(940, 740));
	sfRenderWindow_drawText(win->win, btle->hptex, NULL);
	if (ennem[ennem->num].hplt <= 0) {
		ennem[ennem->num].hplt = 0;
		sfRenderWindow_drawSprite(win->win, btle->turn.aekos, NULL);
	}
}

void	vpae_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vpaes, NULL);
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
	sfText_setPosition(p[btle->tmp->perso].petex, v2f(290, 740));
	sfText_setCharacterSize(p[btle->tmp->perso].petex, 85);
	sfText_setPosition(ennem[ennem->num].entex, v2f(940, 740));
	sfText_setCharacterSize(ennem[ennem->num].entex, 85);
	sfRenderWindow_drawText(win->win, p[btle->tmp->perso].petex, NULL);
	sfRenderWindow_drawText(win->win, ennem[ennem->num].entex, NULL);
}

void	qvva_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.qvvas, NULL);
	sfRenderWindow_drawSprite(win->win, ennem[ennem->num].arros, NULL);
}

void	qdfv_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.qdfvs, NULL);
	sfRenderWindow_drawSprite(win->win, btle->turn.asefs, NULL);
	btle->turn.artim = sfClock_getElapsedTime(btle->turn.arclo);
	if (sfTime_asSeconds(btle->turn.artim) > 0.3) {
		if (btle->turn.arrec.left == 40)
			btle->turn.arrec.left = 0;
		else
			btle->turn.arrec.left += 40;
		sfSprite_setTextureRect(btle->turn.arros, btle->turn.arrec);
		sfClock_restart(btle->turn.arclo);
	}
	sfRenderWindow_drawSprite(win->win, btle->turn.arros, NULL);
	sfText_setPosition(p[btle->tmp->perso].petex, v2f(120, 840));
	sfText_setCharacterSize(p[btle->tmp->perso].petex, 85);
	sfRenderWindow_drawText(win->win, p[btle->tmp->perso].petex, NULL);
}

void	dmva_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.dmvas, NULL);
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