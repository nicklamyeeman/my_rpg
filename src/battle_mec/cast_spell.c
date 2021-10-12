/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** spell
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

void	clock_ponearc(chara_t *p, int *i, int *k)
{
	if (sfTime_asSeconds(p[2].spell.s1tim) > 0.1 &&
	p[2].spell.s1rec.top != (92 * 3)) {
		if (p[2].spell.s1rec.left == 92 * 3) {
			p[2].spell.s1rec.left = 0;
			*i += 1;
			*k = 500;
		}
		else
			p[2].spell.s1rec.left += 92;
		sfSprite_setTextureRect(p[2].spell.spe1s, p[2].spell.s1rec);
		sfClock_restart(p[2].spell.s1clo);
	}
}

void	cast_pone(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	ennem->num = 0;
	if (btle->tmp->perso == 0) {
		for (int i = 0; ennem[i].name != NULL; ennem->num++, i++)
			speone_pala(win, btle, p, ennem);
	}
	if (btle->tmp->perso == 1) {
		for (int i = 0; ennem[i].name != NULL; ennem->num++, i++)
			speone_mage(win, btle, p, ennem);
	}
	if (btle->tmp->perso == 2)
		speone_arch(win, btle, p, ennem);
	if (btle->tmp->perso == 3)
		speone_vole(win, btle, p, ennem);
	if (btle->tmp->perso == 4) {
		for (p->num = 0; p->num != 5; p->num++)
			speone_mene(win, btle, p, ennem);
	}
}

void	cast_ptwo(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	if (btle->tmp->perso == 0)
		spetwo_pala(win, btle, p, ennem);
	if (btle->tmp->perso == 1)
		spetwo_mage(win, btle, p, ennem);
	if (btle->tmp->perso == 2)
		spetwo_arch(win, btle, p, ennem);
	if (btle->tmp->perso == 3)
		spetwo_vole(win, btle, p, ennem);
	if (btle->tmp->perso == 4) {
		for (p->num = 0; p->num != 5; p->num++)
			spetwo_mene(win, btle, p, ennem);
	}
}

int	choose_target(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	sfVector2f	a = sfSprite_getPosition(btle->turn.arros);
	int	r = 0;

	r = (a.x == 70 && a.y == 895) ? which_pone(win, btle, ennem, perso) : r;
	r = (a.x == 70 && a.y == 965) ? which_ptwo(win, btle, ennem, perso) : r;
	return (r);
}

int	let_spell_us(win_t *win, btle_t *btle, ennem_t *ennem, chara_t *perso)
{
	int	t = 0;

	win->f = 10;
	sfSprite_setPosition(btle->turn.arros, v2f(70, 895));
	while (win->f == 10) {
		battle_event(win, btle, perso, ennem);
		sfRenderWindow_clear(win->win, sfWhite);
		display_window(win, btle, perso, ennem);
		sfRenderWindow_display(win->win);
	}
	if (win->f == 11)
		return (choose_target(win, btle, ennem, perso));
	else
		return (1);
}