/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init combi
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

ennem_t	*init_bigxp()
{
	ennem_t	*ennem = NULL;

	ennem = malloc(sizeof(*ennem) * 4);
	ennem[0] = init_troll();
	ennem[1] = init_pampa();
	ennem[2] = init_gob();
	ennem[3].name = NULL;
	return (ennem);
}

ennem_t	*init_easy()
{
	ennem_t	*ennem = NULL;

	ennem = malloc(sizeof(*ennem) * 4);
	ennem[0] = init_troll();
	ennem[1] = init_gob();
	ennem[1].name = my_strdup("Gob A");
	ennem[2] = init_gob();
	ennem[2].name = my_strdup("Gob B");
	ennem[3].name = NULL;
	return (ennem);
}

ennem_t	*init_horde()
{
	ennem_t	*ennem = NULL;
	
	ennem = malloc(sizeof(*ennem) * 7);
	ennem[0] = init_gob();
	ennem[0].name = my_strdup("Gob A");
	ennem[1] = init_gob();
	ennem[1].name = my_strdup("Gob B");
	ennem[2] = init_gob();
	ennem[2].name = my_strdup("Gob C");
	ennem[3] = init_gob();
	ennem[3].name = my_strdup("Gob D");
	ennem[4] = init_gob();
	ennem[4].name = my_strdup("Gob E");
	ennem[5] = init_gob();
	ennem[5].name = my_strdup("Gob F");
	ennem[6].name = NULL;
	return (ennem);
}

ennem_t	*init_hard()
{
	ennem_t	*ennem = NULL;
	
	ennem = malloc(sizeof(*ennem) * 6);
	ennem[0] = init_troll();
	ennem[0].name = my_strdup("Troll A");
	ennem[1] = init_troll();
	ennem[1].name = my_strdup("Troll B");
	ennem[2] = init_troll();
	ennem[2].name = my_strdup("Troll C");
	ennem[3] = init_gob();
	ennem[3].name = my_strdup("Gob A");
	ennem[4] = init_gob();
	ennem[4].name = my_strdup("Gob B");
	ennem[5].name =NULL;
	return (ennem);
}

ennem_t	*init_trolz()
{
	ennem_t	*ennem = NULL;

	ennem = malloc(sizeof(*ennem) * 7);
	ennem[0] = init_pampa();
	ennem[1] = init_bidoof();
	ennem[1].name = my_strdup("Bid. A");
	ennem[2] = init_bidoof();
	ennem[2].name = my_strdup("Bid. B");
	ennem[3] = init_bidoof();
	ennem[3].name = my_strdup("Bid. C");
	ennem[4] = init_bidoof();
	ennem[4].name = my_strdup("Bid. D");
	ennem[5] = init_bidoof();
	ennem[5].name = my_strdup("Bid. E");
	ennem[6].name = NULL;
	return (ennem);
}