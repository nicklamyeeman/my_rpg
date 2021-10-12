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

int	display_perso_stats(rpg_t *rp)
{
	sfRenderWindow_drawText(rp->wina.win, rp->stat.name, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.lvl, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.hp, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.hpm, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.pm, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.pmm, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.atk, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.def, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.mag, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.rm, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.vit, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.prec, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.esq, NULL);
	sfRenderWindow_drawText(rp->wina.win, rp->stat.expe, NULL);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[5].sprite, NULL);
	return (0);
}

int	display_stats(rpg_t *rp, chara_t *car)
{
	setstruct_totext(rp, car[rp->bol.per]);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[4].sprite, NULL);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[2].sprite, NULL);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[3].sprite, NULL);
	display_perso_stats(rp);
	return (0);
}

int	display_menu(rpg_t *rp)
{
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[2].sprite, NULL);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[3].sprite, NULL);
	return (0);
}

sprites_t	init_sprite(char *path, float x, float y)
{
	sprites_t	sprite;

	sprite.sprite = sfSprite_create();
	sprite.text = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(sprite.sprite, sprite.text, sfTrue);
	sfSprite_setPosition(sprite.sprite, v2f(x, y));
	sprite.i = 0;
	sprite.x = 0;
	sprite.y = 0;
	return (sprite);
}

int	load_sprites(rpg_t *rp)
{
	sfIntRect	rect = {0, 0, 20, 25};
	sfIntRect	recta = {34, 0, 36, 32};

	rp->sprite[0] = init_sprite("./assets/map.png", 0, 0);
	rp->sprite[1] = init_sprite("./assets/per.png", 900, 540);
	rp->sprite[1].rect = rect;
	sfSprite_setScale(rp->sprite[1].sprite, v2f(3, 3));
	sfSprite_setTextureRect(rp->sprite[1].sprite, rp->sprite[1].rect);
	rp->sprite[2] = init_sprite("./assets/menubar.png", 1300, 250);
	rp->sprite[3] = init_sprite("./assets/arro.png", 0, 0);
	sfSprite_setTextureRect(rp->sprite[3].sprite, recta);
	rp->sprite[4] = init_sprite("./assets/status.png", 30, 250);
	rp->sprite[6] = init_sprite("./assets/inventory.png", 30, 250);
	rp->sprite[7] = init_sprite("assets/gong.png", 0, 0);
	rp->sprite[8] = init_sprite("assets/vdoq.png", 0, 0);
	return (0);
}