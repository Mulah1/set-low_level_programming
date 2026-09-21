#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: Pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *next;

	while (head != NULL && *head != NULL)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
	}

	return (previous);
}
