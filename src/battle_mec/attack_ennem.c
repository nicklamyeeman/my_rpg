/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** attack
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

int	ennem_exist(win_t *win, btle_t *btle, chara_t *perso, ennem_t *ennem)
{
	int	c = ennem->num;

	if (!ennem[c].name)
		return (-1);
	else if (ennem[c].hplt <= 0) {
		sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
		adko_fct(win, btle, ennem, perso);
		return (-1);
	}
	else
		return (c);
}

int	full_face(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	int	hplost;
	int	e = rand() % 100;
	int	c = rand() % 16;
	int	lvl = p[btle->tmp->perso].lvl;
	int	atk = p[btle->tmp->perso].atk;
	int	def = ennem[ennem->num].def;

	if (c == 0) {
		crit_fct(win, btle, ennem, p);
		c = 2;
	}
	else
		c = 1;
	hplost = ((((lvl * 0.4 + 2) * atk * 20) / (def * 50)) + 2) * c;
	if (atk == 0)
		hplost = 0;
	if (e >= p[btle->tmp->perso].prec && e <= 100) {
		ratk_fct(win, btle, ennem, p);
		return (0);
	}
	return (hplost);
}

int	team_touch(win_t *win, chara_t *perso, btle_t *btle, ennem_t *ennem)
{
	win->f = 8;
	while (win->f == 8) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		sfText_setString(btle->hptex, int_to_char(btle->hp));
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
	return (2);
}

int	choose_victim(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	hplost = 0;

	win->f = 6;
	while (win->f == 6) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	ennem[ennem->num].hplt -= (hplost = full_face(win, btle, p, ennem));
	btle->hp = hplost;
	if (ennem[ennem->num].hplt <= 0)
		ennem[ennem->num].hplt = 0;
	return (team_touch(win, p, btle, ennem));
}

int	let_hurt_them(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	t = 0;

	win->f = 4;
	ennem->num = 0;
	while (t != 1 && win->f < 6) {
		if (win->f == 2)
			return (1);
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		if (win->f == 5)
			t = choose_victim(win, btle, ennem, p);
		sfRenderWindow_display(win->win);
	}
	return (t);
}