/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_limits_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:49:57 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/05 15:28:21 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	search_max_stack(t_head_list *head)
{
	int		posit_max;
	t_node	*current;
	int		max_value;

	current = head->header;
	posit_max = 0;
	max_value = INT_MIN;
	while (current)
	{
		if (current->index > max_value)
			max_value = current->index;
		current = current->next;
	}
	current = head->header;
	while (current)
	{
		if (current->index == max_value)
			break ;
		posit_max++;
		current = current->next;
	}
	head->max = max_value;
	head->posit_max = posit_max;
}

void	search_min_stack(t_head_list *head)
{
	int		posit_min;
	t_node	*current;
	int		min_value;

	current = head->header;
	posit_min = 0;
	min_value = INT_MAX;
	while (current)
	{
		if (current->index < min_value)
			min_value = current->index;
		current = current->next;
	}
	current = head->header;
	while (current)
	{
		if (current->index == min_value)
			break ;
		posit_min++;
		current = current->next;
	}
	head->min = min_value;
	head->posit_min = posit_min;
}

void	update_min_max(t_head_list *head_a, t_head_list *head_b)
{
	search_max_stack(head_a);
	search_max_stack(head_b);
	search_min_stack(head_a);
	search_min_stack(head_b);
}

void	update_min_max_onelist(t_head_list *head_a)
{
	search_max_stack(head_a);
	search_min_stack(head_a);
}
