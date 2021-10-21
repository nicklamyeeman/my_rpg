/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** go fight
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

void	ennem_touch(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	c = rand() % 16;
	int	lvl = ennem[btle->tmp->perso].coef;
	int	atk = ennem[btle->tmp->perso].atk;
	int	def = p[p->num].def;

	if (c == 0)
		c = 2;
	else
		c = 1;
	btle->hp = ((((lvl * 0.4 + 2) * atk * 20) / (def * 50)) + 2) * c;
	btle->hp = (atk == 0) ? 0 : btle->hp;
	p[p->num].hplt -= btle->hp;
	if (c == 2)
		crit_fct(win, btle, ennem, p);
	while (win->f == 26) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		sfText_setString(btle->hptex, int_to_char(btle->hp));
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	ennem_atk(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	int	k = rand() % 5;
	int	e = rand() % 100;

	win->f = 24;
	while (perso[k].hplt == 0)
		k = rand() % 5;
	perso->num = k;
	while (win->f == 24) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
	if (e >= 0 && e <= (perso[k].esc - 1))
		ratk_fct(win, btle, ennem, perso);
	else {
		win->f = 26;
		ennem_touch(win, btle, ennem, perso);
	}
}

void	ennem_turn(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	if (ennem[btle->tmp->perso].hplt <= 0)
		return;
	else
		ennem_atk(win, btle, ennem, perso);
}

int	analyse_turn(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	h = 0;
	int	e = 0;

	while (end_team(p) != 1 && end_ennem(ennem) != 1) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		h = btle->tmp->type;
		e = (h < 0) ? team_turn(win, btle, ennem, p) : e;
		(h >= 0) ? ennem_turn(win, btle, ennem, p) : 0;
		if (e == 3)
			return (2);
		if (btle->tmp->next == NULL)
			btle->tmp = btle->order;
		else
			btle->tmp = btle->tmp->next;
		sfRenderWindow_display(win->win);
	}
	if (end_team(p) == 1)
		return (0);
	return (1);
}

int	go_fight(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	btle->order = NULL;
	for (int k = 0; k != 5; k ++)
		my_put_in_listp(perso, k, -1, &btle->order);
	for (int k = 0; ennem[k].name != NULL; k ++)
		my_put_in_listc(ennem, k, &btle->order);
	sort(&btle->order);
	for (int g = 0; ennem[g].name != NULL; g ++)
		ennem[g].hplt = ennem[g].hpmx;
	btle->tmp = btle->order;
	return (analyse_turn(win, btle, ennem, perso));
}