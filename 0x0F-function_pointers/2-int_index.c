#include "function_pointers.h"

/**
 * int_index - a function that searches for an integer.
 *
 * @array: array
 * @size:  number of elements in the array 'array'
 * @cmp: pointer to the function
 *
 * Return: void
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL || cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);
			i++;
			}
		}
	}

	return (-1);
}
