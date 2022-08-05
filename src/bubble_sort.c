/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:41:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/05 15:34:18 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bubble_sort(t_head_list *head_c)
{
	int			node_ctr;
	int			ctr;
	int			node_data_copy;
	t_node		*current_node;

	node_ctr = head_c->size_list - 1;
	while (node_ctr--)
	{
		current_node = head_c->header;
		ctr = 0;
		while (ctr++ <= node_ctr)
		{
			if (current_node->number > current_node->next->number)
			{
				node_data_copy = current_node->number;
				current_node->number = current_node->next->number;
				current_node->next->number = node_data_copy;
			}
			current_node = current_node->next;
		}
	}
}

void	indexing_list(t_head_list *head_a, t_head_list *sorting_copy)
{
	t_node	*current_a;
	t_node	*current_c;

	bubble_sort(sorting_copy);
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
	delete_list(sorting_copy);
}
