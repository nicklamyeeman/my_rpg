/*
** EPITECH PROJECT, 2018
** new_game
** File description:
** load a new game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	load_new_player(player_t *player)
{
	player->x = 45;
	player->y = 38;
	player->mvx = 0;
	player->mvy = 0;
	player->clock = sfClock_create();
	player->rect.left = 0;
	player->rect.top = 0;
	player->rect.width = 20;
	player->rect.height = 25;
	player->perso = init_perso(player->perso);
	player->moving = 0;
	player->speaking_with = NULL;
	player->dialog = NULL;
	player->line = 0;
}

void	new_game(win_t *w)
{
	player_t	player;
	void	*m = malloc(1);

	srand((unsigned long)m);
	load_new_player(&player);
	start_game(w, &player);
}
