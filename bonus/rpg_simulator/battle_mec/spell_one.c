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

int	pala_sone(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	int	e = rand() % 85;

	if (p[tmp->perso].pmlt < 4) {
		my_printf("Vous n'avez pas assez de PM !\n");
		return (3);
	}
	p[tmp->perso].pmlt -= 4;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		my_printf("Votre Paladin lance Consecration !\n");
		pala_sone2(comb, i, p, tmp);
	}
	return (1);
}

int	mage_sone(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	int	e = rand() % 100;

	if (p[tmp->perso].pmlt < 2) {
		my_printf("Vous n'avez pas assez de PM !\n");
		return (3);
	}
	p[tmp->perso].pmlt -= 2;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		my_printf("Votre Mage lance Nova de Givre !\n");
		mage_sone2(comb, i, p, tmp);
	}
	return (1);
}

int	arch_sone(comb_t *comb, int i, chara_t *p, fight_t *tmp)
{
	int	e = rand() % 100;
	int	r = 0;
	int	k = 0;

	if (p[tmp->perso].pmlt < 4) {
		my_printf("Vous n'avez pas assez de PM !\n");
		return (3);
	}
	p[tmp->perso].pmlt -= 4;
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		my_printf("Votre Archer lance Tirs Multiples !\n");
		for (k = 0; comb[i].ennem[k].name != NULL; k ++);
		for (int j = 0; j != 2; j ++) {
			r = rand() % k;
			j -= arch_sone2(&comb[i].ennem[r], p, tmp);
		}
	}
	return (1);
}

int	vole_sone(comb_t *comb, int i, chara_t *p, fight_t *tmp)
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
		my_printf("Votre Voleur lance Assassiner sur le ");
		my_printf("%s adverse !\n", comb[i].ennem[r].name);
		p[tmp->perso].pmlt -= 5;
		return (vole_sone2(&comb[i].ennem[r], p, tmp));
	}
	return (0);
}

int	mene_sone(chara_t *p, fight_t *tmp)
{
	int	e = rand() % 100;

	if (p[tmp->perso].pmlt < 8) {
		my_printf("Vous n'avez pas assez de PM !\n");
		return (3);
	}
	if (e >= p[tmp->perso].prec && e <= 100)
		my_printf("Votre %s rate son attaque !\n", p[tmp->perso].name);
	else {
		my_printf("Votre Menestrel lance Rock N Roll!\n");
		p[tmp->perso].pmlt -= 8;
		for (int r = 0; r != 5; r ++)
			mene_sone2(r, p, tmp);
	}
	return (1);
}