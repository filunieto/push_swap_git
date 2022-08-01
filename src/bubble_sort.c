/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:41:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/31 18:41:52 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bubble_sort(t_head_list *head_c)
{
	int node_ctr;
	int ctr;
	int	node_data_copy;
	t_node	*currentNode;
	
	node_ctr = head_c->size_list - 1;
	while (node_ctr--)
	{
		currentNode = head_c->header;
		ctr	= 0;
		while (ctr++ <= node_ctr)
		{
			if (currentNode->number > currentNode->next->number)
			{
				node_data_copy = currentNode->number;
				currentNode->number = currentNode->next->number;
				currentNode->next->number = node_data_copy;
			}
			currentNode = currentNode->next;
		}
	}
}

void	indexing_list(t_head_list *head_a, t_head_list *sorting_copy)
{
	t_node	*current_a;
	t_node	*current_c;
	
	current_a = head_a->header;
	while (current_a)
	{
		current_c = sorting_copy->header;
		while (current_c && current_a->number != current_c->number)
		{
			current_c = current_c->next;
		}
		if (current_a->number == current_c->number)
		{
			current_a->index = current_c->position;
		}
		current_a = current_a->next;
	}
	search_max_stack(head_a);
	search_min_stack(head_a);
	// hacer un free a la lista sorting_copy( hacerlo solo esta vez)
	
}

void	convert_index_bin(t_head_list *head_a) //esta funcion no es necesaria
{
	t_node	*current;
	print_list(head_a);
	current = head_a->header;
	while (current)
	{
		current->index = num_bin(current->index);
		current = current->next;
	}
	print_list(head_a);

}

int	num_bin(int num)
{
	int bin;
	int	k;

	bin = 0;
	k = 1;
	while(num)
	{
		bin = bin + (num % 2) * k;
		k = k * 10;
		num = num /2;
	}
	return (bin);
}
