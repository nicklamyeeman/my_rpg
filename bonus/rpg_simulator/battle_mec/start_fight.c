/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** start_fight
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

int	fainted_ennemy(char *s, comb_t *comb, chara_t *perso)
{
	int	i = rand() % 5;
	int	vod = -1;

	my_printf("\nVos adversaires sont:\n\t\t");
	print_ennemies(comb, i);
	my_putchar('\n');
	vod = go_fight(comb, i, perso);
	if (vod == 1)
		victory_nxp(comb, i, perso);
	else if (vod == 0)
		my_printf("GAME OVER\n");
	return (1);
}

int	start_fight(comb_t *comb, chara_t *perso)
{
	char	*s;
	int	k = 0;

	while (k != 1) {
		if (k == 0)
			my_printf("\nVous entrez dans une zone de combat...");
		k = fainted_ennemy(s, comb, perso);
	}
	return (0);
}