#include "main.h"

/**
 * _memset - fill memory with a constant byte.
 *
 * @n: number of bytes to be changed
 * @b: the desired value
 * @s: starting address of memory to be filled
 *
 * Return: changed array with new value for n bytes
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
