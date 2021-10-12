/*
** EPITECH PROJECT, 2018
** same_strings
** File description:
** Compare two strings and return 1 if they are the same
*/

#include <unistd.h>

int	is_in_it(char *str1, char *str2)
{
	int	i = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[i] == str2[i])
		i++;
	if (str1[i] == '\0')
		return (1);
	return (0);
}

int	same_strings(char *str1, char *str2)
{
	int	i = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[i] == str2[i]) {
		if (str1[i] == '\0' && str2[i] != '\0')
			return (0);
		if (str2[i] == '\0' && str1[i] != '\0')
			return (0);
		if (str1[i] == '\0' && str2[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
