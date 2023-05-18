#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to retrieve.
 * Return: Pointer to the nth node, or NULL if it does not exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int value = 0;

	while (head != NULL)
	{
		if (value == index)
			return (head);
		head = head->next;
		value++;
	}

	return (NULL);
}
