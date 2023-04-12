#include "main.h"

/**
 * flip_bits - a function that returns the number of bits
 * you would need to flip to get from one number to another.
 *
 * @n: num
 * @m: num
 *
 * Return: the number of bits that need to be flipped to convert n to m.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count = 0;
	size_t h;
	unsigned long int X;

	X = n ^ m;
	for (h = 0; h < sizeof(unsigned long int) * 8; h++)
	{
		if (((X >> h) & 1UL) == 1)
			count++;
	}
	return (count);
}
