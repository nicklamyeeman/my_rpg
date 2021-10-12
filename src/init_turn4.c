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

void	init_vvme(btle_t *btle)
{
	btle->turn.vvmet = sfTexture_createFromFile("./a/d/vvme.png", NULL);
	btle->turn.vvmes = sfSprite_create();
	sfSprite_setTexture(btle->turn.vvmes, btle->turn.vvmet, sfTrue);
	sfSprite_setPosition(btle->turn.vvmes, v2f(53, 737));
	init_bteq(btle);
}

void	init_verx(btle_t *btle)
{
	btle->turn.verxt = sfTexture_createFromFile("./a/d/verx.png", NULL);
	btle->turn.verxs = sfSprite_create();
	sfSprite_setTexture(btle->turn.verxs, btle->turn.verxt, sfTrue);
	sfSprite_setPosition(btle->turn.verxs, v2f(53, 737));
	init_vvme(btle);
}

void	init_fepn(btle_t *btle)
{
	btle->turn.fepnt = sfTexture_createFromFile("./a/d/fepn.png", NULL);
	btle->turn.fepns = sfSprite_create();
	sfSprite_setTexture(btle->turn.fepns, btle->turn.fepnt, sfTrue);
	sfSprite_setPosition(btle->turn.fepns, v2f(53, 737));
	init_verx(btle);
}

void	init_vapc(btle_t *btle)
{
	btle->turn.vapct = sfTexture_createFromFile("./a/d/vapc.png", NULL);
	btle->turn.vapcs = sfSprite_create();
	sfSprite_setTexture(btle->turn.vapcs, btle->turn.vapct, sfTrue);
	sfSprite_setPosition(btle->turn.vapcs, v2f(53, 737));
	init_fepn(btle);
}

void	init_adko(btle_t *btle)
{
	btle->turn.adkot = sfTexture_createFromFile("./a/d/adko.png", NULL);
	btle->turn.adkos = sfSprite_create();
	sfSprite_setTexture(btle->turn.adkos, btle->turn.adkot, sfTrue);
	sfSprite_setPosition(btle->turn.adkos, v2f(53, 737));
	init_vapc(btle);
}
