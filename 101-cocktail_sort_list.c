#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @node: Pointer to the node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	if (!list || !*list || !node || !node->next)
		return;

	node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - Sorts a list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (!list || !*list)
		return;

	current = *list;

	while (swapped)
	{
		for (swapped = 0; current->next;)
		{
			if (current->next->n < current->n)
			{
				swap_nodes(list, current);
				print_list(*list);
				swapped++;
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		for (swapped = 0; current->prev;)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev);
				print_list(*list);
				swapped++;
			}
			else
				current = current->prev;
		}
	}
}
