/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display inventory
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	display_inventory(rpg_t *rp)
{
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[6].sprite, NULL);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[2].sprite, NULL);
	sfRenderWindow_drawSprite(rp->wina.win, rp->sprite[3].sprite, NULL);
	display_items(rp->obj, rp);
	if (rp->bol.stat == 1)
		sfRenderWindow_drawSprite
		(rp->wina.win, rp->sprite[7].sprite, NULL);
}

void	do_events(rpg_t *rp, player_t *player)
{
	(rp->bol.menu == MENU) ? display_menu(rp) : 0;
	(rp->bol.menu == STAT)? display_stats(rp, player->perso): 0;
	(rp->bol.menu == INV)? display_inventory(rp) : 0;
}