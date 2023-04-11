#include "main.h"

/**
 * print_binary - a function that prints the binary representation of a number.
 * @n: ...
 * Return: ...
 */

void print_binary(unsigned long int n)
{
	int c = 0;
	unsigned long int b = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (b)
	{
		if (n & b)
		{
			putchar('1');
			c = 1;
		}
		else if (c)
		{
			putchar('0');
		}
		b >>= 1;
	}
	if (!c)
	{
		putchar('0');
	}
}
