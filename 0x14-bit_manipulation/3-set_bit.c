#include "main.h"

/**
 * count_bits - ...
 * @n: ...
 * Return: ...
 */

unsigned int count_bits(unsigned long int n)
{
	unsigned int count = 0;

	while (n != 0)
	{
		count += n & 1;
		n >>= 1;
	}
	return (count);
}

/**
 * set_bit - a function that sets the value of a bit to 1 at a given index.
 * @n: pointer
 * @index: the index, starting from 0 of the bit you want to set.
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int num_bits;

	if (index > 63)
		return (-1);

	num_bits = count_bits(*n);
	if (index >= num_bits)
	{
		*n |= 1UL << index;
		return (0);
	}
	return (-1);
}
