#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key
 * @ht: A pointer to hash_table_t
 * @key: The key to search for
 *
 * Return: The value associated with the element, or
 * NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *cur;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[i];

	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
			return (cur->value);

		cur = cur->next;
	}

	return (NULL);
}
