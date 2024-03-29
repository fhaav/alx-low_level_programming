#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - a function that prints numbers,
 * followed by a new line.
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 * @...: a variable number of numbers to be printed.
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list mynumbers;
	unsigned int i;

	va_start(mynumbers, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(mynumbers, int));

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(mynumbers);
}
