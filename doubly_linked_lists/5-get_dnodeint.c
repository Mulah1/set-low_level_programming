#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t list
 * @head: pointer to the head of the list
 * @index: index of the node to return, starting from 0
 *
 * Return: pointer to the node at the specified index, or NULL if missing
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current_index = 0;
	dlistint_t *current = head;

	while (current != NULL && current_index < index)
	{
		current = current->next;
		current_index++;
	}

	return (current);
}
