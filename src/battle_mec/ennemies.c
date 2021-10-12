/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** ennemies
*/

#include "rpg.h"

ennem_t	init_troll(void)
{
	ennem_t	ennem;

	ennem.name = my_strdup("Troll");
	ennem.coef = 1;
	ennem.hplt = 22;
	ennem.hpmx = 22;
	ennem.atk = 14;
	ennem.mag = 2;
	ennem.def = 8;
	ennem.rm = 6;
	ennem.vit = 6;
	ennem.exp = 20;
	return (init_troltxt(ennem));
}

ennem_t	init_bidoof(void)
{
	ennem_t	ennem;

	ennem.name = my_strdup("Bidoof");
	ennem.coef = 1;
	ennem.hplt = 30;
	ennem.hpmx = 30;
	ennem.atk = 0;
	ennem.mag = 0;
	ennem.def = 30;
	ennem.rm = 30;
	ennem.vit = 30;
	ennem.exp = 1;
	return (init_bidotxt(ennem));
}

ennem_t	init_gob(void)
{
	ennem_t	ennem;

	ennem.name = my_strdup("Gob");
	ennem.coef = 1;
	ennem.hplt = 4;
	ennem.hpmx = 4;
	ennem.atk = 4;
	ennem.mag = 4;
	ennem.def = 4;
	ennem.rm = 4;
	ennem.vit = 4;
	ennem.exp = 6;
	return (init_gobetxt(ennem));
}

ennem_t	init_pampa(void)
{
	ennem_t	ennem;

	ennem.name = my_strdup("Pampa");
	ennem.coef = 1;
	ennem.hplt = 20;
	ennem.hpmx = 20;
	ennem.atk = 2;
	ennem.mag = 2;
	ennem.def = 6;
	ennem.rm = 6;
	ennem.vit = 2;
	ennem.exp = 70;
	return (init_pamptxt(ennem));
}