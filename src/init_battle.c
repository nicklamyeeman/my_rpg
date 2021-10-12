/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init battle
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

void	init_fuit(btle_t *btle)
{
	btle->turn.vprft = sfTexture_createFromFile("./a/d/vprf.png", NULL);
	btle->turn.vprfs = sfSprite_create();
	btle->turn.vplft = sfTexture_createFromFile("./a/d/vplf.png", NULL);
	btle->turn.vplfs = sfSprite_create();
	sfSprite_setTexture(btle->turn.vprfs, btle->turn.vprft, sfTrue);
	sfSprite_setPosition(btle->turn.vprfs, v2f(53, 737));
	sfSprite_setTexture(btle->turn.vplfs, btle->turn.vplft, sfTrue);
	sfSprite_setPosition(btle->turn.vplfs, v2f(53, 737));
}

void	init_battle(btle_t *btle)
{
	btle->hp = 0;
	btle->bgt = sfTexture_createFromFile("./a/btle_bg.png", NULL);
	btle->bgs = sfSprite_create();
	sfSprite_setTexture(btle->bgs, btle->bgt, sfTrue);
	btle->ript = sfTexture_createFromFile("./a/p/rip.png", NULL);
	btle->rips = sfSprite_create();
	sfSprite_setTexture(btle->rips, btle->ript, sfTrue);
	sfSprite_setScale(btle->rips, v2f(0.5, 0.5));
	init_turn(btle);
	init_fuit(btle);
}