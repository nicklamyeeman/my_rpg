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

chara_t	init_voletxt2(chara_t perso)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	perso.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	perso.arros = sfSprite_create();
	perso.arrec = arrec;
	perso.caret = sfTexture_createFromFile("./a/caren.png", NULL);
	perso.cares = sfSprite_create();
	sfSprite_setTexture(perso.cares, perso.caret, sfTrue);
	sfSprite_setTexture(perso.arros, perso.arrot, sfTrue);
	sfSprite_setTextureRect(perso.arros, perso.arrec);
	sfSprite_setPosition(perso.arros, v2f(1740, 240));
	perso.num = 3;
	return (perso);
}

chara_t	init_palatxt2(chara_t perso)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	perso.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	perso.arros = sfSprite_create();
	perso.arrec = arrec;
	perso.caret = sfTexture_createFromFile("./a/carep.png", NULL);
	perso.cares = sfSprite_create();
	sfSprite_setTexture(perso.cares, perso.caret, sfTrue);
	sfSprite_setTexture(perso.arros, perso.arrot, sfTrue);
	sfSprite_setTextureRect(perso.arros, perso.arrec);
	sfSprite_setPosition(perso.arros, v2f(1150, 200));
	perso.num = 0;
	return (perso);
}

chara_t	init_magetxt2(chara_t perso)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	perso.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	perso.arros = sfSprite_create();
	perso.arrec = arrec;
	perso.caret = sfTexture_createFromFile("./a/carem.png", NULL);
	perso.cares = sfSprite_create();
	sfSprite_setTexture(perso.cares, perso.caret, sfTrue);
	sfSprite_setTexture(perso.arros, perso.arrot, sfTrue);
	sfSprite_setTextureRect(perso.arros, perso.arrec);
	sfSprite_setPosition(perso.arros, v2f(1560, 360));
	perso.num = 1;
	return (perso);
}

chara_t	init_menetxt2(chara_t perso)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	perso.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	perso.arros = sfSprite_create();
	perso.arrec = arrec;
	perso.caret = sfTexture_createFromFile("./a/carg.png", NULL);
	perso.cares = sfSprite_create();
	sfSprite_setTexture(perso.cares, perso.caret, sfTrue);
	sfSprite_setTexture(perso.arros, perso.arrot, sfTrue);
	sfSprite_setTextureRect(perso.arros, perso.arrec);
	sfSprite_setPosition(perso.arros, v2f(1290, 330));
	perso.num = 4;
	return (perso);
}

chara_t	init_archtxt2(chara_t perso)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	perso.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	perso.arros = sfSprite_create();
	perso.arrec = arrec;
	perso.caret = sfTexture_createFromFile("./a/cara.png", NULL);
	perso.cares = sfSprite_create();
	sfSprite_setTexture(perso.cares, perso.caret, sfTrue);
	sfSprite_setTexture(perso.arros, perso.arrot, sfTrue);
	sfSprite_setTextureRect(perso.arros, perso.arrec);
	sfSprite_setPosition(perso.arros, v2f(1440, 170));
	perso.num = 2;
	return (perso);
}