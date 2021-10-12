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

int	ennem_exist(char *cmp, comb_t *comb, int i)
{
	int	c = my_getnbr(cmp);

	if (!comb[i].ennem[c - 1].name)
		return (-1);
	else if (comb[i].ennem[c - 1].hplt <= 0) {
		my_printf("Cet adversaire est deja K.O.\n");
		return (-1);
	}
	else
		return (c - 1);
}

int	full_face(chara_t *p, fight_t *tmp, int def)
{
	int	hplost;
	int	e = rand() % 100;
	int	c = rand() % 16;
	int	lvl = p[tmp->perso].lvl;
	int	atk = p[tmp->perso].atk;

	if (c == 0) {
		my_printf("Coup critique !\n");
		c = 2;
	}
	else
		c = 1;
	hplost = ((((lvl * 0.4 + 2) * atk * 20) / (def * 50)) + 2) * c;
	if (atk == 0)
		hplost = 0;
	if (e >= p[tmp->perso].prec && e <= 100) {
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
		return (0);
	}
	return (hplost);
}

int	team_touch(chara_t *perso, fight_t *tmp, ennem_t *ennem, int hplost)
{
	my_printf("Le %s adverse perd", ennem->name);
	my_printf(" %d point(s) de vie.\n", hplost);
	if (ennem->hplt <= 0) {
		ennem->hplt = 0;
		my_printf("Le %s adverse est K.O.\n", ennem->name);
	}
	return (1);
}

int	choose_victim(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	char	*cmp[7] = {"1", "2", "3", "4", "5", "6", NULL};
	int	hplost = 0;
	int	r = -1;
	int	def;
	char	*s;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++)
		if (my_strcmp(s, cmp[j]) == 0)
			r = ennem_exist(cmp[j], comb, i);
	if (r != -1) {
		my_printf("Votre %s attaque le", perso[tmp->perso].name);
		my_printf(" %s adverse.\n", comb[i].ennem[r].name);
		def = comb[i].ennem[r].def;
		comb[i].ennem[r].hplt -= (hplost = full_face(perso, tmp, def));
		if (comb[i].ennem[r].hplt <= 0)
			comb[i].ennem[r].hplt = 0;
		return (team_touch(perso, tmp, &comb[i].ennem[r], hplost));
	}
	return (0);
}

int	let_hurt_them(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	e = 0;
	int	t = 0;

	for (e = 0; comb[i].ennem[e].name != NULL; e ++);
	my_printf("\nQui voulez vous attaquer ?\n");
	for (int n = 0; n != e; n ++) {
		my_printf("%d: ", n + 1);
		my_printf("%s\n", comb[i].ennem[n].name);
	}
	while (t != 1)
		t = choose_victim(comb, i, perso, tmp);
	return (2);
}