/*
** EPITECH PROJECT, 2018
** delete_boss
** File description:
** delete the boss
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	delete_boss(pnj_t *pnj)
{
	pnj_t	*tmp = pnj;

	while (tmp != NULL) {
		if (same_strings(tmp->name, "Demon")) {
			tmp->x = 0;
			tmp->y = 0;
		}
		tmp = tmp->next;
	}
}
