/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** print team
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

void	print_morennem(comb_t *comb, int k)
{
	my_printf("\nVIT\t->\t");
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++)
		my_printf("%i\t\t", comb[k].ennem[i].vit);
}

void	print_ennemies(comb_t *comb, int k)
{
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++)
		my_printf("%s\t\t", comb[k].ennem[i].name);
	my_printf("\nHP\t->\t");
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++) {
		my_printf("%i", comb[k].ennem[i].hplt);
		my_printf("/%i\t\t", comb[k].ennem[i].hpmx);
	}
	my_printf("\nATK\t->\t");
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++)
		my_printf("%i\t\t", comb[k].ennem[i].atk);
	my_printf("\nMAG\t->\t");
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++)
		my_printf("%i\t\t", comb[k].ennem[i].mag);
	my_printf("\nDEF\t->\t");
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++)
		my_printf("%i\t\t", comb[k].ennem[i].def);
	my_printf("\nRM\t->\t");
	for (int i = 0; comb[k].ennem[i].name != NULL; i ++)
		my_printf("%i\t\t", comb[k].ennem[i].rm);
	print_morennem(comb, k);
}

int	print_more(chara_t *perso)
{
	my_printf("\nATK\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].atk);
	my_printf("\nMAG\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].mg);
	my_printf("\nVIT\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].vit);
	my_printf("\nPREC\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].prec);
	my_printf("\nESC\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].esc);
	my_printf("\nEXP\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].exp);
	return (0);
}

int	print_team(chara_t *perso)
{
	my_printf("\t\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%s\t\t", perso[i].name);
	my_printf("\nLVL\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].lvl);
	my_printf("\nHP\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i/%i\t\t", perso[i].hplt, perso[i].hpmx);
	my_printf("\nPM\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i/%i\t\t", perso[i].pmlt, perso[i].pmmx);
	my_printf("\nDEF\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].def);
	my_printf("\nRM\t->\t");
	for (int i = 0; i != 5; i ++)
		my_printf("%i\t\t", perso[i].rm);
	return (print_more(perso));
}
