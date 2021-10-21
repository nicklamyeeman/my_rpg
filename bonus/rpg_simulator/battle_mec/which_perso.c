/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** which perso
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

void	before_help(chara_t *perso)
{
	my_printf("\nQui voulez vous soigner ?\n");
	for (int n = 0; n != 5; n ++) {
		my_printf("%d: ", n + 1);
		my_printf("%s\n", perso[n].name);
	}
}

void	before_spell(comb_t *comb, int i)
{
	int	e = 0;

	for (e = 0; comb[i].ennem[e].name != NULL; e ++);
	my_printf("\nQui voulez vous attaquer ?\n");
	for (int n = 0; n != e; n ++) {
		my_printf("%d: ", n + 1);
		my_printf("%s\n", comb[i].ennem[n].name);
	}
}

int	which_pone(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	ret = 1;
	int	t = 0;

	if (tmp->perso == 0)
		ret = pala_sone(comb, i, perso, tmp);
	if (tmp->perso == 1)
		ret = mage_sone(comb, i, perso, tmp);
	if (tmp->perso == 2)
		ret = arch_sone(comb, i, perso, tmp);
	if (tmp->perso == 3) {
		before_spell(comb, i);
		while (t < 1)
			t = vole_sone(comb, i, perso, tmp);
		ret = t;
	}
	if (tmp->perso == 4)
		ret = mene_sone(perso, tmp);
	return (ret);
}

int	which_ptwo2(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	t = 0;

	if (tmp->perso == 3) {
		before_spell(comb, i);
		while (t < 1)
			t = vole_stwo(comb, i, perso, tmp);
	}
	if (tmp->perso == 4)
		t = mene_stwo(perso, tmp);
	return (t);
}

int	which_ptwo(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	t = 0;

	if (tmp->perso == 0) {
		before_help(perso);
		while (t < 1)
			t = pala_stwo(perso, tmp);
	}
	if (tmp->perso == 1) {
		before_spell(comb, i);
		while (t < 1)
			t = mage_stwo(comb, i, perso, tmp);
	}
	if (tmp->perso == 2) {
		before_spell(comb, i);
		while (t < 1)
			t = arch_stwo(comb, i, perso, tmp);
	}
	if (t >= 1)
		return (t);
	else
		return (which_ptwo2(comb, i, perso, tmp));
}