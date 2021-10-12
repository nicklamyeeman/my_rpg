/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** int to char
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <fcntl.h>
#include "rpg.h"

void	check_first(int *n, int *j, int *i, int *s)
{
	if (*n < 0) {
		*n = *n * -1;
		*j = 1;
	}
	*i = *n;
	while (*i) {
		*i /= 10;
		*s += 1;
	}
}

char	*zero_char(char *str)
{
	str = malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*int_to_char(int n)
{
	char	*str = NULL;
	int	s = 0;
	int	i = 0;
	int	j = 0;

	if (n == 0)
		return (zero_char(str));
	else {
		check_first(&n, &j, &i, &s);
		str = malloc(sizeof(char) * s + j + 1);
		if (str == NULL)
			return (NULL);
		for (i = s + j - 1; i >= j; i --, n /= 10)
			str[i] = n % 10 + '0';
		if (j)
			str[0] = '-';
		str[s + j] = '\0';
		return (str);
	}
}