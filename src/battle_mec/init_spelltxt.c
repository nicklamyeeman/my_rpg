/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** spells
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

spell_t	spell_txtmage(spell_t spell)
{
	sfIntRect	s1rec = {0, 0, 192, 192};
	sfIntRect	s2rec = {0, 0, 192, 192};

	spell.spe1t = sfTexture_createFromFile("./a/s/nogi.png", NULL);
	spell.spe1s = sfSprite_create();
	spell.spe2t = sfTexture_createFromFile("./a/s/fiba.png", NULL);
	spell.spe2s = sfSprite_create();
	spell.s1rec = s1rec;
	spell.s2rec = s2rec;
	spell.s1clo = sfClock_create();
	spell.s1tim = sfClock_getElapsedTime(spell.s1clo);
	spell.s2clo = sfClock_create();
	spell.s2tim = sfClock_getElapsedTime(spell.s2clo);
	sfSprite_setTexture(spell.spe1s, spell.spe1t, sfTrue);
	sfSprite_setTexture(spell.spe2s, spell.spe2t, sfTrue);
	sfSprite_setTextureRect(spell.spe1s, spell.s1rec);
	sfSprite_setTextureRect(spell.spe2s, spell.s2rec);
	return (spell);
}

spell_t	spell_txtpala(spell_t spell)
{
	sfIntRect	s1rec = {0, 0, 192, 192};
	sfIntRect	s2rec = {0, 0, 192, 192};

	spell.spe1t = sfTexture_createFromFile("./a/s/cons.png", NULL);
	spell.spe1s = sfSprite_create();
	spell.spe2t = sfTexture_createFromFile("./a/s/todi.png", NULL);
	spell.spe2s = sfSprite_create();
	spell.s1rec = s1rec;
	spell.s2rec = s2rec;
	spell.s1clo = sfClock_create();
	spell.s1tim = sfClock_getElapsedTime(spell.s1clo);
	spell.s2clo = sfClock_create();
	spell.s2tim = sfClock_getElapsedTime(spell.s2clo);
	sfSprite_setTexture(spell.spe1s, spell.spe1t, sfTrue);
	sfSprite_setTexture(spell.spe2s, spell.spe2t, sfTrue);
	sfSprite_setTextureRect(spell.spe1s, spell.s1rec);
	sfSprite_setTextureRect(spell.spe2s, spell.s2rec);
	return (spell);
}

spell_t	spell_txtvole(spell_t spell)
{
	sfIntRect	s1rec = {0, 0, 96, 98};
	sfIntRect	s2rec = {0, 0, 192, 192};

	spell.spe1t = sfTexture_createFromFile("./a/s/assa.png", NULL);
	spell.spe1s = sfSprite_create();
	spell.spe2t = sfTexture_createFromFile("./a/s/evis.png", NULL);
	spell.spe2s = sfSprite_create();
	spell.s1rec = s1rec;
	spell.s2rec = s2rec;
	spell.s1clo = sfClock_create();
	spell.s1tim = sfClock_getElapsedTime(spell.s1clo);
	spell.s2clo = sfClock_create();
	spell.s2tim = sfClock_getElapsedTime(spell.s2clo);
	sfSprite_setTexture(spell.spe1s, spell.spe1t, sfTrue);
	sfSprite_setTexture(spell.spe2s, spell.spe2t, sfTrue);
	sfSprite_setTextureRect(spell.spe1s, spell.s1rec);
	sfSprite_setTextureRect(spell.spe2s, spell.s2rec);
	return (spell);
}

spell_t	spell_txtmene(spell_t spell)
{
	sfIntRect	s1rec = {0, 0, 192, 192};
	sfIntRect	s2rec = {0, 0, 192, 192};

	spell.spe1t = sfTexture_createFromFile("./a/s/ranr.png", NULL);
	spell.spe1s = sfSprite_create();
	spell.spe2t = sfTexture_createFromFile("./a/s/vads.png", NULL);
	spell.spe2s = sfSprite_create();
	spell.s1rec = s1rec;
	spell.s2rec = s2rec;
	spell.s1clo = sfClock_create();
	spell.s1tim = sfClock_getElapsedTime(spell.s1clo);
	spell.s2clo = sfClock_create();
	spell.s2tim = sfClock_getElapsedTime(spell.s2clo);
	sfSprite_setTexture(spell.spe1s, spell.spe1t, sfTrue);
	sfSprite_setTexture(spell.spe2s, spell.spe2t, sfTrue);
	sfSprite_setTextureRect(spell.spe1s, spell.s1rec);
	sfSprite_setTextureRect(spell.spe2s, spell.s2rec);
	return (spell);
}

spell_t	spell_txtarch(spell_t spell)
{
	sfIntRect	s1rec = {0, 0, 92, 66};
	sfIntRect	s2rec = {0, 0, 70, 90};

	spell.spe1t = sfTexture_createFromFile("./a/s/timu.png", NULL);
	spell.spe1s = sfSprite_create();
	spell.spe2t = sfTexture_createFromFile("./a/s/time.png", NULL);
	spell.spe2s = sfSprite_create();
	spell.s1rec = s1rec;
	spell.s2rec = s2rec;
	spell.s1clo = sfClock_create();
	spell.s1tim = sfClock_getElapsedTime(spell.s1clo);
	spell.s2clo = sfClock_create();
	spell.s2tim = sfClock_getElapsedTime(spell.s2clo);
	sfSprite_setTexture(spell.spe1s, spell.spe1t, sfTrue);
	sfSprite_setTexture(spell.spe2s, spell.spe2t, sfTrue);
	sfSprite_setTextureRect(spell.spe1s, spell.s1rec);
	sfSprite_setTextureRect(spell.spe2s, spell.s2rec);
	return (spell);
}