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

void	update_spell2(win_t *win, chara_t *p, int h, int occ)
{
	sfRenderWindow_drawSprite(win->win, p->spell.spe2s, NULL);
	if (p->spell.s2rec.top == (h * occ)) {
		p->spell.s2rec.left = 0;
		p->spell.s2rec.top = 0;
		win->f = 13;
	}
}

void	update_spell(win_t *win, chara_t *p, int h, int occ)
{
	sfRenderWindow_drawSprite(win->win, p->spell.spe1s, NULL);
	if (p->spell.s1rec.top == (h * occ)) {
		p->spell.s1rec.left = 0;
		p->spell.s1rec.top = 0;
		win->f = 13;
	}
}

void	bteq_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->bgs, NULL);
	display_teamt(win, btle, p);
	display_ennem(win, btle, ennem);
	sfRenderWindow_drawSprite(win->win, btle->turn.bteqs, NULL);
}

void	fepn_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.fepns, NULL);
	sfText_setPosition(btle->hptex, v2f(1250, 770));
	sfSprite_setPosition(btle->nexts, v2f(1490, 770));
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

void	vapc_display(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->turn.vapcs, NULL);
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