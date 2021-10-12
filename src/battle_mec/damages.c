/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** dmaages
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

int	get_maxexp(chara_t *perso, int j)
{
	int	i = 1;
	int	xpmax = 0;

	while (i != (perso[0].lvl + j + 1)) {
		xpmax += (i * 50);
		i ++;
	}
	return (xpmax);
}

void	update_ennemy(ennem_t *ennem, chara_t *perso)
{
	for (int j = 0; ennem[j].name != NULL; j++) {
		ennem[j].coef = (perso[0].lvl + 1);
		ennem[j].hpmx *= ennem[j].coef / 2;
		ennem[j].hplt = ennem[j].hpmx;
		ennem[j].atk *= ennem[j].coef / 2;
		ennem[j].mag *= ennem[j].coef / 2;
		ennem[j].def *= ennem[j].coef / 2;
		ennem[j].rm *= ennem[j].coef / 2;
		ennem[j].vit *= ennem[j].coef / 2;
		ennem[j].exp *= ennem[j].coef / 2;
	}
}

void	update_perso(chara_t *perso, int k)
{
	perso[k].lvl += 1;
	perso[k].hpmx += ((perso[k].hpmx + 10) / 5);
	perso[k].hplt = perso[k].hpmx;
	perso[k].pmmx += ((perso[k].pmmx + 10) / 10);
	perso[k].pmlt = perso[k].pmmx;
	perso[k].def += ((perso[k].def + 10) / 10);
	perso[k].rm += ((perso[k].rm + 10) / 10);
	perso[k].atk += ((perso[k].atk + 10) / 10);
	perso[k].mg += ((perso[k].mg + 10) / 10);
	perso[k].vit += ((perso[k].vit + 10) / 10);
	perso[k].pc += 2;
	if (perso[k].lvl % 10 == 0)
		perso[k].esc += 5;
}

int	level_up(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	btle->xp = (btle->xp - btle->xpmax);
	btle->xpmax = get_maxexp(perso, 1);
	for (int k = 0; k != 5; k ++)
		update_perso(perso, k);
	if (btle->xp >= btle->xpmax)
		btle->xp = level_up(win, btle, ennem, perso);
	else {
		btle->hp = perso[0].lvl;
		fepn_fct(win, btle, ennem, perso);
	}
	return (btle->xp);
}

void	victory_nxp(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	getxp = 0;

	btle->xpmax = get_maxexp(p, 0);
	btle->xp = p[0].exp;
	vvme_fct(win, btle, ennem, p);
	update_ennemy(ennem, p);
	for (int j = 0; ennem[j].name != NULL; j ++)
		getxp += ennem[j].exp;
	btle->hp = getxp;
	verx_fct(win, btle, ennem, p);
	btle->xp += getxp;
	if (btle->xp >= btle->xpmax)
		btle->xp = level_up(win, btle, ennem, p);
	for (int k = 0; k != 5; k ++)
		p[k].exp = btle->xp;
}