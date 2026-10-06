#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data in a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: sum of the integer values in the list, or 0 for an empty list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
