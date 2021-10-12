/*
** EPITECH PROJECT, 2018
** events
** File description:
** Handle the events
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

char	charactifier(int c)
{
	if (c >= 0 && c < 26)
		c += 97;
	else if (c == 50)
		return ('.');
	return (c);
}

char	*sub_to_buf(char *buf)
{
	int	i = 0;

	if (buf == NULL)
		return (buf);
	while (buf[i] != '\0')
		i++;
	if (i == 1) {
		buf = NULL;
		return (buf);
	}
	buf[i - 1] = '\0';
	return (buf);
}

char	*add_to_buf(char *buf, int c)
{
	int	i = 0;
	int	j = 0;
	char	*tmp = NULL;

	if (c == sfKeySpace)
		c = ' ';
	if (buf == NULL) {
		buf = malloc(2);
		buf[0] = charactifier(c);
		buf[1] = '\0';
	} else {
		for (i; buf[i] != '\0'; i++);
		tmp = malloc(i + 2);
		for (j; j != i; j++)
			tmp[j] = buf[j];
		tmp[j] = charactifier(c);
		tmp[i + 1] = '\0';
		return (tmp);
	}
	return (buf);
}

void	keyboard_event(sfEvent event, variables *var)
{
	if (event.key.code == 58) {
		var->select = var->buf;
		var->buf = NULL;
	}
	if (event.key.code == 59)
		var->buf = sub_to_buf(var->buf);
	else if (event.key.code != 38 && event.key.code != 58)
		var->buf = add_to_buf(var->buf, event.key.code);
}

void	events(variables *v, map_s **m)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(v->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(v->window);
		if (event.type == sfEvtKeyPressed)
			keyboard_event(event, v);
		if (event.type == sfEvtMouseMoved) {
			v->x_mouse = event.mouseMove.x;
			v->y_mouse = event.mouseMove.y;
		}
	}
	if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
		if (v->cur != NULL)
			add_texture(m, v->cur, v->x_mouse, v->y_mouse);
		else if (same_strings(v->select, "spawn"))
			set_spawn(m, v->x_mouse, v->y_mouse);
	}
	else if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
		delete_from_map(m, v->x_mouse, v->y_mouse);
}
