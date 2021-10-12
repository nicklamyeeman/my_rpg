/*
** EPITECH PROJECT, 2018
** print_usage
** File description:
** Display the usage of the program
*/

#include <unistd.h>
#include <fcntl.h>
#include "rpg.h"

int	print_usage(void)
{
	int	fd = open("./config/usage", O_RDONLY);
	char	buf;

	if (fd == -1) {
		my_putstr("Error: Can't display the usage, ");
		my_putstr("file is missing.\n");
		return (84);
	}
	while (read(fd, &buf, 1) > 0)
		my_putchar(buf);
	close(fd);
	return (0);
}
