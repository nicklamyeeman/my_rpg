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

void	verx_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.verxs, NULL);
	sfText_setPosition(btle->hptex, v2f(640, 770));
	sfSprite_setPosition(btle->nexts, v2f(1390, 770));
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
	sfRenderWindow_drawText(win->win, btle->hptex, NULL);
}

void	vvme_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vvmes, NULL);
	sfSprite_setPosition(btle->nexts, v2f(1130, 770));
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

void	adko_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.adkos, NULL);
	sfSprite_setPosition(btle->nexts, v2f(870, 760));
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

void	vpap_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vpaps, NULL);
	sfSprite_setPosition(btle->nexts, v2f(890, 740));
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

void	ratk_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.ratks, NULL);
	sfSprite_setPosition(btle->nexts, v2f(990, 740));
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
