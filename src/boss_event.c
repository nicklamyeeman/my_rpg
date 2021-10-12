/*
** EPITECH PROJECT, 2018
** game_events
** File description:
** Handle inputs in the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

ennem_t	*init_bosstxt(ennem_t *ennem)
{
	sfText_setString(ennem[0].entex, "DEMON");
	sfSprite_setPosition(ennem[0].ennes, v2f(60, 20));
	sfSprite_setPosition(ennem[0].arros, v2f(220, 10));
	return (ennem);
}

ennem_t	init_demontxt(ennem_t ennem)
{
	sfIntRect	arrec = {0, 0, 90, 80};

	ennem.ennet = sfTexture_createFromFile("./a/p/boss.png", NULL);
	ennem.ennes = sfSprite_create();
	ennem.enfon = sfFont_createFromFile("./a/ppf.ttf");
	ennem.entex = sfText_create();
	ennem.arrot = sfTexture_createFromFile("./a/next.png", NULL);
	ennem.arros = sfSprite_create();
	ennem.arrec = arrec;
	sfText_setFont(ennem.entex, ennem.enfon);
	sfText_setString(ennem.entex, "DEMON");
	sfSprite_setTexture(ennem.ennes, ennem.ennet, sfTrue);
	sfSprite_setTexture(ennem.arros, ennem.arrot, sfTrue);
	sfSprite_setTextureRect(ennem.arros, ennem.arrec);
	sfSprite_setScale(ennem.ennes, v2f(0.5, 0.5));
	return (ennem);
}

ennem_t	init_demon(void)
{
	ennem_t	ennem;

	ennem.name = my_strdup("Demon");
	ennem.coef = 1;
	ennem.hplt = 2;
	ennem.hpmx = 2;
	ennem.atk = 31;
	ennem.mag = 15;
	ennem.def = 34;
	ennem.rm = 51;
	ennem.vit = 25;
	ennem.exp = 1000;
	return (init_demontxt(ennem));
}

ennem_t	*init_boss(ennem_t *ennem)
{
	ennem = malloc(sizeof(*ennem) * 2);
	ennem[0] = init_demon();
	ennem[0].comb = 2;
	ennem[1].name = NULL;
	return (init_bosstxt(ennem));
}

void	special_event(win_t *w, player_t *p, pnj_t *pnj)
{
	if (same_strings(p->speaking_with, "Demon") == 1) {
		if (w->boss == 0) {
			w->boss = 1;
			init_fight(w, p);
		}
		if (w->boss == 2) {
			delete_boss(pnj);
			change_gandoulf_dialog(pnj);
		}
	}
}
