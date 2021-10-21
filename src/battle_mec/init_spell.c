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
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <fcntl.h>
#include "rpg.h"

spell_t	spell_mage()
{
	spell_t	spell;
	char	*spell1a = "Nova de Givre:\tPui: 10  Prec: 100 PM: 2\t";
	char	*sb = "Lance une explosion givree sur tous les ennemis.\n";
	char	*spell2a = "Boule de Feu:\tPui: 55  Prec: 90  PM: 5\t";
	char	*sb2 = "Lance une boule de feu puissante sur un ennemi.\n";

	spell.s1fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s1tex = sfText_create();
	spell.s2fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s2tex = sfText_create();
	sfText_setCharacterSize(spell.s1tex, 80);
	sfText_setCharacterSize(spell.s2tex, 80);
	sfText_setFont(spell.s1tex, spell.s1fon);
	sfText_setString(spell.s1tex, spell1a);
	sfText_setFont(spell.s2tex, spell.s2fon);
	sfText_setString(spell.s2tex, spell2a);
	sfText_setPosition(spell.s1tex, v2f(140, 860));
	sfText_setPosition(spell.s2tex, v2f(140, 930));
	spell.spell1 = my_strdup(my_strcat(spell1a, sb));
	spell.spell2 = my_strdup(my_strcat(spell2a, sb2));
	return (spell_txtmage(spell));
}

spell_t	spell_pala()
{
	spell_t	spell;
	char	*spell1a = "Consecration:\tPui: 20  Prec: 85  PM: 4\t";
	char	*spell1b = "Abat les cieux sur tous les ennemis.\n";
	char	*spell2a = "Toucher divin:\tPui: 60  Prec: 100 PM: 3";
	char	*spell2b = "\tRend des points de vie a un allie.\n";

	spell.s1fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s1tex = sfText_create();
	spell.s2fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s2tex = sfText_create();
	sfText_setCharacterSize(spell.s1tex, 80);
	sfText_setCharacterSize(spell.s2tex, 80);
	sfText_setFont(spell.s1tex, spell.s1fon);
	sfText_setString(spell.s1tex, spell1a);
	sfText_setFont(spell.s2tex, spell.s2fon);
	sfText_setString(spell.s2tex, spell2a);
	sfText_setPosition(spell.s1tex, v2f(140, 860));
	sfText_setPosition(spell.s2tex, v2f(140, 930));
	spell.spell1 = my_strdup(my_strcat(spell1a, spell1b));
	spell.spell2 = my_strdup(my_strcat(spell2a, spell2b));
	return (spell_txtpala(spell));
}

spell_t	spell_assas()
{
	spell_t spell;
	char	*spell1a = "Assassiner:\t\tPui: 90  Prec: 70  PM: 5\t";
	char	*spell1b = "Atk un ennemi. Chances de critique elevees.\n";
	char	*spell2a = "Evisceration:\tPui: 60  Prec: 90  PM: 4\t";
	char	*spell2b = "Lance une dague sur un ennemi.\n";

	spell.s1fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s1tex = sfText_create();
	spell.s2fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s2tex = sfText_create();
	sfText_setCharacterSize(spell.s1tex, 80);
	sfText_setCharacterSize(spell.s2tex, 80);
	sfText_setFont(spell.s1tex, spell.s1fon);
	sfText_setString(spell.s1tex, spell1a);
	sfText_setFont(spell.s2tex, spell.s2fon);
	sfText_setString(spell.s2tex, spell2a);
	sfText_setPosition(spell.s1tex, v2f(140, 860));
	sfText_setPosition(spell.s2tex, v2f(140, 930));
	spell.spell1 = my_strdup(my_strcat(spell1a, spell1b));
	spell.spell2 = my_strdup(my_strcat(spell2a, spell2b));
	return (spell_txtvole(spell));
}

spell_t	spell_archer()
{
	spell_t	spell;
	char	*spell1a = "Tirs Multiples:\tPui: 30  Prec: 100 PM: 4\t";
	char	*sb = "Lance 2 fleches aleatoirement sur les ennemis.\n";
	char	*spell2a = "Tir Meurtrier:\tPui: 50  Prec: 85  PM: 3\t";
	char	*spell2b = "Tire une fleche dans la tete d'un ennemi.\n";

	spell.s1fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s1tex = sfText_create();
	spell.s2fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s2tex = sfText_create();
	sfText_setCharacterSize(spell.s1tex, 80);
	sfText_setCharacterSize(spell.s2tex, 80);
	sfText_setFont(spell.s1tex, spell.s1fon);
	sfText_setString(spell.s1tex, spell1a);
	sfText_setFont(spell.s2tex, spell.s2fon);
	sfText_setString(spell.s2tex, spell2a);
	sfText_setPosition(spell.s1tex, v2f(140, 860));
	sfText_setPosition(spell.s2tex, v2f(140, 930));
	spell.spell1 = my_strdup(my_strcat(spell1a, sb));
	spell.spell2 = my_strdup(my_strcat(spell2a, spell2b));
	return (spell_txtarch(spell));
}

spell_t	spell_troub()
{
	spell_t	spell;
	char	*spell1a = "Rock N Roll:\t\tPui: 40  Prec: 100 PM: 8\t";
	char	*spell1b = "Joue de la guitare et rend des PM a tous.\n";
	char	*spell2a = "Vague de soins:\tPui: 40  Prec: 100 PM: 4\t";
	char	*spell2b = "Chante pour rendre des HP a tous les allies.\n";

	spell.s1fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s1tex = sfText_create();
	spell.s2fon = sfFont_createFromFile("./a/ppf.ttf");
	spell.s2tex = sfText_create();
	sfText_setCharacterSize(spell.s1tex, 80);
	sfText_setCharacterSize(spell.s2tex, 80);
	sfText_setFont(spell.s1tex, spell.s1fon);
	sfText_setString(spell.s1tex, spell1a);
	sfText_setFont(spell.s2tex, spell.s2fon);
	sfText_setString(spell.s2tex, spell2a);
	sfText_setPosition(spell.s1tex, v2f(140, 860));
	sfText_setPosition(spell.s2tex, v2f(140, 930));
	spell.spell1 = my_strdup(my_strcat(spell1a, spell1b));
	spell.spell2 = my_strdup(my_strcat(spell2a, spell2b));
	return (spell_txtmene(spell));
}