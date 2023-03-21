#include "dog.h"

/**
 * init_dog - a function that initialize a variable of type struct dog
 *
 * @d: d is a pointer to struct dog to initialize.
 * @name: pointer to initialize
 * @age: pointer to initialize
 * @owner: pointer to initialize
 *
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		(*d).name = name;
		(*d).age = age;
		(*d).owner = owner;
	}
}
