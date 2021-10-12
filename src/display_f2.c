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

void	qvvs_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.qvvss, NULL);
	sfRenderWindow_drawSprite(win->win, p[p->num].arros, NULL);
}

void	vplf_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vplfs, NULL);
	sfSprite_setPosition(btle->nexts, v2f(650, 765));
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

void	vprf_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vprfs, NULL);
	sfSprite_setPosition(btle->nexts, v2f(920, 765));
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

void	vpls_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfVector2f	a = sfSprite_getPosition(btle->turn.arros);

	(a.x == 70 && a.y == 895) ? cast_pone(win, btle, p, ennem) : 0;
	(a.x == 70 && a.y == 965) ? cast_ptwo(win, btle, p, ennem) : 0;
}

void	qsvl_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	int	c = btle->tmp->perso;

	sfRenderWindow_drawSprite(win->win, btle->turn.qsvls, NULL);
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
	sfRenderWindow_drawText(win->win, p[c].spell.s1tex, NULL);
	sfRenderWindow_drawText(win->win, p[c].spell.s2tex, NULL);
}