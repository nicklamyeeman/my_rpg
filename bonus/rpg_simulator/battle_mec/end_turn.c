/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** endturn
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

int	end_team(chara_t *perso)
{
	int	k = 0;
	int	ret = 0;

	for (k = 0; k != 5; k ++)
		ret += (perso[k].hplt == 0) ? 1 : 0;
	if (ret == k)
		return (1);
	else
		return (0);
}

int	end_ennem(comb_t *comb, int i)
{
	int	k = 0;
	int	ret = 0;

	for (k = 0; comb[i].ennem[k].name != NULL; k++)
		ret += (comb[i].ennem[k].hplt == 0) ? 1 : 0;
	if (ret == k)
		return (1);
	else
		return (0);
}
