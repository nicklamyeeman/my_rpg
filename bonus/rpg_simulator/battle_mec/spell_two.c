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

int	pala_stwo(chara_t *p, fight_t *tmp)
{
	char	*cmp[6] = {"1", "2", "3", "4", "5", NULL};
	int	r = -1;
	char	*s;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++)
		if (my_strcmp(s, cmp[j]) == 0)
			r = j;
	if (r != -1) {
		if (p[tmp->perso].pmlt < 3) {
			my_printf("Vous n'avez pas assez de PM !\n");
			return (3);
		}
		my_printf("Votre Paladin lance Toucher divin sur ");
		my_printf("votre %s !\n", p[r].name);
		p[tmp->perso].pmlt -= 3;
		return (pala_stwo2(r, p, tmp));
	}
	return (0);
}

int	mage_stwo(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	char	*cmp[7] = {"1", "2", "3", "4", "5", "6", NULL};
	int	r = -1;
	char	*s;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++)
		if (my_strcmp(s, cmp[j]) == 0)
			r = ennem_exist(cmp[j], comb, i);
	if (r != -1) {
		if (p[tmp->perso].pmlt < 5) {
			my_printf("Vous n'avez pas assez de PM !\n");
			return (3);
		}
		my_printf("Votre Mage lance Boule de Feu sur le ");
		my_printf("%s adverse !\n", comb[i].ennem[r].name);
		p[tmp->perso].pmlt -= 5;
		return (mage_stwo2(&comb[i].ennem[r], p, tmp));
	}
	return (0);
}

int	arch_stwo(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	char	*cmp[7] = {"1", "2", "3", "4", "5", "6", NULL};
	int	r = -1;
	char	*s;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++)
		if (my_strcmp(s, cmp[j]) == 0)
			r = ennem_exist(cmp[j], comb, i);
	if (r != -1) {
		if (p[tmp->perso].pmlt < 3) {
			my_printf("Vous n'avez pas assez de PM !\n");
			return (3);
		}
		my_printf("Votre Archer lance Tir Meurtrier sur le ");
		my_printf("%s adverse !\n", comb[i].ennem[r].name);
		p[tmp->perso].pmlt -= 3;
		return (arch_stwo2(&comb[i].ennem[r], p, tmp));
	}
	return (0);
}

int	vole_stwo(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	char	*cmp[7] = {"1", "2", "3", "4", "5", "6", NULL};
	int	r = -1;
	char	*s;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++)
		if (my_strcmp(s, cmp[j]) == 0)
			r = ennem_exist(cmp[j], comb, i);
	if (r != -1) {
		if (p[tmp->perso].pmlt < 4) {
			my_printf("Vous n'avez pas assez de PM !\n");
			return (3);
		}
		my_printf("Votre Voleur lance Evisceration sur le ");
		my_printf("%s adverse !\n", comb[i].ennem[r].name);
		p[tmp->perso].pmlt -= 4;
		return (arch_stwo2(&comb[i].ennem[r], p, tmp));
	}
	return (0);
}

int	mene_stwo(chara_t *p, fight_t *tmp)
{
	int	e = rand() % 100;

	if (p[tmp->perso].pmlt < 4) {
		my_printf("Vous n'avez pas assez de PM !\n");
		return (3);
	}
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		my_printf("Votre Menestrel lance Vague de soins !\n");
		p[tmp->perso].pmlt -= 4;
		for (int r = 0; r != 5; r ++)
			mene_stwo2(r, p, tmp);
	}
	return (1);
}