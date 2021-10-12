/*
** EPITECH PROJECT, 2018
** is_it_a_fight
** File description:
** Check if we enter in fight mode
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

void	do_we_fight(win_t *w, player_t *p)
{
	int	r = rand() % 6;

	if (r == 0)
		init_fight(w, p);
}

void	is_it_a_fight(win_t *w, player_t *p, map_t *map)
{
	map_t	*tmp = map;

	while (tmp->x != p->x || tmp->y != p->y)
		tmp = tmp->next;
	if (tmp == NULL)
		return;
	if (tmp->spawn == 1)
		do_we_fight(w, p);
}
