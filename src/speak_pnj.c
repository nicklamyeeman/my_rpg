/*
** EPITECH PROJECT, 2018
** speak_pnj
** File description:
** Speak to a pnj
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"
#include "get_next_line.h"

void	display_dialog_win(win_t *w)
{
	sfTexture	*txt;
	sfSprite	*sprite = sfSprite_create();

	txt = sfTexture_createFromFile("ressources/misc/dialog.png", NULL);
	sfSprite_setTexture(sprite, txt, sfTrue);
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfSprite_setPosition(sprite, create_vector(250, 585));
	sfSprite_setScale(sprite, create_vector(0.2, 0.2));
	sfRenderWindow_drawSprite(w->win, sprite, NULL);
	sfSprite_destroy(sprite);
	sfTexture_destroy(txt);
}

void	display_dialog(win_t *w, player_t *p)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("a/ppf.ttf");

	sfText_setFont(text, font);
	sfText_setString(text, p->dialog);
	sfText_setScale(text, create_vector(2, 2));
	sfText_setColor(text, sfBlack);
	sfText_setPosition(text, create_vector(250, 850));
	sfRenderWindow_drawText(w->win, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
}

void	display_name(win_t *w, player_t *p)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("a/ppf.ttf");

	sfText_setFont(text, font);
	sfText_setString(text, p->speaking_with);
	sfText_setScale(text, create_vector(1.5, 1.5));
	sfText_setColor(text, sfBlack);
	sfText_setPosition(text, create_vector(370, 735));
	sfRenderWindow_drawText(w->win, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
}

void	speak_pnj(win_t *w, player_t *p)
{
	display_dialog_win(w);
	display_dialog(w, p);
	display_name(w, p);
}
