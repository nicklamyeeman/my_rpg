/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init turn 2
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

void	init_bteq(btle_t *btle)
{
	btle->turn.bteqt = sfTexture_createFromFile("./a/btle_eq.png", NULL);
	btle->turn.bteqs = sfSprite_create();
	sfSprite_setTexture(btle->turn.bteqs, btle->turn.bteqt, sfTrue);
	sfSprite_setPosition(btle->turn.bteqs, v2f(0, 0));
}
