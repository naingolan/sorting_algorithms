#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: address of the list's head
 * @current: pointer to the node to be swapped with the one before it
 */
void swap_nodes(listint_t **list, listint_t *current)
{
	listint_t *node1, *node2;

	node1 = (current->prev)->prev;
	node2 = current->next;
	current->next = current->prev;
	(current->prev)->prev = current;
	current->prev = node1;
	if (node1 == NULL)
		*list = current;
	else
		node1->next = current;
	(current->next)->next = node2;
	if (node2)
		node2->prev = current->next;
}

/**
 * cocktail_sort_list -  sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * The nodes are swapped instead of swapping only the integers n
 * @list: address of head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *first, *end;
	int swapped = 1;

	if ((!list || !(*list)) || !(*list)->next)
		return;
	first = (*list)->next;
	while (swapped)
	{
		swapped = 0;
		while (first)
		{
			if ((first->prev) && first->n < (first->prev)->n)
			{
				swap_nodes(list, first);
				swapped = 1;
				print_list(*list);
			}
			end = first;
			first = first->next;
		}
		end = end->prev;
		if (swapped == 0)
			break;
		swapped = 0;
		while (end)
		{
			if ((end->prev) && end->n < (end->prev)->n)
			{
				swap_nodes(list, end);
				swapped = 1;
				print_list(*list);
				end = end->next;
			}
			first = end;
			end = end->prev;
		}
		first = first->next;
		if (swapped == 0)
			break;
	}
}
