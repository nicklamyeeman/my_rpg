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

int	main(int ac, char **av)
{
	chara_t	*perso;
	comb_t	*comb;
	win_t	win;
	void	*m = malloc(1);

	srand((unsigned long)m);
	perso = init_perso(perso);
	comb = init_ennemies(comb);
	my_printf("Voici votre équipe: \n");
	print_team(perso);
	battle_orupgrade(perso, comb);
}
