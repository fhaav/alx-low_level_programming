#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 *
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int i = 0;

	if (!b)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		res = (res << 1) | (b[i] - '0');
		i++;
	}
	return (res);
}
