#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table with the specified size.
 * @size: The size of the array in the hash table.
 *
 * Return: A pointer to the newly created hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	unsigned long int i = 0;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	for (; i < size; i++)
		hash_table->array[i] = NULL;

	hash_table->size = size;

	return (hash_table);
}
