/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** team turn
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

int	will_you_run(void)
{
	int	r = rand() % 100;

	if (r >= 0 && r <= 9) {
		my_printf("\nVous prenez la fuite.\n");
		return (3);
	}
	else {
		my_printf("\nVous n'avez pas reussi a fuir.\n");
		return (2);
	}
}

int	resume_fight(comb_t *comb, int i, chara_t *perso)
{
	print_team(perso);
	my_putstr("\n\n\t\t");
	print_ennemies(comb, i);
	my_putchar('\n');
	return (0);
}

int	do_in_fight(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	char	*cmp[5] = {"Attaquer", "Sort", "Resume", "Fuir", NULL};
	int	r = 0;
	char	*s;

	s = get_next_line(0);
	for (int j = 0; cmp[j] != NULL; j ++) {
		if (my_strcmp(s, cmp[j]) == 0) {
			r = (j == 0) ? let_hurt_them(comb, i, perso, tmp) : r;
			r = (j == 1) ? let_spell_us(comb, i, perso, tmp) : r;
			r = (j == 2) ? resume_fight(comb, i, perso) : r;
			r = (j == 3) ? will_you_run() : r;
			return (r);
		}
	}
	return (1);
}

int	team_turn(comb_t *comb, int i, chara_t *perso, fight_t *tmp)
{
	int	t = 0;

	if (perso[tmp->perso].hplt < 0)
		return (2);
	my_printf("\nC'est au tour de votre %s.\n", perso[tmp->perso].name);
	while (t < 2) {
		if (t == 0) {
			my_printf("\nChoisissez une action à faire:\n");
			my_printf("Attaquer: Attaquez un adversaire.\n");
			my_printf("Sort: Lancez un sort sur vos ");
			my_printf("ennemis ou sur vos allies.\n");
			my_printf("Resume: Observez les statistiques du");
			my_printf(" combat en cours.\nFuir: Fuyez pauvre");
			my_printf(" fou !\n");
		}
		t = do_in_fight(comb, i, perso, tmp);
	}
	return (t);
}