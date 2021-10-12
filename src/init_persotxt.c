/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init perso txt
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

chara_t	init_voletxt(chara_t perso)
{
	sfIntRect	aurec = {0, 0, 500, 750};

	perso.perst = sfTexture_createFromFile("./a/p/N.png", NULL);
	perso.perss = sfSprite_create();
	perso.aurat = sfTexture_createFromFile("./a/p/Nspri.png", NULL);
	perso.auras = sfSprite_create();
	perso.aurec = aurec;
	perso.auclo = sfClock_create();
	perso.autim = sfClock_getElapsedTime(perso.auclo);
	perso.pefon = sfFont_createFromFile("./a/ppf.ttf");
	perso.petex = sfText_create();
	sfText_setFont(perso.petex, perso.pefon);
	sfText_setString(perso.petex, "VOLEUR");
	sfSprite_setTexture(perso.perss, perso.perst, sfTrue);
	sfSprite_setTexture(perso.auras, perso.aurat, sfTrue);
	sfSprite_setTextureRect(perso.perss, perso.aurec);
	sfSprite_setScale(perso.perss, v2f(0.5, 0.5));
	sfSprite_setScale(perso.auras, v2f(0.5, 0.5));
	sfSprite_setPosition(perso.perss, v2f(1640, 240));
	sfSprite_setPosition(perso.auras, v2f(1640, 240));
	return (init_voletxt2(perso));
}

chara_t	init_palatxt(chara_t perso)
{
	sfIntRect	aurec = {0, 0, 500, 750};

	perso.perst = sfTexture_createFromFile("./a/p/P.png", NULL);
	perso.perss = sfSprite_create();
	perso.aurat = sfTexture_createFromFile("./a/p/Pspri.png", NULL);
	perso.auras = sfSprite_create();
	perso.aurec = aurec;
	perso.auclo = sfClock_create();
	perso.autim = sfClock_getElapsedTime(perso.auclo);
	perso.pefon = sfFont_createFromFile("./a/ppf.ttf");
	perso.petex = sfText_create();
	sfText_setFont(perso.petex, perso.pefon);
	sfText_setString(perso.petex, "PALADIN");
	sfSprite_setTexture(perso.perss, perso.perst, sfTrue);
	sfSprite_setTexture(perso.auras, perso.aurat, sfTrue);
	sfSprite_setTextureRect(perso.perss, perso.aurec);
	sfSprite_setScale(perso.perss, v2f(0.5, 0.5));
	sfSprite_setScale(perso.auras, v2f(0.5, 0.5));
	sfSprite_setPosition(perso.perss, v2f(1050, 200));
	sfSprite_setPosition(perso.auras, v2f(1050, 200));
	return (init_palatxt2(perso));
}

chara_t	init_magetxt(chara_t perso)
{
	sfIntRect	aurec = {0, 0, 500, 750};

	perso.perst = sfTexture_createFromFile("./a/p/M.png", NULL);
	perso.perss = sfSprite_create();
	perso.aurat = sfTexture_createFromFile("./a/p/Mspri.png", NULL);
	perso.auras = sfSprite_create();
	perso.aurec = aurec;
	perso.auclo = sfClock_create();
	perso.autim = sfClock_getElapsedTime(perso.auclo);
	perso.pefon = sfFont_createFromFile("./a/ppf.ttf");
	perso.petex = sfText_create();
	sfText_setFont(perso.petex, perso.pefon);
	sfText_setString(perso.petex, "MAGE");
	sfSprite_setTexture(perso.perss, perso.perst, sfTrue);
	sfSprite_setTexture(perso.auras, perso.aurat, sfTrue);
	sfSprite_setTextureRect(perso.perss, perso.aurec);
	sfSprite_setScale(perso.perss, v2f(0.5, 0.5));
	sfSprite_setScale(perso.auras, v2f(0.5, 0.5));
	sfSprite_setPosition(perso.perss, v2f(1460, 360));
	sfSprite_setPosition(perso.auras, v2f(1460, 360));
	return (init_magetxt2(perso));
}

chara_t	init_menetxt(chara_t perso)
{
	sfIntRect	aurec = {0, 0, 500, 750};

	perso.perst = sfTexture_createFromFile("./a/p/G.png", NULL);
	perso.perss = sfSprite_create();
	perso.aurat = sfTexture_createFromFile("./a/p/Gspri.png", NULL);
	perso.auras = sfSprite_create();
	perso.aurec = aurec;
	perso.auclo = sfClock_create();
	perso.autim = sfClock_getElapsedTime(perso.auclo);
	perso.pefon = sfFont_createFromFile("./a/ppf.ttf");
	perso.petex = sfText_create();
	sfText_setFont(perso.petex, perso.pefon);
	sfText_setString(perso.petex, "MENESTREL");
	sfSprite_setTexture(perso.perss, perso.perst, sfTrue);
	sfSprite_setTexture(perso.auras, perso.aurat, sfTrue);
	sfSprite_setTextureRect(perso.perss, perso.aurec);
	sfSprite_setScale(perso.perss, v2f(0.5, 0.5));
	sfSprite_setScale(perso.auras, v2f(0.5, 0.5));
	sfSprite_setPosition(perso.perss, v2f(1190, 330));
	sfSprite_setPosition(perso.auras, v2f(1190, 330));
	return (init_menetxt2(perso));
}

chara_t	init_archtxt(chara_t perso)
{
	sfIntRect	aurec = {0, 0, 500, 750};

	perso.perst = sfTexture_createFromFile("./a/p/A.png", NULL);
	perso.perss = sfSprite_create();
	perso.aurat = sfTexture_createFromFile("./a/p/Aspri.png", NULL);
	perso.auras = sfSprite_create();
	perso.aurec = aurec;
	perso.auclo = sfClock_create();
	perso.autim = sfClock_getElapsedTime(perso.auclo);
	perso.pefon = sfFont_createFromFile("./a/ppf.ttf");
	perso.petex = sfText_create();
	sfText_setFont(perso.petex, perso.pefon);
	sfText_setString(perso.petex, "ARCHER");
	sfSprite_setTexture(perso.perss, perso.perst, sfTrue);
	sfSprite_setTexture(perso.auras, perso.aurat, sfTrue);
	sfSprite_setTextureRect(perso.perss, perso.aurec);
	sfSprite_setScale(perso.perss, v2f(0.5, 0.5));
	sfSprite_setScale(perso.auras, v2f(0.5, 0.5));
	sfSprite_setPosition(perso.perss, v2f(1340, 170));
	sfSprite_setPosition(perso.auras, v2f(1340, 170));
	return (init_archtxt2(perso));
}