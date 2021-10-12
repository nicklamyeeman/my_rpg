/*
** EPITECH PROJECT, 2018
** create_vector
** File description:
** Create a 2D vector
*/

#include <SFML/System.h>

sfVector2f	create_vector(float x, float y)
{
	sfVector2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
