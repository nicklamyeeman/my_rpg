/*
** EPITECH PROJECT, 2018
** destroy_map
** File description:
** Destroy the map
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "proto.h"

void	destroy_map(map_s **map)
{
	while (*map != NULL) {
		sfTexture_destroy((*map)->texture);
		*map = (*map)->next;
	}
}
