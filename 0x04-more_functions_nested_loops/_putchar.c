#include "main.h"
#include <unistd.h>
/**
 * putchar - writes the character c to stdout
 * @c: The character to print
 * Return 1 if true, 0 if false
 * On error, return -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
