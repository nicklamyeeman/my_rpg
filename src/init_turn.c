/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** turn
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

void	init_toch(btle_t *btle)
{
	btle->turn.tocht = sfTexture_createFromFile("./a/d/toch.png", NULL);
	btle->turn.tochs = sfSprite_create();
	btle->turn.aekot = sfTexture_createFromFile("./a/d/aeko.png", NULL);
	btle->turn.aekos = sfSprite_create();
	btle->hpfon = sfFont_createFromFile("./a/ppf.ttf");
	btle->hptex = sfText_create();
	sfText_setCharacterSize(btle->hptex, 80);
	sfSprite_setTexture(btle->turn.tochs, btle->turn.tocht, sfTrue);
	sfSprite_setTexture(btle->turn.aekos, btle->turn.aekot, sfTrue);
	sfSprite_setPosition(btle->turn.tochs, v2f(53, 737));
	sfSprite_setPosition(btle->turn.aekos, v2f(53, 737));
	sfText_setFont(btle->hptex, btle->hpfon);
	sfText_setString(btle->hptex, "0");
	init_qsvl(btle);
}

void	init_vpae(btle_t *btle)
{
	btle->turn.vpaet = sfTexture_createFromFile("./a/d/vpae.png", NULL);
	btle->turn.vpaes = sfSprite_create();
	sfSprite_setTexture(btle->turn.vpaes, btle->turn.vpaet, sfTrue);
	sfSprite_setPosition(btle->turn.vpaes, v2f(53, 737));
	init_toch(btle);
}

void	init_qvva(btle_t *btle)
{
	btle->turn.qvvat = sfTexture_createFromFile("./a/d/qvva.png", NULL);
	btle->turn.qvvas = sfSprite_create();
	sfSprite_setTexture(btle->turn.qvvas, btle->turn.qvvat, sfTrue);
	sfSprite_setPosition(btle->turn.qvvas, v2f(53, 737));
	init_vpae(btle);
}

void	init_qdfv(btle_t *btle)
{
	sfIntRect	arrec = {0, 0, 40, 35};

	btle->turn.qdfvt = sfTexture_createFromFile("./a/d/qdfv.png", NULL);
	btle->turn.qdfvs = sfSprite_create();
	btle->turn.aseft = sfTexture_createFromFile("./a/d/asef.png", NULL);
	btle->turn.asefs = sfSprite_create();
	btle->turn.arrot = sfTexture_createFromFile("./a/arro.png", NULL);
	btle->turn.arros = sfSprite_create();
	btle->turn.arrec = arrec;
	btle->turn.arclo = sfClock_create();
	btle->turn.artim = sfClock_getElapsedTime(btle->turn.arclo);
	sfSprite_setTexture(btle->turn.qdfvs, btle->turn.qdfvt, sfTrue);
	sfSprite_setPosition(btle->turn.qdfvs, v2f(53, 737));
	sfSprite_setTexture(btle->turn.asefs, btle->turn.aseft, sfTrue);
	sfSprite_setPosition(btle->turn.asefs, v2f(53, 737));
	sfSprite_setTexture(btle->turn.arros, btle->turn.arrot, sfTrue);
	sfSprite_setTextureRect(btle->turn.arros, btle->turn.arrec);
	sfSprite_scale(btle->turn.arros, v2f(1.5, 1.5));
	sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
	init_qvva(btle);
}

void	init_turn(btle_t *btle)
{
	sfIntRect	nerec = {0, 0, 90, 80};

	btle->turn.dmvat = sfTexture_createFromFile("./a/d/dmva.png", NULL);
	btle->turn.dmvas = sfSprite_create();
	btle->nextt = sfTexture_createFromFile("./a/next.png", NULL);
	btle->nexts = sfSprite_create();
	btle->nerec = nerec;
	btle->neclo = sfClock_create();
	btle->netim = sfClock_getElapsedTime(btle->neclo);
	sfSprite_setTexture(btle->turn.dmvas, btle->turn.dmvat, sfTrue);
	sfSprite_setPosition(btle->turn.dmvas, v2f(53, 737));
	sfSprite_setTexture(btle->nexts, btle->nextt, sfTrue);
	sfSprite_setTextureRect(btle->nexts, btle->nerec);
	sfSprite_setPosition(btle->nexts, v2f(1270, 760));
	init_qdfv(btle);
}