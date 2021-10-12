/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** spell one
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

int	pala_stwo2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = p[p->num].rm;
	int	e = rand() % 100;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		btle->hp = ((((lvl * 0.4 + 2) * mag * 60) / (rm * 50)) + 2);
		p[p->num].hplt += btle->hp;
		while (win->f == 16) {
			sfText_setString(btle->hptex, int_to_char(btle->hp));
			battle_event(win, btle, p, ennem);
			sfRenderWindow_clear(win->win, sfWhite);
			display_window(win, btle, p, ennem);
			sfRenderWindow_display(win->win);
		}
		if (p[p->num].hplt > p[p->num].hpmx)
			p[p->num].hplt = p[p->num].hpmx;
	}
	return (2);
}

int	mage_stwo2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = ennem[ennem->num].rm;
	int	hplost = 0;
	int	c = rand() % 32;
	int	e = rand() % 90;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 55) / (rm * 50)) + 2) * c;
		if (c == 2)
			crit_fct(win, btle, ennem, p);
		ennem[ennem->num].hplt -= hplost;
		btle->hp = hplost;
		team_touch(win, p, btle, ennem);
	}
	return (2);
}

int	arch_stwo2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = ennem[ennem->num].rm;
	int	hplost = 0;
	int	c = rand() % 32;
	int	e = rand() % 85;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 50) / (rm * 50)) + 2) * c;
		if (c == 2)
			crit_fct(win, btle, ennem, p);
		ennem[ennem->num].hplt -= hplost;
		btle->hp = hplost;
		team_touch(win, p, btle, ennem);
	}
	return (2);
}

int	vole_stwo2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = ennem[ennem->num].rm;
	int	hplost = 0;
	int	c = rand() % 16;
	int	e = rand() % 90;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 60) / (rm * 50)) + 2) * c;
		if (c == 2)
			crit_fct(win, btle, ennem, p);
		ennem[ennem->num].hplt -= hplost;
		btle->hp = hplost;
		team_touch(win, p, btle, ennem);
	}
	return (2);
}

void	mene_stwo2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = p[p->num].rm;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	win->f = 16;
	btle->hp = ((((lvl * 0.4 + 2) * mag * 40) / (rm * 50)) + 2);
	p[p->num].hplt += btle->hp;
	while (win->f == 16) {
		sfText_setString(btle->hptex, int_to_char(btle->hp));
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	if (p[p->num].hplt > p[p->num].hpmx)
		p[p->num].hplt = p[p->num].hpmx;
}