/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** other fct
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

void	ratk_fct(win_t *win, btle_t *btle, ennem_t *en, chara_t *p)
{
	int	h = btle->tmp->type;
	int	a = btle->tmp->perso;
	int	e = btle->tmp->perso;

	win->f = 30;
	while (win->f == 30) {
		battle_event(win, btle, p, en);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, en);
		if (h < 0) {
			sfText_setPosition(p[a].petex, v2f(200, 745));
			sfRenderWindow_drawText(win->win, p[a].petex, NULL);
		}
		else {
			sfText_setPosition(en[e].entex, v2f(195, 745));
			sfRenderWindow_drawText(win->win, en[e].entex, NULL);
		}
		sfRenderWindow_display(win->win);
	}
}

void	vpap_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 32;
	while (win->f == 32) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	adko_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 34;
	while (win->f == 34) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	crit_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 28;
	while (win->f == 28) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	arch_sone_oth(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	k = 0;

	win->f = 12;
	while (win->f == 12) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	for (k = 0; ennem[k].name != NULL; k ++);
	for (int j = 0; j != 2; j ++) {
		ennem->num = rand() % k;
		j -= arch_sone2(win, ennem, p, btle);
	}
}