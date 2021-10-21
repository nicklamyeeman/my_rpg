/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main file
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include "rpg.h"

int	main(void)
{
	chara_t	*perso = NULL;
	comb_t	*comb = NULL;
	void	*m = malloc(1);

	srand((unsigned long)m);
	perso = init_perso();
	comb = init_ennemies();
	my_printf("Voici votre équipe: \n");
	print_team(perso);
	battle_orupgrade(perso, comb);
}
