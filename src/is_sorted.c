/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:16:50 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/08 09:59:33 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
	gives 0, if not sorted
	1 if no list or is sorted
*/
int	is_sorted(t_head_list *head_a)
{
	t_node	*current;

	current = head_a->header;
	if (!current->next)
	{
		return (1);
	}
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
	List of double movements from the stack which are not used
	by my algorithms. Just in case
*/

void	double_rotate(t_head_list *head_a, t_head_list *head_b)
{
	rotate_stack(head_a);
	rotate_stack(head_b);
	write(1, "rr\n", 3);
}

void	double_rev_rotate(t_head_list *head_a, t_head_list *head_b)
{
	rotate_stack_reverse(head_a);
	rotate_stack_reverse(head_b);
	write(1, "rrr\n", 4);
}

void	double_swap(t_head_list *head_a, t_head_list *head_b)
{
	swap_one_basic(head_a);
	swap_one_basic(head_b);
	write(1, "ss\n", 3);
}
