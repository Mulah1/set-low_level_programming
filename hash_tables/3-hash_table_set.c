#include "hash_tables.h"

/**
 * hash_table_update_v - Updates the value of
 * an existing key in the hash table.
 * @temp: Pointer to the hash node found.
 * @value: The new value string to duplicate.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_update_v(hash_node_t *temp,
			const char *value)
{
	char *value_dup;

	value_dup = strdup(value);
	if (!value_dup)
		return (0);
	free(temp->value);
	temp->value = value_dup;
	return (1);
}

/**
 * hash_table_add_node - Creates a new node and
 * prepends it to the hash list.
 * @ht: The hash table.
 * @key: The key string.
 * @value: The value string.
 * @index: The calculated array index.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_add_node(hash_table_t *ht, const char *key,
			const char *value, unsigned long int index)
{
	hash_node_t *new_node;
	char *value_dup;

	value_dup = strdup(value);
	if (!value_dup)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(value_dup);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(value_dup);
		free(new_node);
		return (0);
	}
	new_node->value = value_dup;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

/**
 * hash_table_set - Adds or updates an element
 * in the hash table.
 * @ht: The hash table to add or update.
 * @key: The key. Cannot be an empty string.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key,
		const char *value)
{
	unsigned long int index;
	hash_node_t *temp;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (hash_table_update_v(temp, value));
		temp = temp->next;
	}

	return (hash_table_add_node(ht, key, value, index));
}
