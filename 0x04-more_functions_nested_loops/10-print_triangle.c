#include "main.h"

/**
 * print_triangle - a function that prints a triangle, followed by a new line.
 * If size is 0 or less, the function should print only a new line
 *
 * @size: size of the triangle
 *
 * Return: nothing on success
 */

void print_triangle(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i, j;

		for (i = 1; i <= size; i++)
		{
			for (j = i; j < size; j++)
			{
				_putchar(' ');
			}
			for (j = 1; j <= i; j++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
