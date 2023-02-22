#include "main.h"

/**
 * _abs - function that computes the absolute value
 * of an integer.
 *
 * @d: parameter to be checked
 *
 * Return: Always d
 */

int _abs(int d)
{
	if (d < 0)
		d = -(d);
	else if (d >= 0)
		d = d;
	return (d);
}
