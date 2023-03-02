#include "main.h"

/**
 * reverse_array - a function that reverses the content
 * of an array of integers.
 *
 * @n: number of elements of array
 * @a: array
 *
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i;
	int h;

	for (i = 0; i < n--; i++)
	{
		h = a[i];
		a[i] = a[n];
		a[n] = h;
	}
}
