#include "main.h"

/**
 * print_numbers - print the numbers from 0 to 9, followed by a new line.
 * Return: void
 */
void print_numbers(void)
{
int j;

for (j = '0'; j <= '9'; j++)
{
_putchar(j);
}
_putchar('\n');
}
