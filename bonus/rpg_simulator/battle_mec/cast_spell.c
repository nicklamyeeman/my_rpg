/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** spell
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

int	choose_target(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	char	*cmp[4] = {"1", "2", "Retour", NULL};
	char	*s;
	int	r = 0;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++) {
		if (my_strcmp(s, cmp[j]) == 0) {
			r = (j == 0) ? which_pone(comb, i, perso, tmp) : r;
			r = (j == 1) ? which_ptwo(comb, i, perso, tmp) : r;
			r = (j == 2) ? 3 : r;
			return (r);
		}
	}
	return (0);
}

int	let_spell_us(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	t = 0;

	my_printf("\nQuel sort souhaitez-vous lancer ?\n");
	my_printf("1: %s", perso[tmp->perso].spell.spell1);
	my_printf("2: %s", perso[tmp->perso].spell.spell2);
	my_printf("Retour\n");
	while (t != 1) {
		t = choose_target(comb, i, perso, tmp);
		if (t == 3)
			return (0);
	}
	return (2);
}