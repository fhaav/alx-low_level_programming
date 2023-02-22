#include "main.h"

/**
 * print_last_digit - function that prints the last digit
 * of a number.
 *
 *@j: parameter to be checked
 *
 *Return: Always h
 */

int print_last_digit(int j)
{
	int h;

	h = j % 10;
	if (j < 0)
		h = -h;
	_putchar (h + '0');
	return (h);
}

