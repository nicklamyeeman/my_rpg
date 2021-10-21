/*
** EPITECH PROJECT, 2018
** start_game
** File description:
** Launch the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	replace_stats(rpg_t *rp)
{
	sfVector2f	vec = sfView_getCenter(rp->cam.view);

	sfText_setPosition(rp->stat.name, v2f(vec.x - 500, vec.y - 300));
	sfText_setPosition(rp->stat.lvl, v2f(vec.x - 390, vec.y - 260));
	sfText_setPosition(rp->stat.hp, v2f(vec.x - 490, vec.y - 83));
	sfText_setPosition(rp->stat.hpm, v2f(vec.x - 420, vec.y - 83));
	sfText_setPosition(rp->stat.pm, v2f(vec.x - 490, vec.y - 47));
	sfText_setPosition(rp->stat.pmm, v2f(vec.x - 420, vec.y - 47));
	sfText_setPosition(rp->stat.atk, v2f(vec.x - 490, vec.y - 14));
	sfText_setPosition(rp->stat.def, v2f(vec.x - 490, vec.y + 20));
	sfText_setPosition(rp->stat.mag, v2f(vec.x - 490, vec.y + 56));
	sfText_setPosition(rp->stat.rm, v2f(vec.x - 490, vec.y + 92));
	sfText_setPosition(rp->stat.vit, v2f(vec.x - 490, vec.y + 128));
	sfText_setPosition(rp->stat.prec, v2f(vec.x - 490, vec.y + 164));
	sfText_setPosition(rp->stat.esq, v2f(vec.x - 490, vec.y + 200));
	sfText_setPosition(rp->stat.expe, v2f(vec.x - 490, vec.y + 233));
	vec = v2f(vec.x - 690, vec.y - 309);
	sfSprite_setPosition(rp->sprite[5].sprite, vec);
}

int	last_set(rpg_t *rp, chara_t car, char *tmp)
{
	tmp = int_to_char(car.esc);
	sfText_setString(rp->stat.esq, tmp);
	free(tmp);
	tmp = int_to_char(car.exp);
	sfText_setString(rp->stat.expe, tmp);
	free(tmp);
	rp->sprite[5].sprite = car.cares;
	replace_stats(rp);
	return (0);
}

int	second_set(rpg_t *rp, chara_t car, char *tmp)
{
	tmp = int_to_char(car.atk);
	sfText_setString(rp->stat.atk, tmp);
	free(tmp);
	tmp = int_to_char(car.def);
	sfText_setString(rp->stat.def, tmp);
	free(tmp);
	tmp = int_to_char(car.mg);
	sfText_setString(rp->stat.mag, tmp);
	free(tmp);
	tmp = int_to_char(car.rm);
	sfText_setString(rp->stat.rm, tmp);
	free(tmp);
	tmp = int_to_char(car.vit);
	sfText_setString(rp->stat.vit, tmp);
	free(tmp);
	tmp = int_to_char(car.prec);
	sfText_setString(rp->stat.prec, tmp);
	free(tmp);
	last_set(rp, car, tmp);
	return (0);
}

int	setstruct_totext(rpg_t *rp, chara_t car)
{
	char	*tmp;

	sfText_setString(rp->stat.name, car.name);
	tmp = int_to_char(car.lvl);
	sfText_setString(rp->stat.lvl, tmp);
	free(tmp);
	tmp = int_to_char(car.hplt);
	sfText_setString(rp->stat.hp, tmp);
	free(tmp);
	tmp = int_to_char(car.hpmx);
	sfText_setString(rp->stat.hpm, tmp);
	free(tmp);
	tmp = int_to_char(car.pmlt);
	sfText_setString(rp->stat.pm, tmp);
	free(tmp);
	tmp = int_to_char(car.pmmx);
	sfText_setString(rp->stat.pmm, tmp);
	free(tmp);
	second_set(rp, car, tmp);
	return (0);
}