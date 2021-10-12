/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** spell one
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

int	pala_sone(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	e = rand() % 85;

	win->f = 12;
	if (p[btle->tmp->perso].pmlt < 4) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	p[btle->tmp->perso].pmlt -= 4;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		while (win->f == 12) {
			battle_event(win, btle, p, ennem);
			sfRenderWindow_clear(win->win, sfWhite);
			display_window(win, btle, p, ennem);
			sfRenderWindow_display(win->win);
		}
		pala_sone2(win, btle, ennem, p);
	}
	return (2);
}

int	mage_sone(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	e = rand() % 100;

	win->f = 12;
	if (p[btle->tmp->perso].pmlt < 2) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	p[btle->tmp->perso].pmlt -= 2;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		while (win->f == 12) {
			battle_event(win, btle, p, ennem);
			sfRenderWindow_clear(win->win, sfWhite);
			display_window(win, btle, p, ennem);
			sfRenderWindow_display(win->win);
		}
		mage_sone2(win, btle, ennem, p);
	}
	return (2);
}

int	arch_sone(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	e = rand() % 100;

	if (p[btle->tmp->perso].pmlt < 4) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	p[btle->tmp->perso].pmlt -= 4;
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else
		arch_sone_oth(win, btle, ennem, p);
	return (2);
}

int	vole_sone(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	win->f = 12;
	if (p[btle->tmp->perso].pmlt < 5) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	sfText_setCharacterSize(ennem[ennem->num].entex, 85);
	while (win->f == 12) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	p[btle->tmp->perso].pmlt -= 5;
	return (vole_sone2(win, ennem, p, btle));
}

int	mene_sone(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	e = rand() % 100;

	win->f = 12;
	if (p[btle->tmp->perso].pmlt < 8) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	if (e >= p[btle->tmp->perso].prec && e <= 100)
		ratk_fct(win, btle, ennem, p);
	else {
		while (win->f == 12) {
			battle_event(win, btle, p, ennem);
			sfRenderWindow_clear(win->win, sfWhite);
			display_window(win, btle, p, ennem);
			sfRenderWindow_display(win->win);
		}
		p[btle->tmp->perso].pmlt -= 8;
		for (p->num = 0; p->num != 5; p->num ++)
			mene_sone2(win, ennem, p, btle);
	}
	return (2);
}