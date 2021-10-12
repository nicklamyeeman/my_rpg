/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** other fct
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

void	bteq_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 44;
	while (win->f == 44) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	vvme_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 36;
	while (win->f == 36) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	verx_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 38;
	while (win->f == 38) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		sfText_setString(btle->hptex, int_to_char(btle->hp));
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	fepn_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 40;
	while (win->f == 40) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		sfText_setString(btle->hptex, int_to_char(btle->hp));
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	vapc_fct(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	win->f = 42;
	while (win->f == 42) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
	for (int i = 0; i != 5; i ++)
		perso[i].hplt += 1;
}