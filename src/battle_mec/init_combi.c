/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init combi
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

ennem_t	*init_bigxp(ennem_t *ennem)
{
	ennem = malloc(sizeof(*ennem) * 4);
	ennem[0] = init_troll();
	ennem[0].comb = 3;
	ennem[1] = init_pampa();
	ennem[1].comb = 3;
	ennem[2] = init_gob();
	ennem[2].comb = 3;
	ennem[3].name = NULL;
	return (init_bigxptxt(ennem));
}

ennem_t	*init_easy(ennem_t *ennem)
{
	ennem = malloc(sizeof(*ennem) * 4);
	ennem[0] = init_troll();
	ennem[0].comb = 0;
	ennem[1] = init_gob();
	ennem[1].comb = 0;
	ennem[2] = init_gob();
	ennem[2].comb = 0;
	ennem[3].name = NULL;
	return (init_easytxt(ennem));
}

ennem_t	*init_horde(ennem_t *ennem)
{
	ennem = malloc(sizeof(*ennem) * 7);
	ennem[0] = init_gob();
	ennem[0].comb = 2;
	ennem[1] = init_gob();
	ennem[1].comb = 2;
	ennem[2] = init_gob();
	ennem[2].comb = 2;
	ennem[3] = init_gob();
	ennem[3].comb = 2;
	ennem[4] = init_gob();
	ennem[4].comb = 2;
	ennem[5] = init_gob();
	ennem[5].comb = 2;
	ennem[6].name = NULL;
	return (init_hordetxt(ennem));
}

ennem_t	*init_hard(ennem_t *ennem)
{
	ennem = malloc(sizeof(*ennem) * 6);
	ennem[0] = init_troll();
	ennem[0].comb = 1;
	ennem[1] = init_troll();
	ennem[1].comb = 1;
	ennem[2] = init_troll();
	ennem[2].comb = 1;
	ennem[3] = init_gob();
	ennem[3].comb = 1;
	ennem[4] = init_gob();
	ennem[4].comb = 1;
	ennem[5].name =NULL;
	return (init_hardtxt(ennem));
}

ennem_t	*init_trolz(ennem_t *ennem)
{
	ennem = malloc(sizeof(*ennem) * 7);
	ennem[0] = init_pampa();
	ennem[0].comb = 4;
	ennem[1] = init_bidoof();
	ennem[1].comb = 4;
	ennem[2] = init_bidoof();
	ennem[2].comb = 4;
	ennem[3] = init_bidoof();
	ennem[3].comb = 4;
	ennem[4] = init_bidoof();
	ennem[4].comb = 4;
	ennem[5] = init_bidoof();
	ennem[5].comb = 4;
	ennem[6].name = NULL;
	return (init_trolztxt(ennem));
}