#include "sort.h"

void swap_right(listint_t *temp)
{
	if (temp->next)
		temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	if (temp->prev)
		temp->prev->next = temp;
	temp->next->prev = temp;
}

void swap_left(listint_t *temp)
{
	if (temp->prev)
		temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->prev = temp->next;
	temp->next = temp->next->next;
	if (temp->next)
		temp->next->prev = temp;
	temp->prev->next = temp;
}

/**
 * @brief
 *
 * @param list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *head = *list;
	int check = 1;

	if (!head->next)
		return;

	while (check)
	{
		check = 0;

		while (head->next)
		{
			if (head->n > head->next->n)
			{
				swap_right(head->next);
				print_list(*list);
				if (!head->prev)
					*list = head;
				check = 1;
			}
			else
				head = head->next;
		}

		if (check == 0)
			break;

		while (head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_left(head->prev);
				if (!head->prev)
					*list = head;
				print_list(*list);
				check = 1;
			}
			else
				head = head->prev;
		}
	}
}
