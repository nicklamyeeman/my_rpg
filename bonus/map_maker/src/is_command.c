/*
** EPITECH PROJECT, 2018
** is_command
** File description:
** Check if it's a command and execute it
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

char	*cut_cmd(char *cmd, int i)
{
	int	j = 0;
	char	*to_re = malloc(i + 1);

	while (j != i) {
		to_re[j] = cmd[j];
		j++;
	}
	to_re[j] = '\0';
	return (to_re);
}

char	*cut_name(char *cmd, int i)
{
	cmd = cmd + i + 1;
	return (cmd);
}

int	is_command(char *select, map_s **map)
{
	int	i = 0;
	char	*cmd = NULL;
	char	*name = NULL;

	if (same_strings(select, "spawn"))
		return (1);
	if (same_strings(select, "clear")) {
		destroy_map(map);
		return (1);
	}
	while (select[i] != '\0' && select[i] != ' ')
		i++;
	if (select[i] == '\0')
		return (0);
	cmd = cut_cmd(select, i);
	name = cut_name(select, i);
	if (same_strings(cmd, "save"))
		save(map, concat_strings("./saves/", name));
	if (same_strings(cmd, "load"))
		load(map, name);
	return (1);
}
