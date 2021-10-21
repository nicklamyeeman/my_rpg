/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** initperso
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

chara_t	init_mage(void)
{
	chara_t	perso;

	perso.name = my_strdup("Mage");
	perso.lvl = 1;
	perso.hplt = 12;
	perso.hpmx = 12;
	perso.pmlt = 15;
	perso.pmmx = 15;
	perso.def = 8;
	perso.rm = 12;
	perso.atk = 8;
	perso.mg = 16;
	perso.vit = 8;
	perso.prec = 90;
	perso.esc = 10;
	perso.pc = 2;
	perso.exp = 0;
	perso.spell = spell_mage();
	return (perso);
}

chara_t	init_pala(void)
{
	chara_t	perso;

	perso.name = my_strdup("Paladin");
	perso.lvl = 1;
	perso.hplt = 18;
	perso.hpmx = 18;
	perso.pmlt = 8;
	perso.pmmx = 8;
	perso.def = 12;
	perso.rm = 10;
	perso.atk = 10;
	perso.mg = 4;
	perso.vit = 6;
	perso.prec = 100;
	perso.esc = 10;
	perso.pc = 2;
	perso.exp = 0;
	perso.spell = spell_pala();
	return (perso);
}

chara_t	init_assassin(void)
{
	chara_t	perso;

	perso.name = my_strdup("Voleur");
	perso.lvl = 1;
	perso.hplt = 6;
	perso.hpmx = 6;
	perso.pmlt = 15;
	perso.pmmx = 15;
	perso.def = 6;
	perso.rm = 6;
	perso.atk = 18;
	perso.mg = 4;
	perso.vit = 15;
	perso.prec = 100;
	perso.esc = 20;
	perso.pc = 2;
	perso.exp = 0;
	perso.spell = spell_assas();
	return (perso);
}

chara_t	init_archer(void)
{
	chara_t	perso;

	perso.name = my_strdup("Archer");
	perso.lvl = 1;
	perso.hplt = 8;
	perso.hpmx = 8;
	perso.pmlt = 8;
	perso.pmmx = 8;
	perso.def = 6;
	perso.rm = 8;
	perso.atk = 15;
	perso.mg = 12;
	perso.vit = 12;
	perso.prec = 100;
	perso.esc = 20;
	perso.pc = 2;
	perso.exp = 0;
	perso.spell = spell_archer();
	return (perso);
}

chara_t	init_troub(void)
{
	chara_t	perso;

	perso.name = my_strdup("Menestrel");
	perso.lvl = 1;
	perso.hplt = 14;
	perso.hpmx = 14;
	perso.pmlt = 16;
	perso.pmmx = 16;
	perso.def = 10;
	perso.rm = 12;
	perso.atk = 2;
	perso.mg = 14;
	perso.vit = 10;
	perso.prec = 90;
	perso.esc = 20;
	perso.pc = 2;
	perso.exp = 0;
	perso.spell = spell_troub();
	return (perso);
}