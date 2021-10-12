/*
** EPITECH PROJECT, 2018
** concatenate
** File description:
** Concatenate two strings and return the result
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

char	*concat_str(char *str1, char *str2)
{
	int	i = 0;
	char	*to_re = malloc(my_strlen(str1) + my_strlen(str2) + 2);

	if (str1 == NULL)
		return (str2);
	if (str2 == NULL)
		return (str1);
	while (i != my_strlen(str1)) {
		to_re[i] = str1[i];
		i++;
	}
	while (i != my_strlen(str1) + my_strlen(str2)) {
		to_re[i] = str2[i - my_strlen(str1)];
		i++;
	}
	to_re[i] = '\0';
	return (to_re);
}
