/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** which perso
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

void	before_help(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	win->f = 14;
	p->num = 0;
	while (win->f == 14) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
}

void	before_spell(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	win->f = 4;
	ennem->num = 0;
	while (win->f == 4) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
}

int	which_pone(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	int	ret = 1;
	int	t = 0;

	if (btle->tmp->perso == 0)
		ret = pala_sone(win, btle, ennem, perso);
	if (btle->tmp->perso == 1)
		ret = mage_sone(win, btle, ennem, perso);
	if (btle->tmp->perso == 2)
		ret = arch_sone(win, btle, ennem, perso);
	if (btle->tmp->perso == 3) {
		before_spell(win, btle, perso, ennem);
		if (win->f == 2)
			return (1);
		while (t < 1)
			t = vole_sone(win, btle, ennem, perso);
		ret = t;
	}
	if (btle->tmp->perso == 4)
		ret = mene_sone(win, btle, ennem, perso);
	return (ret);
}

int	which_ptwo2(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	int	t = 0;

	if (btle->tmp->perso == 2) {
		before_spell(win, btle, perso, ennem);
		if (win->f == 2)
			return (1);
		while (t < 1)
			t = arch_stwo(win, btle, ennem, perso);
	}
	if (btle->tmp->perso == 3) {
		before_spell(win, btle, perso, ennem);
		if (win->f == 2)
			return (1);
		while (t < 1)
			t = vole_stwo(win, btle, ennem, perso);
	}
	if (btle->tmp->perso == 4)
		t = mene_stwo(win, btle, ennem, perso);
	return (t);
}

int	which_ptwo(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	int	t = 0;

	if (btle->tmp->perso == 0) {
		before_help(win, btle, perso, ennem);
		if (win->f == 2)
			return (1);
		while (t < 1)
			t = pala_stwo(win, btle, ennem, perso);
	}
	if (btle->tmp->perso == 1) {
		before_spell(win, btle, perso, ennem);
		if (win->f == 2)
			return (1);
		while (t < 1)
			t = mage_stwo(win, btle, ennem, perso);
	}
	if (t >= 1)
		return (t);
	else
		return (which_ptwo2(win, btle, ennem, perso));
}