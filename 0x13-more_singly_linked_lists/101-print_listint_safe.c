#include "lists.h"

/**
 * print_listint_safe - a function that prints a listint_t linked list.
 *
 * @head: pointer to the head node
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t a;
	size_t count = 0;
	const listint_t **old = NULL;

	while (head != NULL)
	{
		for (a = 0; a < count; a++)
		{
			if (head == old[a])
			{
				printf("-> [%p] %d\n", (void *) head, head->n);
				free(old);
				return (count);
			}
		}
		count++;
		old = reallocate_memory(old, count, head);
		printf("[%p] %d\n", (void *) head, head->n);
		head = head->next;
	}
	free(old);
	return (count);
}

/**
 * reallocate_memory - new memory address is assigned to pointers in a list
 * @old: the old list to be checked
 * @prop: this is the size of the new list
 * @newnode: a newnode added to the list
 * Return: new list pointer
 */

const listint_t **reallocate_memory(const listint_t **old, size_t prop,
		const listint_t *newnode)
{
	const listint_t **new;
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
