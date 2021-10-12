/*
** EPITECH PROJECT, 2018
** init_fight
** File description:
** Initialise a fight and lauch it
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

void	init_fight(win_t *win, player_t *p)
{
	comb_t	*comb;
	void	*m = malloc(1);

	comb = init_ennemies(comb);
	win->f = 0;
	for (int i = 0; i != 5; i ++)
		for (int j = 0; comb[i].ennem[j].name != NULL; j ++)
			comb[i].ennem[j].num = j;
	start_fight(win, comb, p->perso);
}
