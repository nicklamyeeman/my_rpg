/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main file
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include "rpg.h"

int	check_display(char **env)
{
	int	i = 0;

	while (env[i] != NULL) {
		if (my_strcmp(env[i], "DISPLAY=:0") == 0)
			return (1);
		if (my_strcmp(env[i], "DISPLAY=:0.0") == 0)
			return (1);
		i++;
	}
	my_printf("%r\n", "No DISPLAY variable");
	return (0);
}

int	main(int ac, char **av, char **env)
{
	if (check_display(env) == 0)
		return (84);
	if (ac > 1) {
		if (same_strings("-h", av[1]))
			return (print_usage());
		my_putstr("Invalid arguments, try using '-h'.\n");
		return (84);
	}
	launch_menu();
	return (0);
}
