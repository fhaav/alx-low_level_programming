#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table
 *
 * Return: void
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur;
	hash_node_t *head;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		while (head)
		{
			cur = head;
			head = head->next;
			free(cur->key);
			free(cur->value);
			free(cur);
		}
	}

	free(ht->array);
	free(ht);
}
