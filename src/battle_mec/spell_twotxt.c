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

void	spetwo_pala(win_t *win, chara_t *p)
{
	sfVector2f	a = sfSprite_getPosition(p[p->num].perss);

	a.y += 60;
	a.x -= 20;
	sfSprite_setPosition(p[0].spell.spe2s, a);
	sfSprite_setScale(p[0].spell.spe2s, v2f(2, 2));
	p[0].spell.s2tim = sfClock_getElapsedTime(p[0].spell.s2clo);
	if (sfTime_asSeconds(p[0].spell.s2tim) > 0.08 &&
	p[0].spell.s2rec.top != (192 * 4)) {
		if (p[0].spell.s2rec.left == 192 * 5) {
			p[0].spell.s2rec.left = 0;
			p[0].spell.s2rec.top += 192;
		}
		else
			p[0].spell.s2rec.left += 192;
		sfSprite_setTextureRect(p[0].spell.spe2s, p[0].spell.s2rec);
		sfClock_restart(p[0].spell.s2clo);
	}
	update_spell2(win, &p[0], 192, 4);
}

void	spetwo_mage(win_t *win, chara_t *p, ennem_t *ennem)
{
	sfVector2f	a = sfSprite_getPosition(ennem[ennem->num].ennes);

	sfSprite_setPosition(p[1].spell.spe2s, a);
	sfSprite_setScale(p[1].spell.spe2s, v2f(2, 2));
	p[1].spell.s2tim = sfClock_getElapsedTime(p[1].spell.s2clo);
	if (sfTime_asSeconds(p[1].spell.s2tim) > 0.08 &&
	p[1].spell.s2rec.top != (192 * 5)) {
		if (p[1].spell.s2rec.left == 192 * 5) {
			p[1].spell.s2rec.left = 0;
			p[1].spell.s2rec.top += 192;
		}
		else
			p[1].spell.s2rec.left += 192;
		sfSprite_setTextureRect(p[1].spell.spe2s, p[1].spell.s2rec);
		sfClock_restart(p[1].spell.s2clo);
	}
	update_spell2(win, &p[1], 192, 5);
}

void	spetwo_arch(win_t *win, chara_t *p)
{
	sfVector2f	a = sfSprite_getPosition(p[2].perss);

	a.y -= 70;
	a.x += 80;
	sfSprite_setPosition(p[2].spell.spe2s, a);
	sfSprite_setScale(p[2].spell.spe2s, v2f(-2, 2.5));
	p[2].spell.s2tim = sfClock_getElapsedTime(p[2].spell.s2clo);
	if (sfTime_asSeconds(p[2].spell.s2tim) > 0.05 &&
	p[2].spell.s2rec.top != (90 * 2)) {
		if (p[2].spell.s2rec.left == 70 * 6) {
			p[2].spell.s2rec.left = 0;
			p[2].spell.s2rec.top += 90;
		}
		else
			p[2].spell.s2rec.left += 70;
		sfSprite_setTextureRect(p[2].spell.spe2s, p[2].spell.s2rec);
		sfClock_restart(p[2].spell.s2clo);
	}
	update_spell2(win, &p[2], 90, 2);
}

void	spetwo_vole(win_t *win, chara_t *p, ennem_t *ennem)
{
	sfVector2f	a = sfSprite_getPosition(ennem[ennem->num].ennes);

	a.x -= 50;
	sfSprite_setPosition(p[3].spell.spe2s, a);
	sfSprite_setScale(p[3].spell.spe2s, v2f(2, 2));
	p[3].spell.s2tim = sfClock_getElapsedTime(p[3].spell.s2clo);
	if (sfTime_asSeconds(p[3].spell.s2tim) > 0.06 &&
	p[3].spell.s2rec.top != (192 * 4)) {
		if (p[3].spell.s2rec.left == 192 * 5) {
			p[3].spell.s2rec.left = 0;
			p[3].spell.s2rec.top += 192;
		}
		else
			p[3].spell.s2rec.left += 192;
		sfSprite_setTextureRect(p[3].spell.spe2s, p[3].spell.s2rec);
		sfClock_restart(p[3].spell.s2clo);
	}
	update_spell2(win, &p[3], 192, 4);
}

void	spetwo_mene(win_t *win, chara_t *p)
{
	sfVector2f	a = sfSprite_getPosition(p[p->num].perss);

	a.x -= 60;
	sfSprite_setPosition(p[4].spell.spe2s, a);
	sfSprite_setScale(p[4].spell.spe2s, v2f(2, 2));
	p[4].spell.s2tim = sfClock_getElapsedTime(p[4].spell.s2clo);
	if (sfTime_asSeconds(p[4].spell.s2tim) > 0.05 &&
	p[4].spell.s2rec.top != (192 * 3)) {
		if (p[4].spell.s2rec.left == (192 * 5)) {
			p[4].spell.s2rec.left = 0;
			p[4].spell.s2rec.top += 192;
		}
		else
			p[4].spell.s2rec.left += 192;
		sfSprite_setTextureRect(p[4].spell.spe2s, p[4].spell.s2rec);
		sfClock_restart(p[4].spell.s2clo);
	}
	update_spell2(win, &p[4], 192, 3);
}