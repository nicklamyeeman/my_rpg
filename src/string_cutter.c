/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** cut parts of string
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

char	*cut_text(int *i, char *line)
{
	int	j = *i;
	int	k = 0;
	char	*to_ret = 0;

	while (line[j] != ' ' && line[j] != '\t')
		j++;
	to_ret = malloc(sizeof(char) * (j - *i) + 2);
	if (to_ret == NULL)
		return (NULL);
	while (*i != j && line[*i] != '\n') {
		to_ret[k] = line[*i];
		k++;
		*i += 1;
	}
	to_ret[k] = '\0';
	*i += 1;
	return (to_ret);
}

float	cut_frac(int *i, char *line)
{
	int	j = *i;
	float	to_ret = 0;

	while (line[j + 1] != ' ' && line[j] != '\t')
		j++;
	while (j != *i - 1) {
		to_ret += (line[j] - '0');
		to_ret /= 10;
		j --;
	}
	while (line[*i] != ' ' && line[*i] != '\t')
		*i += 1;
	return (to_ret);
}

float	cut_param(int *i, char *line)
{
	float	to_ret = 0;
	int	sign = 1;

	if (line[*i] == '-') {
		*i += 1;
		sign = -1;
	}
	while (line[*i] != ' ' && line[*i] != '\t') {
		to_ret *= 10;
		to_ret += line[*i] - '0';
		*i += 1;
		if (line[*i] == '.') {
			*i += 1;
			to_ret += cut_frac(i, line);
		}
	}
	*i += 1;
	to_ret *= sign;
	return (to_ret);
}
