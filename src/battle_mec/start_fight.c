/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** start_fight
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

void	vod_for_boss(win_t *win, int vod)
{
	if (vod == 1)
		win->boss = 2;
	else
		win->boss = 0;
}

void	fainted_ennemy(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	int	vod = -1;

	display_window(win, btle, p, ennem);
	if (win->f != 0) {
		vod = go_fight(win, btle, ennem, p);
		if (vod == 1) {
			victory_nxp(win, btle, ennem, p);
			win->loop = 0;
		}
		if (vod == 0) {
			vapc_fct(win, btle, ennem, p);
			win->loop = 0;
		}
		if (vod == 2)
			win->loop = 0;
		if (win->boss == 1)
			vod_for_boss(win, vod);
		return;
	}
}

void	start_fight(win_t *win, comb_t *comb, chara_t *p)
{
	int	i = rand() % 5;
	int	k = 0;
	btle_t btle;

	win->loop = 1;
	if (win->boss == 1)
		i = 5;
	init_battle(&btle);
	while (win->loop) {
		battle_event(win, &btle, p, comb[i].ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		fainted_ennemy(win, &btle, p, comb[i].ennem);
		sfRenderWindow_display(win->win);
	}
	win->loop = 1;
}
