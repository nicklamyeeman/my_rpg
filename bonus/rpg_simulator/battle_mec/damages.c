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

void	update_ennemy(comb_t *comb, int i, chara_t *perso)
{
	for (int j = 0; comb[i].ennem[j].name != NULL; j++) {
		comb[i].ennem[j].coef = (perso[0].lvl + 1);
		comb[i].ennem[j].hpmx *= comb[i].ennem[j].coef / 2;
		comb[i].ennem[j].hplt = comb[i].ennem[j].hpmx;
		comb[i].ennem[j].atk *= comb[i].ennem[j].coef / 2;
		comb[i].ennem[j].mag *= comb[i].ennem[j].coef / 2;
		comb[i].ennem[j].def *= comb[i].ennem[j].coef / 2;
		comb[i].ennem[j].rm *= comb[i].ennem[j].coef / 2;
		comb[i].ennem[j].vit *= comb[i].ennem[j].coef / 2;
		comb[i].ennem[j].exp *= comb[i].ennem[j].coef / 2;
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

int	level_up(int xp, int xpmax, chara_t *perso)
{
	xp = (xp - xpmax);
	xpmax = get_maxexp(perso, 1);
	for (int k = 0; k != 5; k ++)
		update_perso(perso, k);
	if (xp >= xpmax)
		xp = level_up(xp, xpmax, perso);
	else {
		my_printf("\nFélicitations ! Votre équipe passe au niveau ");
		my_printf("%d\n", perso[0].lvl);
		my_printf("--Vous avez 2 nouveaux points de compétences--");
	}
	return (xp);
}

void	victory_nxp(comb_t *comb, int i, chara_t *perso)
{
	int	xpmax = get_maxexp(perso, 0);
	int	xp = perso[0].exp;
	int	getxp = 0;

	update_ennemy(comb, i, perso);
	for (int j = 0; comb[i].ennem[j].name != NULL; j ++)
		getxp += comb[i].ennem[j].exp;
	my_printf("\nExpérience reçue par membre de l'équipe: %d\n", getxp);
	xp += getxp;
	if (xp >= xpmax)
		xp = level_up(xp, xpmax, perso);
	for (int k = 0; k != 5; k ++)
		perso[k].exp = xp;
}