/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** ennem text n spri
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

ennem_t	init_troltxt(ennem_t ennem)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	ennem.ennet = sfTexture_createFromFile("./a/p/tro.png", NULL);
	ennem.ennes = sfSprite_create();
	ennem.enfon = sfFont_createFromFile("./a/ppf.ttf");
	ennem.entex = sfText_create();
	ennem.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	ennem.arros = sfSprite_create();
	ennem.arrec = arrec;
	sfText_setFont(ennem.entex, ennem.enfon);
	sfText_setString(ennem.entex, "TROLL");
	sfSprite_setTexture(ennem.ennes, ennem.ennet, sfTrue);
	sfSprite_setTexture(ennem.arros, ennem.arrot, sfTrue);
	sfSprite_setTextureRect(ennem.arros, ennem.arrec);
	sfSprite_setScale(ennem.ennes, v2f(0.5, 0.5));
	return (ennem);
}

ennem_t	init_bidotxt(ennem_t ennem)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	ennem.ennet = sfTexture_createFromFile("./a/p/bid.png", NULL);
	ennem.ennes = sfSprite_create();
	ennem.enfon = sfFont_createFromFile("./a/ppf.ttf");
	ennem.entex = sfText_create();
	ennem.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	ennem.arros = sfSprite_create();
	ennem.arrec = arrec;
	sfText_setFont(ennem.entex, ennem.enfon);
	sfText_setString(ennem.entex, "BIDOOF");
	sfSprite_setTexture(ennem.ennes, ennem.ennet, sfTrue);
	sfSprite_setTexture(ennem.arros, ennem.arrot, sfTrue);
	sfSprite_setTextureRect(ennem.arros, ennem.arrec);
	sfSprite_setScale(ennem.ennes, v2f(0.5, 0.5));
	return (ennem);
}

ennem_t	init_gobetxt(ennem_t ennem)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	ennem.ennet = sfTexture_createFromFile("./a/p/gob.png", NULL);
	ennem.ennes = sfSprite_create();
	ennem.enfon = sfFont_createFromFile("./a/ppf.ttf");
	ennem.entex = sfText_create();
	ennem.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	ennem.arros = sfSprite_create();
	ennem.arrec = arrec;
	sfText_setFont(ennem.entex, ennem.enfon);
	sfText_setString(ennem.entex, "GOBELIN");
	sfSprite_setTexture(ennem.ennes, ennem.ennet, sfTrue);
	sfSprite_setTexture(ennem.arros, ennem.arrot, sfTrue);
	sfSprite_setTextureRect(ennem.arros, ennem.arrec);
	sfSprite_setScale(ennem.ennes, v2f(0.5, 0.5));
	return (ennem);
}

ennem_t	init_pamptxt(ennem_t ennem)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	ennem.ennet = sfTexture_createFromFile("./a/p/pam.png", NULL);
	ennem.ennes = sfSprite_create();
	ennem.enfon = sfFont_createFromFile("./a/ppf.ttf");
	ennem.entex = sfText_create();
	ennem.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	ennem.arros = sfSprite_create();
	ennem.arrec = arrec;
	sfText_setFont(ennem.entex, ennem.enfon);
	sfText_setString(ennem.entex, "PAMPINATOR");
	sfSprite_setTexture(ennem.ennes, ennem.ennet, sfTrue);
	sfSprite_setTexture(ennem.arros, ennem.arrot, sfTrue);
	sfSprite_setTextureRect(ennem.arros, ennem.arrec);
	sfSprite_setScale(ennem.ennes, v2f(0.5, 0.5));
	return (ennem);
}