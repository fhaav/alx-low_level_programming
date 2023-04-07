#include "lists.h"

/**
 * _memory - new memory address is assigned to pointers in a list
 * @old: the old list to be checked
 * @prop: this is the size of the new list
 * @newnode: a newnode added to the list
 * Return: new list pointer
 */

listint_t **_memory(listint_t **old, size_t prop, listint_t *newnode)
{
	listint_t **new;
	size_t a;

	new = malloc(prop * sizeof(listint_t *));
	if (new == NULL)
	{
		free(old);
		exit(98);
	}
	for (a = 0; a < prop - 1; a++)
		new[a] = old[a];
	new[a] = newnode;
	free(old);
	return (new);
}

/**
 * free_listint_safe - a function that frees a listint_t list.
 * @h: pointer to the head node
 * Return: the number of nodes in the list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t a;
	size_t count = 0;
	listint_t **old = NULL;
	listint_t *next;

	if (h == NULL || *h == NULL)
		return (count);
	while (*h != NULL)
	{
		for (a = 0; a < count; a++)
		{
			if (*h == old[a])
			{
				*h = NULL;
				free(old);
				return (count);
			}
		}
		count++;
		old = _memory(old, count, *h);
		next = (*h)->next->next;
		free(*h);
		*h = next;
	}
	free(old);
	return (count);
}
