/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** battle event
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

void	bteq_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 2;
}

void	vapc_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 43;
}

void	fepn_event(win_t *win, btle_t *btle)
{
	if (win->evt.type == sfEvtKeyPressed)
		if (win->evt.key.code == sfKeyReturn)
			win->f = 41;
}