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

void	pala_sone2(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	int	rm;
	int	hplost;
	int	c = rand() % 32;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	if (c == 0)
		my_printf("Coup critique !\n");
	c = (c == 0) ? 2 : 1;
	for (int k = 0; comb[i].ennem[k].name != NULL; k ++) {
		rm = comb[i].ennem[k].rm;
		hplost = ((((lvl * 0.4 + 2) * mag * 20) / (rm * 50)) + 2) * c;
		comb[i].ennem[k].hplt -= hplost;
		team_touch(p, tmp, &comb[i].ennem[k], hplost);
	}
}

void	mage_sone2(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	int	rm;
	int	hplost;
	int	c = rand() % 32;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	if (c == 0)
		my_printf("Coup critique !\n");
	c = (c == 0) ? 2 : 1;
	for (int k = 0; comb[i].ennem[k].name != NULL; k ++) {
		rm = comb[i].ennem[k].rm;
		hplost = ((((lvl * 0.4 + 2) * mag * 10) / (rm * 50)) + 2) * c;
		comb[i].ennem[k].hplt -= hplost;
		team_touch(p, tmp, &comb[i].ennem[k], hplost);
	}
}

int	arch_sone2(ennem_t *ennem, chara_t *p, fight_t *tmp)
{
	int	hplost;
	int	rm = ennem->rm;
	int	c = rand() % 16;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	if (ennem->hplt == 0)
		return (1);
	if (c == 0)
		my_printf("Coup critique !\n");
	c = (c == 0) ? 2 : 1;
	hplost = ((((lvl * 0.4 + 2) * mag * 30) / (rm * 50)) + 2) * c;
	ennem->hplt -= hplost;
	team_touch(p, tmp, ennem, hplost);
	return (0);
}

int	vole_sone2(ennem_t *ennem, chara_t *p, fight_t *tmp)
{
	int	rm = ennem->rm;
	int	hplost = 0;
	int	c = rand() % 8;
	int	e = rand() % 70;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 90) / (rm * 50)) + 2) * c;
		if (c == 2)
			my_printf("Coup critique !\n");
		ennem->hplt -= hplost;
		team_touch(p, tmp, ennem, hplost);
	}
	return (1);
}

void	mene_sone2(int r, chara_t *p, fight_t *tmp)
{
	int	pmp;
	int	hplost;
	int	rm = p[r].rm;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	pmp = ((((lvl * 0.4 + 2) * mag * 40) / (rm * 50)) + 2);
	p[r].pmlt += pmp;
	my_printf("Votre %s recupere", p[r].name);
	my_printf(" %d point(s) de mana.\n", pmp);
	if (p[r].pmlt > p[r].pmmx)
		p[r].pmlt = p[r].pmmx;
}