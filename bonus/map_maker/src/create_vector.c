/*
** EPITECH PROJECT, 2018
** create_vector
** File description:
** create a vector
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "proto.h"

sfVector2u	create_vector(int x, int y)
{
	sfVector2u	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfVector2f	create_vector2f(int x, int y)
{
	sfVector2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
