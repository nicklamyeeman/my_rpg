/*
** EPITECH PROJECT, 2018
** print_buf
** File description:
** print the buffer of what you are actually typing
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "proto.h"

void	print_buf(sfRenderWindow *w, char *buf)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("font.ttf");

	if (buf == NULL) {
		sfText_destroy(text);
		sfFont_destroy(font);
		return;
	}
	sfText_setFont(text, font);
	sfText_setString(text, buf);
	sfRenderWindow_drawText(w, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
}
