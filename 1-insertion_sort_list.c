#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to the pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	listint_t *current, *prev, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && temp->n < prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->next = temp->next;
			temp->prev = prev->prev;

			temp->next = prev;
			prev->prev = temp;

			print_list(*list);

			prev = temp->prev;

		}

		current = current->next;
	}
}
