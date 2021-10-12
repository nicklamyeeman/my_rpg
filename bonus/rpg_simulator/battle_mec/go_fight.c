/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** go fight
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

void	ennem_touch(chara_t *perso, int k, int hplost, int c)
{
	int	e = rand() % 100;

	if (e >= 0 && e <= (perso[k].esc - 1))
		my_printf("Votre %s esquive l'attaque !\n", perso[k].name);
	else {
		if (c == 2)
			my_printf("Coup critique !\n");
		perso[k].hplt -= hplost;
		my_printf("Votre %s perd", perso[k].name);
		my_printf(" %d point(s) de vie.\n", hplost);
		if (perso[k].hplt <= 0) {
			perso[k].hplt = 0;
			my_printf("Votre %s est K.O.\n", perso[k].name);
		}
	}
}

void	ennem_atk(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	k = rand() % 5;
	int	c = rand() % 16;
	int	lvl = comb[i].ennem[tmp->perso].coef;
	int	atk = comb[i].ennem[tmp->perso].atk;
	int	def = perso[k].def;
	int	hplost;

	while (perso[k].hplt == 0)
		k = rand() % 5;
	my_printf("\nLe %s attaque votre", comb[i].ennem[tmp->perso].name);
	my_printf(" %s !\n", perso[k].name);
	if (c == 0)
		c = 2;
	else
		c = 1;
	hplost = ((((lvl * 0.4 + 2) * atk * 20) / (def * 50)) + 2) * c;
	if (atk == 0)
		hplost = 0;
	ennem_touch(perso, k, hplost, c);
}

void	ennem_turn(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	if (comb[i].ennem[tmp->perso].hplt <= 0)
		return;
	else
		ennem_atk(comb, i, perso, tmp);
}

int	analyse_turn(comb_t *comb, int i, chara_t *perso, fight_t *order)
{
	int	h = 0;
	int	e = 0;
	fight_t *tmp = order;

	while (end_team(perso) != 1 && end_ennem(comb, i) != 1) {
		h = tmp->type;
		if (h < 0)
			e = team_turn(comb, i, perso, tmp);
		else
			ennem_turn(comb, i, perso, tmp);
		if (e == 3)
			return (2);
		if (tmp->next == NULL)
			tmp = order;
		else
			tmp = tmp->next;
	}
	if (end_team(perso) == 1)
		return (0);
	else if (end_ennem(comb, i) == 1)
		return (1);
}

int	go_fight(comb_t *comb, int i, chara_t *perso)
{
	fight_t	*order = NULL;

	for (int k = 0; k != 5; k ++)
		my_put_in_listp(perso, k, -1, &order);
	for (int k = 0; comb[i].ennem[k].name != NULL; k ++)
		my_put_in_listc(comb, k, i, &order);
	sort(&order);
	for (int g = 0; comb[i].ennem[g].name != NULL; g ++)
		comb[i].ennem[g].hplt = comb[i].ennem[g].hpmx;
	return (analyse_turn(comb, i, perso, order));
}