/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_basic_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:58:59 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/07 19:01:08 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_one(t_head_list *head)
{
	swap_one_basic(head);
	print_order(head->stack_name, 1);
	search_max_stack(head);
	search_min_stack(head);
}

void	swap_one_basic(t_head_list *head)
{
	t_node	*old_first;
	t_node	*new_first;
	t_node	*third;

	if (head->size_list < 2)
		return ;
	old_first = head->header;
	new_first = old_first->next;
	old_first->position = 1;
	new_first->position = 0;
	new_first->prev = NULL;
	head->header = new_first;
	old_first->prev = new_first;
	if (head->size_list == 2)
	{
		new_first->next = old_first;
		old_first->next = NULL;
		head->tail = old_first;
		return ;
	}
	third = new_first->next;
	third->prev = old_first;
	old_first->next = third;
	new_first->next = old_first;
}

void	push_topushed(t_head_list *head_pusher, t_head_list *head_pushed)
{
	t_node	*pusher;
	t_node	*newfirst_pusher;

	if (head_pusher->size_list == 0)
		return ;
	pusher = head_pusher->header;
	pusher->position = 0;
	if (head_pusher->size_list == 1)
		initialize_list(head_pusher, head_pusher->stack_name);
	else
	{
		newfirst_pusher = pusher->next;
		newfirst_pusher->prev = NULL;
		pusher->next = NULL;
		head_pusher->header = newfirst_pusher;
		head_pusher->size_list--;
		decreas_posit_nodes(head_pusher);
	}
	add_node_begginig(head_pushed, pusher);
	update_min_max(head_pushed, head_pusher);
	print_order(head_pushed->stack_name, 2);
}

void	rotate_stack(t_head_list *head)
{
	t_node	*new_last;
	t_node	*new_first;

	if (head->size_list < 2)
		return ;
	new_last = head->header;
	new_first = new_last->next;
	new_first->prev = NULL;
	new_last->next = NULL;
	new_last->prev = head->tail;
	head->tail->next = new_last;
	head->header = new_first;
	head->tail = new_last;
	decreas_posit_nodes(head);
	new_last->position = (int)head->size_list - 1;
	print_order(head->stack_name, 3);
	update_min_max_onelist(head);
}

void	rotate_stack_reverse(t_head_list *head)
{
	t_node	*new_second;
	t_node	*new_first;

	if (head->size_list < 2)
		return ;
	new_second = head->header;
	new_first = head->tail;
	head->tail = head->tail->prev;
	new_first->prev = NULL;
	new_second->prev = new_first;
	new_first->next = new_second;
	head->tail->next = NULL;
	head->header = new_first;
	increas_posit_nodes(head);
	new_first->position = 0;
	print_order(head->stack_name, 4);
	update_min_max_onelist(head);
}
