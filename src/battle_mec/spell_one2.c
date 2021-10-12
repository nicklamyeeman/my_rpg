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

void	pala_sone2(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	rm;
	int	hplost;
	int	c = rand() % 32;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	if (c == 0)
		crit_fct(win, btle, ennem, p);
	c = (c == 0) ? 2 : 1;
	for (int k = 0; ennem[k].name != NULL; k ++) {
		rm = ennem[k].rm;
		hplost = ((((lvl * 0.4 + 2) * mag * 20) / (rm * 50)) + 2) * c;
		ennem[k].hplt -= hplost;
		ennem->num = k;
		btle->hp = hplost;
		sfText_setCharacterSize(ennem[ennem->num].entex, 85);
		team_touch(win, p, btle, ennem);
	}
}

void	mage_sone2(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	rm;
	int	hplost;
	int	c = rand() % 32;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	if (c == 0)
		crit_fct(win, btle, ennem, p);
	c = (c == 0) ? 2 : 1;
	for (int k = 0; ennem[k].name != NULL; k ++) {
		rm = ennem[k].rm;
		hplost = ((((lvl * 0.4 + 2) * mag * 10) / (rm * 50)) + 2) * c;
		ennem[k].hplt -= hplost;
		ennem->num = k;
		btle->hp = hplost;
		sfText_setCharacterSize(ennem[ennem->num].entex, 85);
		team_touch(win, p, btle, ennem);
	}
}

int	arch_sone2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	hplost;
	int	rm = ennem[ennem->num].rm;
	int	c = rand() % 16;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	if (end_ennem(ennem) == 1)
		return (0);
	if (ennem[ennem->num].hplt == 0)
		return (1);
	if (c == 0)
		crit_fct(win, btle, ennem, p);
	c = (c == 0) ? 2 : 1;
	hplost = ((((lvl * 0.4 + 2) * mag * 30) / (rm * 50)) + 2) * c;
	ennem[ennem->num].hplt -= hplost;
	btle->hp = hplost;
	sfText_setCharacterSize(ennem[ennem->num].entex, 85);
	team_touch(win, p, btle, ennem);
	return (0);
}

int	vole_sone2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = ennem[ennem->num].rm;
	int	hplost = 0;
	int	c = rand() % 8;
	int	e = rand() % 70;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 90) / (rm * 50)) + 2) * c;
		if (c == 2)
			crit_fct(win, btle, ennem, p);
		ennem[ennem->num].hplt -= hplost;
		btle->hp = hplost;
		team_touch(win, p, btle, ennem);
	}
	return (2);
}

void	mene_sone2(win_t *win, ennem_t *ennem, chara_t *p, btle_t *btle)
{
	int	rm = p[p->num].rm;
	int	lvl = p[btle->tmp->perso].lvl;
	int	mag = p[btle->tmp->perso].mg;

	win->f = 18;
	btle->hp = ((((lvl * 0.4 + 2) * mag * 40) / (rm * 50)) + 2);
	p[p->num].pmlt += btle->hp;
	while (win->f == 18) {
		sfText_setString(btle->hptex, int_to_char(btle->hp));
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	if (p[p->num].pmlt > p[p->num].pmmx)
		p[p->num].pmlt = p[p->num].pmmx;
}