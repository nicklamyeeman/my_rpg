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

void	speone_mage(win_t *win, chara_t *p, ennem_t *ennem)
{
	sfVector2f	a = sfSprite_getPosition(ennem[ennem->num].ennes);

	a.x += 80;
	a.y -= 90;
	sfSprite_setPosition(p[1].spell.spe1s, a);
	sfSprite_setScale(p[1].spell.spe1s, v2f(1.4, 1.4));
	p[1].spell.s1tim = sfClock_getElapsedTime(p[1].spell.s1clo);
	if (sfTime_asSeconds(p[1].spell.s1tim) > 0.08 &&
	p[1].spell.s1rec.top != (192 * 3)) {
		if (p[1].spell.s1rec.left == (192 * 5)) {
			p[1].spell.s1rec.left = 0;
			p[1].spell.s1rec.top += 192;
		}
		else
			p[1].spell.s1rec.left += 192;
		sfSprite_setTextureRect(p[1].spell.spe1s, p[1].spell.s1rec);
		sfClock_restart(p[1].spell.s1clo);
	}
	update_spell(win, &p[1], 192, 3);
}

void	speone_pala(win_t *win, chara_t *p, ennem_t *ennem)
{
	sfVector2f	a = sfSprite_getPosition(ennem[ennem->num].ennes);
	sfFloatRect	b = sfSprite_getGlobalBounds(ennem[ennem->num].ennes);

	a.y = b.top + b.height;
	a.y -= 240;
	a.x -= 30;
	sfSprite_setPosition(p[0].spell.spe1s, a);
	sfSprite_setScale(p[0].spell.spe1s, v2f(2, 2));
	p[0].spell.s1tim = sfClock_getElapsedTime(p[0].spell.s1clo);
	if (sfTime_asSeconds(p[0].spell.s1tim) > 0.08 &&
	p[0].spell.s1rec.top != (192 * 2)) {
		if (p[0].spell.s1rec.left == 192 * 5) {
			p[0].spell.s1rec.left = 0;
			p[0].spell.s1rec.top += 192;
		}
		else
			p[0].spell.s1rec.left += 192;
		sfSprite_setTextureRect(p[0].spell.spe1s, p[0].spell.s1rec);
		sfClock_restart(p[0].spell.s1clo);
	}
	update_spell(win, &p[0], 192, 2);
}

void	speone_mene(win_t *win, chara_t *p)
{
	sfVector2f	a = sfSprite_getPosition(p[p->num].perss);

	a.x -= 60;
	sfSprite_setPosition(p[4].spell.spe1s, a);
	sfSprite_setScale(p[4].spell.spe1s, v2f(2, 2));
	p[4].spell.s1tim = sfClock_getElapsedTime(p[4].spell.s1clo);
	if (sfTime_asSeconds(p[4].spell.s1tim) > 0.05 &&
	p[4].spell.s1rec.top != (192 * 3)) {
		if (p[4].spell.s1rec.left == (192 * 5)) {
			p[4].spell.s1rec.left = 0;
			p[4].spell.s1rec.top += 192;
		}
		else
			p[4].spell.s1rec.left += 192;
		sfSprite_setTextureRect(p[4].spell.spe1s, p[4].spell.s1rec);
		sfClock_restart(p[4].spell.s1clo);
	}
	update_spell(win, &p[4], 192, 3);
}

void	speone_vole(win_t *win, chara_t *p, ennem_t *ennem)
{
	sfVector2f	a;

	a = sfSprite_getPosition(ennem[ennem->num].ennes);
	sfSprite_setPosition(p[3].spell.spe1s, a);
	sfSprite_setScale(p[3].spell.spe1s, v2f(3.6, 3.6));
	p[3].spell.s1tim = sfClock_getElapsedTime(p[3].spell.s1clo);
	if (sfTime_asSeconds(p[3].spell.s1tim) > 0.1 &&
	p[3].spell.s1rec.top != 98) {
		if (p[3].spell.s1rec.left == (96 * 5))
			p[3].spell.s1rec.top += 98;
		else
			p[3].spell.s1rec.left += 96;
		sfSprite_setTextureRect(p[3].spell.spe1s, p[3].spell.s1rec);
		sfClock_restart(p[3].spell.s1clo);
	}
	update_spell(win, &p[3], 98, 1);
}

void	speone_arch(win_t *win, chara_t *p)
{
	static	int	i = 0;
	static	int	k = 200;

	sfSprite_setPosition(p[2].spell.spe1s, v2f(800, k));
	sfSprite_setScale(p[2].spell.spe1s, v2f(3, 3));
	p[2].spell.s1tim = sfClock_getElapsedTime(p[2].spell.s1clo);
	clock_ponearc(p, &i, &k);
	sfRenderWindow_drawSprite(win->win, p[2].spell.spe1s, NULL);
	if (i == 2) {
		p[2].spell.s1rec.left = 0;
		i = 0;
		k = 200;
		win->f = 13;
	}
}