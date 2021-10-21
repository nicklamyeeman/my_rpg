/*
** EPITECH PROJECT, 2018
** start_game
** File description:
** Launch the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

view_t	init_view(void)
{
	view_t	cam;

	cam.view = sfView_create();
	cam.x = 0;
	cam.y = 0;
	sfView_setSize(cam.view, v2f(1920, 1080));
	sfView_setCenter(cam.view, v2f(960, 540));
	return (cam);
}

stat_t	init_stats_der(stat_t stat)
{
	stat.prec = sfText_create();
	sfText_setFont(stat.prec, stat.pok);
	sfText_setCharacterSize(stat.prec, 38);
	stat.esq = sfText_create();
	sfText_setFont(stat.esq, stat.pok);
	sfText_setCharacterSize(stat.esq, 38);
	stat.expe = sfText_create();
	sfText_setFont(stat.expe, stat.pok);
	sfText_setCharacterSize(stat.expe, 38);
	return (stat);
}

stat_t	init_stats_oui(stat_t stat)
{
	stat.pmm = sfText_create();
	sfText_setFont(stat.pmm, stat.pok);
	sfText_setCharacterSize(stat.pmm, 38);
	stat.atk = sfText_create();
	sfText_setFont(stat.atk, stat.pok);
	sfText_setCharacterSize(stat.atk, 38);
	stat.def = sfText_create();
	sfText_setFont(stat.def, stat.pok);
	sfText_setCharacterSize(stat.def, 38);
	stat.mag = sfText_create();
	sfText_setFont(stat.mag, stat.pok);
	sfText_setCharacterSize(stat.mag, 38);
	stat.rm = sfText_create();
	sfText_setFont(stat.rm, stat.pok);
	sfText_setCharacterSize(stat.rm, 38);
	stat.vit = sfText_create();
	sfText_setFont(stat.vit, stat.pok);
	sfText_setCharacterSize(stat.vit, 38);
	stat = init_stats_der(stat);
	return (stat);
}

stat_t	init_stats(void)
{
	stat_t	stat;

	stat.pok = sfFont_createFromFile("./assets/ppf.ttf");
	stat.name = sfText_create();
	sfText_setFont(stat.name, stat.pok);
	sfText_setCharacterSize(stat.name, 44);
	stat.lvl = sfText_create();
	sfText_setFont(stat.lvl, stat.pok);
	sfText_setCharacterSize(stat.lvl, 44);
	stat.hp = sfText_create();
	sfText_setFont(stat.hp, stat.pok);
	sfText_setCharacterSize(stat.hp, 38);
	stat.hpm = sfText_create();
	sfText_setFont(stat.hpm, stat.pok);
	sfText_setCharacterSize(stat.hpm, 38);
	stat.pm = sfText_create();
	sfText_setFont(stat.pm, stat.pok);
	sfText_setCharacterSize(stat.pm, 38);
	stat = init_stats_oui(stat);
	return (stat);
}

rpg_t	init_struct(win_t *w)
{
	rpg_t rp;

	rp.bol.menu = 0;
	rp.bol.in = 0;
	rp.bol.per = 0;
	rp.bol.obj = 0;
	rp.zone.top = 0;
	rp.zone.left = 0;
	rp.zone.width = 500;
	rp.zone.height = 300;
	rp.c = sfClock_create();
	rp.cam = init_view();
	rp.camp = init_view();
	rp.stat = init_stats();
	rp.wina.win = w->win;
	load_sprites(&rp);
	init_items(&rp.obj);
	return (rp);
}