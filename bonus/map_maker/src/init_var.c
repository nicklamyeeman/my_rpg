/*
** EPITECH PROJECT, 2018
** init_var
** File description:
** initialise variables
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"

variables	init_var()
{
	variables var;
	sfVideoMode	mode = {1920, 1080, 32};

	var.window = sfRenderWindow_create(mode, "map_maker", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(var.window, 60);
	var.select = NULL;
	var.buf = NULL;
	var.cur = NULL;
	var.x_bg = 0;
	var.y_bg = 0;
	return (var);
}
