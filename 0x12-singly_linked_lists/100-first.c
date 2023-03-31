#include <stdio.h>

/**
 * my_sentence - Apply the constructor attribute to my_sentence()
 * so that it is executed before main().
 */
void my_sentence(void) __attribute__ ((constructor));

/**
 * my_sentence - implementation of my_sentence
 */
void my_sentence(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
