/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** Display the map surrounding the player
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	display_tile(win_t *w, player_t *p, map_t *t)
{
	sfTexture	*txt;
	sfSprite	*sprite = sfSprite_create();
	char	*dir = "./ressources/textures/";
	float	x = (t->x - (p->x - 5)) * 192 - 96;
	float	y = (t->y - (p->y - 2)) * 216;

	if (same_strings(t->name, "tree.png"))
		y -= 216;
	txt = sfTexture_createFromFile(concat_str(dir, t->name), NULL);
	sfSprite_setTexture(sprite, txt, sfTrue);
	sfSprite_setPosition(sprite, create_vector(x, y));
	sfSprite_setScale(sprite, create_vector(9.6, 10.8));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(txt);
}

int	valid_coordinates(int x, int y, float px, float py)
{
	if (y < py - 3 || y > py + 4)
		return (0);
	if (x < px - 6 || x > px + 6)
		return (0);
	return (1);
}

void	check_if_display_player(win_t *w, player_t *p, map_t *tmp)
{
	if (p->x > tmp->x - 2 && p->x < tmp->x + 2)
		if (p->y <= tmp->y && p->y > tmp->y - 1)
			display_player(w, p);
}

void	check_if_display_pnj(win_t *w, pnj_t *pnj, map_t *map, player_t *p)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		if (tmp->x > map->x -2 && tmp->y <= map->y &&
			tmp->x < map->x + 2 && tmp->y > map->y - 1)
			display_pnj(w, tmp, p);
		tmp = tmp->next;
	}
}

void	display_map(win_t *w, player_t *p, map_t *map, pnj_t *pnj)
{
	map_t	*tmp = map;

	while (tmp != NULL) {
		if (valid_coordinates(tmp->x, tmp->y, p->x, p->y)) {
			check_if_display_player(w, p , tmp);
			display_tile(w, p , tmp);
			check_if_display_pnj(w, pnj, tmp, p);
		}
		tmp = tmp->next;
	}
}
