/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

chara_t	*init_perso(chara_t *perso)
{
	perso = malloc(sizeof(*perso) * 5);
	perso[0] = init_pala();
	perso[1] = init_mage();
	perso[2] = init_archer();
	perso[3] = init_assassin();
	perso[4] = init_troub();
	return (perso);
}

comb_t	*init_ennemies()
{
	ennem_t	*ennem = NULL;
	comb_t *comb = NULL;
	
	comb = malloc(sizeof(*comb) * 6);
	comb[0].ennem = init_easy(ennem);
	comb[1].ennem = init_hard(ennem);
	comb[2].ennem = init_horde(ennem);
	comb[3].ennem = init_bigxp(ennem);
	comb[4].ennem = init_trolz(ennem);
	comb[5].ennem = init_boss(ennem);
	return (comb);
}

void	my_print_ennem(comb_t *comb, int i, int j)
{
	my_printf("%s\n", comb[i].ennem[j].name);
	my_printf("COEF\t->\t%i\n", comb[i].ennem[j].coef);
	my_printf("HP\t->\t%i\n", comb[i].ennem[j].hpmx);
	my_printf("ATK\t->\t%i\n", comb[i].ennem[j].atk);
	my_printf("MAG\t->\t%i\n", comb[i].ennem[j].mag);
	my_printf("DEF\t->\t%i\n", comb[i].ennem[j].def);
	my_printf("RM\t->\t%i\n", comb[i].ennem[j].rm);
	my_printf("VIT\t->\t%i\n", comb[i].ennem[j].vit);
	my_printf("EXP\t->\t%i\n\n", comb[i].ennem[j].exp);
}

void	my_print_perso(chara_t *perso, int i)
{
	my_printf("%s\n", perso[i].name);
	my_printf("LVL\t->\t%i\n", perso[i].lvl);
	my_printf("HP\t->\t%i/%i\n", perso[i].hplt, perso[i].hpmx);
	my_printf("PM\t->\t%i/%i\n", perso[i].pmlt, perso[i].pmmx);
	my_printf("DEF\t->\t%i\n", perso[i].def);
	my_printf("RM\t->\t%i\n", perso[i].rm);
	my_printf("ATK\t->\t%i\n", perso[i].atk);
	my_printf("MAG\t->\t%i\n", perso[i].mg);
	my_printf("VIT\t->\t%i\n", perso[i].vit);
	my_printf("PREC\t->\t%i\n", perso[i].prec);
	my_printf("ESC\t->\t%i\n", perso[i].esc);
	my_printf("EXP\t->\t%i\n\n", perso[i].exp);
}