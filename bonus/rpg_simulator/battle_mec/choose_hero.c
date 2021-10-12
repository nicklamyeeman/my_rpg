/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** choosen hero
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

int	choose_skill(char *s, chara_t *perso, int k)
{
	char	*cmp[8] = {"HP", "PM", "DEF", "RM",
		"ATK", "MAG", "VIT", NULL};

	for (int i = 0; cmp[i] != NULL; i ++) {
		if (my_strcmp(s, cmp[i]) == 0) {
			perso[k].hpmx += (i == 0) ? 2 : 0;
			perso[k].hplt +=(i == 0) ? 2 : 0;
			perso[k].pmlt += (i == 1) ? 2 : 0;
			perso[k].pmmx += (i == 1) ? 2 : 0;
			perso[k].def += (i == 2) ? 2 : 0;
			perso[k].rm += (i == 3) ? 2 : 0;
			perso[k].atk += (i == 4) ? 2 : 0;
			perso[k].mg += (i == 5) ? 2 : 0;
			perso[k].vit += (i == 6) ? 2 : 0;
			return (1);
		}
	}
	return (0);
}

void	upgrade_hero(chara_t *perso, int k)
{
	char	*s;
	int	av;

	my_printf("Vous avez %d points de compétences à ", perso[k].pc);
	my_printf("répartir\n(HP = points de vie, PM = points de magie,");
	my_printf(" DEF = défense, RM = résistance magique, ATK = ");
	my_printf("attaque, MAG = magie, VIT = vitesse):\n");
	while (perso[k].pc != 0) {
		av = perso[k].pc;
		s = get_next_line(0);
		perso[k].pc -= choose_skill(s, perso, k);
		(perso[k].pc != 0 && av != perso[k].pc) ?
	my_printf("%d point(s) restant.\n", perso[k].pc) : 0;
	}
	my_putchar('\n');
	my_print_perso(perso, k);
}
