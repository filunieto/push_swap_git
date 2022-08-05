/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/05 13:29:47 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_calcuchunk(t_head_list *head_a)
{
	int	index;
	int	len;

	//len = stc->len_a;
	len = head_a->size_list;

	index = 0;
	if (head_a->size_list > 1)
	{
		index = ((3 * len) / 40) + (45 / 2);
		while (index % 5 != 0)
			index += 1;
	}
	head_a->chunk = index;
}

void	algo_chunkcreate(t_head_list *head_a, t_head_list *head_b)
{
	int		i;
	int		j;
	t_node	*temp;

	algo_calcuchunk(head_a);
	i = 0;
	j = 1;
	while (head_a->size_list != 0)
	{
		temp = head_a->header;
		if (temp->index < (head_a->chunk * j))
		{
			push_topushed(head_a, head_b);
			if (temp->index < (head_a->chunk * j) - (head_a->chunk / 2))
				rotate_stack(head_b);
			i++;
		}
		else
			rotate_stack(head_a);
		if (i == head_a->chunk * j)
			j++;
	}
}

void	move_max_a(t_head_list *head_a, t_head_list *head_b)
{
	// print_list(head_a);
	// print_list(head_b);
	while(head_b->size_list)
	{
		if (head_b->posit_max < (int) head_b->size_list / 2)
		{
			while (head_b->header->index != head_b->max)
				rotate_stack(head_b);
		}
		else
		{
			while(head_b->header->index != head_b->max)
				rotate_stack_reverse(head_b);
		}
		push_topushed(head_b, head_a);
		// if (head_a->header->index > head_a->header->next->index)
		// 	swap_one(head_a);

	}
}

void	algortim_medium(t_head_list *head_a, t_head_list *head_b)
{
	algo_chunkcreate(head_a, head_b);
	move_max_a(head_a, head_b);
}
