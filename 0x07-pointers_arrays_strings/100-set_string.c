#include "main.h"

/**
 * set_string - set the value of a pointer to a char.
 *
 * @to:pointer to char
 * @s: pointer to pointer
 */

void set_string(char **s, char *to)
{
	*s = to;
}
