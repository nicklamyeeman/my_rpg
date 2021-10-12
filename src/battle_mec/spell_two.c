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

int	pala_stwo(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	win->f = 12;
	if (p[btle->tmp->perso].pmlt < 3) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	while (win->f == 12) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	p[btle->tmp->perso].pmlt -= 3;
	win->f = 16;
	return (pala_stwo2(win, ennem, p, btle));
}

int	mage_stwo(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	win->f = 12;
	sfText_setCharacterSize(ennem[ennem->num].entex, 85);
	if (p[btle->tmp->perso].pmlt < 5) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	while (win->f == 12) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	p[btle->tmp->perso].pmlt -= 5;
	return (mage_stwo2(win, ennem, p, btle));
}

int	arch_stwo(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	win->f = 12;
	sfText_setCharacterSize(ennem[ennem->num].entex, 85);
	if (p[btle->tmp->perso].pmlt < 3) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	while (win->f == 12) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	p[btle->tmp->perso].pmlt -= 3;
	return (arch_stwo2(win, ennem, p, btle));
}

int	vole_stwo(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	win->f = 12;
	sfText_setCharacterSize(ennem[ennem->num].entex, 85);
	if (p[btle->tmp->perso].pmlt < 4) {
		vpap_fct(win, btle, ennem, p);
		return (1);
	}
	while (win->f == 12) {
		battle_event(win, btle, p, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, p, ennem);
		sfRenderWindow_display(win->win);
	}
	p[btle->tmp->perso].pmlt -= 4;
	return (vole_stwo2(win, ennem, p, btle));
}

int	mene_stwo(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *p)
{
	int	e = rand() % 100;

	win->f = 12;
	if (p[btle->tmp->perso].pmlt < 4) {
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
		p[btle->tmp->perso].pmlt -= 4;
		for (p->num = 0; p->num != 5; p->num ++)
			mene_stwo2(win, ennem, p, btle);
	}
	return (2);
}

