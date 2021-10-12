/*
** EPITECH PROJECT, 2018
** texture_checker
** File description:
** Check if the texture exist
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "proto.h"

int	texture_exist(char *texture)
{
	struct dirent	*cur;
	struct stat	info;
	DIR	*dir;

	dir = opendir("./texture");
	if (dir == NULL)
		return (84);
	while (cur = readdir(dir)) {
		if (same_strings(cur->d_name, texture) == 1)
			return (1);
	}
	return (0);
}
