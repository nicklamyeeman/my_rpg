/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** team turn
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

int	you_dont_run(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	win->f = 20;
	while (win->f == 20) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	return (2);
}

int	will_you_run(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	int	r = rand() % 100;

	if (r >= 0 && r <= 9) {
		win->f = 22;
		while (win->f == 22) {
			battle_event(win, btle, p, ennem);
			sfRenderWindow_clear(win->win, sfWhite);
			display_window(win, btle, p, ennem);
			sfRenderWindow_display(win->win);
		}
		return (3);
	}
	return (you_dont_run(win, btle, p, ennem));
}

int	resume_fight(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	bteq_fct(win, btle, ennem, p);
	return (0);
}

int	do_in_fight(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	sfVector2f a = sfSprite_getPosition(btle->turn.arros);
	int	t = 0;
	int	b = 0;

	b = (a.x == 1030 && a.y == 800) ? 1 : b;
	b = (a.x == 1500 && a.y == 800) ? 2 : b;
	b = (a.x == 1030 && a.y == 940) ? 3 : b;
	b = (a.x == 1500 && a.y == 940) ? 4 : b;
	if (win->f == 3) {
		t = (b == 1) ? let_hurt_them(win, btle, ennem, p) : t;
		t = (b == 2) ? let_spell_us(win, btle, ennem, p) : t;
		t = (b == 3) ? resume_fight(win, btle, ennem, p) : t;
		t = (b == 4) ? will_you_run(win, btle, p, ennem) : t;
	}
	return (t);
}

int	team_turn(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	t = 0;

	if (p[btle->tmp->perso].hplt <= 0)
		return (2);
	win->f = 2;
	sfSprite_setPosition(btle->turn.arros, v2f(1030, 800));
	while (t < 2) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		t = do_in_fight(win, btle, ennem, p);
		sfRenderWindow_display(win->win);
	}
	return (t);
}