/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** spells
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

spell_t	spell_mage()
{
	spell_t spell;

	char	*spell1a = "Nova de Givre:\tPui: 10  Prec: 100 PM: 2\tLanc";
	char	*spell1b = "e une explosion givree sur tous les ennemis.\n";
	char	*spell1 = my_strcat(spell1a, spell1b);

	char	*spell2a = "Boule de Feu:\tPui: 55  Prec: 90  PM: 5\tLan";
	char	*spell2b = "ce une boule de feu puissante sur un ennemi.\n";
	char	*spell2 = my_strcat(spell2a, spell2b);

	spell.spell1 = my_strdup(spell1);
	spell.spell2 = my_strdup(spell2);
	return (spell);
}

spell_t	spell_pala()
{
	spell_t spell;

	char	*spell1a = "Consecration:\tPui: 20  Prec: 85  PM: 4\tAbat ";
	char	*spell1b = "la puissance des cieux sur tous les ennemis.\n";
	char	*spell1 = my_strcat(spell1a, spell1b);

	char	*spell2a = "Toucher divin:\tPui: 60  Prec: 100 PM: 3";
	char	*spell2b = "\tRend des points de vie a un allie.\n";
	char	*spell2 = my_strcat(spell2a, spell2b);

	spell.spell1 = my_strdup(spell1);
	spell.spell2 = my_strdup(spell2);
	return (spell);
}

spell_t	spell_assas()
{
	spell_t spell;

	char	*spell1a = "Assassiner:\t\tPui: 90  Prec: 70  PM: 5\tAttaq";
	char	*spell1b = "ue un ennemi. Chances de critique elevees.\n";
	char	*spell1 = my_strcat(spell1a, spell1b);

	char	*spell2a = "Evisceration:\tPui: 60  Prec: 90  PM: 4\tLanc";
	char	*spell2b = "e une dague sur un ennemi.\n";
	char	*spell2 = my_strcat(spell2a, spell2b);

	spell.spell1 = my_strdup(spell1);
	spell.spell2 = my_strdup(spell2);
	return (spell);
}

spell_t	spell_archer()
{
	spell_t spell;

	char	*spell1a = "Tirs Multiples:\tPui: 30  Prec: 100 PM: 4\tLan";
	char	*spell1b = "ce 2 fleches aleatoirement sur les ennemis.\n";
	char	*spell1 = my_strcat(spell1a, spell1b);

	char	*spell2a = "Tir Meurtrier:\tPui: 50  Prec: 85  PM: 3\tTir";
	char	*spell2b = "e une fleche dans la tete d'un ennemi.\n";
	char	*spell2 = my_strcat(spell2a, spell2b);

	spell.spell1 = my_strdup(spell1);
	spell.spell2 = my_strdup(spell2);
	return (spell);
}

spell_t	spell_troub()
{
	spell_t spell;

	char	*spell1a = "Rock N Roll:\t\tPui: 40  Prec: 100 PM: 8\tJoue";
	char	*spell1b = "de la guitare, rend des PM a tous les allies\n";
	char	*spell1 = my_strcat(spell1a, spell1b);

	char	*spell2a = "Vague de soins:\tPui: 40  Prec: 100 PM: 4\tCha";
	char	*spell2b = "nte pour rendre des HP a tous les allies.\n";
	char	*spell2 = my_strcat(spell2a, spell2b);

	spell.spell1 = my_strdup(spell1);
	spell.spell2 = my_strdup(spell2);
	return (spell);
}