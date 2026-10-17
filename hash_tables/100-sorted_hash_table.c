#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_insert_sorted - Inserts a node into the sorted linked list.
 * @ht: The sorted hash table.
 * @new_node: The new node to insert.
 */
void shash_table_insert_sorted(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *temp;

	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return;
	}

	temp = ht->shead;
	while (temp && strcmp(temp->key, new_node->key) < 0)
		temp = temp->snext;

	if (!temp)
	{
		ht->stail->snext = new_node;
		new_node->sprev = ht->stail;
		new_node->snext = NULL;
		ht->stail = new_node;
	}
	else if (temp == ht->shead)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		new_node->snext = temp;
		new_node->sprev = temp->sprev;
		temp->sprev->snext = new_node;
		temp->sprev = new_node;
	}
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key. Cannot be empty.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *temp;
	char *value_dup;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	value_dup = strdup(value);
	if (!value_dup)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value_dup;
			return (1);
		}
		temp = temp->next;
	}

	new_node = malloc(sizeof(shash_node_t));
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

	shash_table_insert_sorted(ht, new_node);
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key to look for.
 *
 * Return: The value, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (!ht || !key || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *comma = "";

	if (!ht)
		return;

	printf("{");
	temp = ht->shead;
	while (temp)
	{
		printf("%s'%s': '%s'", comma, temp->key, temp->value);
		comma = ", ";
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *comma = "";

	if (!ht)
		return;

	printf("{");
	temp = ht->stail;
	while (temp)
	{
		printf("%s'%s': '%s'", comma, temp->key, temp->value);
		comma = ", ";
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *temp, *next;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp)
		{
			next = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next;
		}
	}
	free(ht->array);
	free(ht);
}
