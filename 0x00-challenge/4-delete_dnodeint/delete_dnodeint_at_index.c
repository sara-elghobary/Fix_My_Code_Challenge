#include "lists.h"
#include <stdlib.h>
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count;

	if (*head == NULL)
	{
		return (-1);
	}

	current = *head;
	for (count =  0; current != NULL && count < index; count++)
	{
		current = current->next;
	}

	if (current == NULL)
	{
		return (-1);
	}

	if (count ==  0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}
	else
	{
		current->prev->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}
	}

	free(current);
	return (1);
}
