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

void	init_vprm(btle_t *btle)
{
	btle->turn.vprmt = sfTexture_createFromFile("./a/d/vprm.png", NULL);
	btle->turn.vprms = sfSprite_create();
	sfSprite_setTexture(btle->turn.vprms, btle->turn.vprmt, sfTrue);
	sfSprite_setPosition(btle->turn.vprms, v2f(53, 737));
	init_eavp(btle);
}

void	init_heal(btle_t *btle)
{
	btle->turn.vprpt = sfTexture_createFromFile("./a/d/vprp.png", NULL);
	btle->turn.vprps = sfSprite_create();
	sfSprite_setTexture(btle->turn.vprps, btle->turn.vprpt, sfTrue);
	sfSprite_setPosition(btle->turn.vprps, v2f(53, 737));
	init_vprm(btle);
}

void	init_qvvs(btle_t *btle)
{
	btle->turn.qvvst = sfTexture_createFromFile("./a/d/qvvs.png", NULL);
	btle->turn.qvvss = sfSprite_create();
	sfSprite_setTexture(btle->turn.qvvss, btle->turn.qvvst, sfTrue);
	sfSprite_setPosition(btle->turn.qvvss, v2f(53, 737));
	init_heal(btle);
}

void	init_qsvl(btle_t *btle)
{
	btle->turn.qsvlt = sfTexture_createFromFile("./a/d/qsvl.png", NULL);
	btle->turn.qsvls = sfSprite_create();
	sfSprite_setTexture(btle->turn.qsvls, btle->turn.qsvlt, sfTrue);
	sfSprite_setPosition(btle->turn.qsvls, v2f(53, 737));
	init_qvvs(btle);
}