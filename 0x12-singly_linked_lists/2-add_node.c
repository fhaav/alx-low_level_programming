#include "lists.h"

/**
 * add_node - a function that adds a new node
 * at the beginning of a list_t list.
 *
 * @head: double pointer to list_t
 * @str: value to insert into element.
 *
 * Return: the address of the new element, or NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *current;
	unsigned int len = 0;

	while (str[len])
		len++;

	current = malloc(sizeof(list_t));
	if (!current)
		return (NULL);

	current->str = strdup(str);
	current->len = len;
	current->next = (*head);
	(*head) = current;

	return (*head);
}
