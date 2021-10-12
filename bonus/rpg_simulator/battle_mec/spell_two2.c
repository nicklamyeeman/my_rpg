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

int	pala_stwo2(int r, chara_t *p, fight_t *tmp)
{
	int	hpp;
	int	hplost;
	int	rm = p[r].rm;
	int	e = rand() % 100;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		hpp = ((((lvl * 0.4 + 2) * mag * 60) / (rm * 50)) + 2);
		p[r].hplt += hpp;
		my_printf("Votre %s recupere", p[r].name);
		my_printf(" %d point(s) de vie.\n", hpp);
		if (p[r].hplt > p[r].hpmx)
			p[r].hplt = p[r].hpmx;
	}
	return (1);
}

int	mage_stwo2(ennem_t *ennem, chara_t *p, fight_t *tmp)
{
	int	rm = ennem->rm;
	int	hplost = 0;
	int	c = rand() % 32;
	int	e = rand() % 90;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 55) / (rm * 50)) + 2) * c;
		if (c == 2)
			my_printf("Coup critique !\n");
		ennem->hplt -= hplost;
		team_touch(p, tmp, ennem, hplost);
	}
	return (1);
}

int	arch_stwo2(ennem_t *ennem, chara_t *p, fight_t *tmp)
{
	int	rm = ennem->rm;
	int	hplost = 0;
	int	c = rand() % 32;
	int	e = rand() % 85;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 50) / (rm * 50)) + 2) * c;
		if (c == 2)
			my_printf("Coup critique !\n");
		ennem->hplt -= hplost;
		team_touch(p, tmp, ennem, hplost);
	}
	return (1);
}

int	vole_stwo2(ennem_t *ennem, chara_t *p, fight_t *tmp)
{
	int	rm = ennem->rm;
	int	hplost = 0;
	int	c = rand() % 16;
	int	e = rand() % 90;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	c = (c == 0) ? 2 : 1;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		hplost = ((((lvl * 0.4 + 2) * mag * 60) / (rm * 50)) + 2) * c;
		if (c == 2)
			my_printf("Coup critique !\n");
		ennem->hplt -= hplost;
		team_touch(p, tmp, ennem, hplost);
	}
	return (1);
}

void	mene_stwo2(int r, chara_t *p, fight_t *tmp)
{
	int	hpp;
	int	hplost;
	int	rm = p[r].rm;
	int	lvl = p[tmp->perso].lvl;
	int	mag = p[tmp->perso].mg;

	hpp = ((((lvl * 0.4 + 2) * mag * 40) / (rm * 50)) + 2);
	p[r].hplt += hpp;
	my_printf("Votre %s recupere", p[r].name);
	my_printf(" %d point(s) de vie.\n", hpp);
	if (p[r].hplt > p[r].hpmx)
		p[r].hplt = p[r].hpmx;
}