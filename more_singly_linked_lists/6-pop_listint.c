#include "lists.h"

/**
 * pop_listint - deletes the head node and returns its data
 * @head: pointer to pointer to the head of the list
 *
 * Return: data (n) of the head node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = temp->next;
	free(temp);

	return (n);
}
