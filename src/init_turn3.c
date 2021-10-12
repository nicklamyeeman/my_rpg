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

void	init_vpap(btle_t *btle)
{
	btle->turn.vpapt = sfTexture_createFromFile("./a/d/vpap.png", NULL);
	btle->turn.vpaps = sfSprite_create();
	sfSprite_setTexture(btle->turn.vpaps, btle->turn.vpapt, sfTrue);
	sfSprite_setPosition(btle->turn.vpaps, v2f(53, 737));
	init_adko(btle);
}

void	init_ratk(btle_t *btle)
{
	btle->turn.ratkt = sfTexture_createFromFile("./a/d/ratk.png", NULL);
	btle->turn.ratks = sfSprite_create();
	sfSprite_setTexture(btle->turn.ratks, btle->turn.ratkt, sfTrue);
	sfSprite_setPosition(btle->turn.ratks, v2f(53, 737));
	init_vpap(btle);
}

void	init_crit(btle_t *btle)
{
	btle->turn.critt = sfTexture_createFromFile("./a/d/crit.png", NULL);
	btle->turn.crits = sfSprite_create();
	sfSprite_setTexture(btle->turn.crits, btle->turn.critt, sfTrue);
	sfSprite_setPosition(btle->turn.crits, v2f(53, 737));
	init_ratk(btle);
}

void	init_ento(btle_t *btle)
{
	btle->turn.vpppt = sfTexture_createFromFile("./a/d/vppp.png", NULL);
	btle->turn.vppps = sfSprite_create();
	btle->turn.vpkot = sfTexture_createFromFile("./a/d/vpko.png", NULL);
	btle->turn.vpkos = sfSprite_create();
	sfSprite_setTexture(btle->turn.vppps, btle->turn.vpppt, sfTrue);
	sfSprite_setTexture(btle->turn.vpkos, btle->turn.vpkot, sfTrue);
	sfSprite_setPosition(btle->turn.vppps, v2f(53, 737));
	sfSprite_setPosition(btle->turn.vpkos, v2f(53, 737));
	init_crit(btle);
}

void	init_eavp(btle_t *btle)
{
	btle->turn.eavpt = sfTexture_createFromFile("./a/d/eavp.png", NULL);
	btle->turn.eavps = sfSprite_create();
	sfSprite_setTexture(btle->turn.eavps, btle->turn.eavpt, sfTrue);
	sfSprite_setPosition(btle->turn.eavps, v2f(53, 737));
	init_ento(btle);
}