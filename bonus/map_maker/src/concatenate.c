/*
** EPITECH PROJECT, 2017
** concatenate
** File description:
** concatenate two strings
*/

#include <stdlib.h>
#include <string.h>
#include "proto.h"

char	*concat_strings(char *str1, char *str2)
{
	int	i = 0;
	char	*to_re = malloc(my_strlen(str1) + my_strlen(str2) + 1);

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
