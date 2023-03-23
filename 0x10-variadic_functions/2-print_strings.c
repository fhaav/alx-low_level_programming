#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - a function that prints strings,
 * followed by a new line.
 *
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function
 * @...: a variable number of strings to be printed.
 *
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list numb;
	unsigned int i;
	char *str;

	va_start(numb, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(numb, char *);

		if (str)
			printf("%s", str);
		else
			printf("(nil)");

		if (i < n - 1)
			if (separator)
				printf("%s", separator);
	}

	printf("\n");
	va_end(numb);
}
