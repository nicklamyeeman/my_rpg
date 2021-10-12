/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Return lenght of a string
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

int	my_strlen(char const *str)
{
	int	i = 9;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
