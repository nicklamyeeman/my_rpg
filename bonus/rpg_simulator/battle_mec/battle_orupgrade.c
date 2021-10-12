/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** battle or upgrade
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

int	the_upgrade(chara_t *perso)
{
	if (perso[0].pc == 0) {
		my_printf("\nVous n'avez pas de point de compétence");
		my_printf(" à dépenser\n");
		return (0);
	}
	else {
		for (int k = 0; k != 5; k ++) {
			my_printf("\n%s\n", perso[k].name);
			upgrade_hero(perso, k);
		}
	}
	return (0);
}

int	option_chosen(chara_t *perso, comb_t *comb, char *s, int print)
{
	char	*cmp[5] = {"Upgrade", "Team", "Fight", "Quit", NULL};

	for (int i = 0; cmp[i] != NULL; i ++) {
		if (my_strcmp(s, cmp[i]) == 0) {
			print = (i == 0) ? the_upgrade(perso) : 0;
			print = (i == 1) ? print_team(perso) : 0;
			print = (i == 2) ? start_fight(comb, perso) : 0;
			print = (i == 3) ? 2 : 0;
			return (print);
		}
	}
	return (1);
}

void	battle_orupgrade(chara_t *perso, comb_t *comb)
{
	char	*s;
	int	print = 0;

	while (print != 2) {
		if (print == 0) {
			my_printf("\n\nQue voulez-vous faire ?\n");
			my_printf("Upgrade: Depensez vos points de ");
			my_printf("competences.\n");
			my_printf("Team: Observez les statistiques de votre");
			my_printf(" equipe.\nFight: Affrontez des ");
			my_printf("ennemis pour gagner de l'experience.\nQu");
			my_printf("it: Quittez le jeu sans sauvegarder.\n");
		}
		s = get_next_line(0);
		print = option_chosen(perso, comb, s, print);
	}
}