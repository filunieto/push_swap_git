/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:58:59 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/21 18:42:42 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_one(t_head_list *head) //pasar esta funciona move_stack.c
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
	new_first->prev = NULL;  //1
	head->header = new_first; //2
	old_first->prev = new_first; //3
	printf("s%c\n", head->stack_name); //estoy hay que buscarse como hacerlo mejor
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

void	push_topushed(t_head_list *head_pusher, t_head_list *head_pushed)  //pasar esta funciona move_stack.c
{
	t_node	*pusher;
	t_node	*newfirst_pusher; //solo a usar si hay mas de un elemento en la lista del spusher

	if (head_pusher->size_list == 0)
	{
		printf("Empuja la lista %c pero esta vacia. No action\n", head_pusher->stack_name); //esto hayqque borrarlo
		return ;
	}
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
	printf("p%c\n", head_pushed->stack_name);
}

void	rotate_stack(t_head_list *head)
{
	t_node	*new_last;
	t_node	*new_first;
	
	if (head->size_list < 2)
	{
		printf("lista de menos de 2 elementos. No hacemos nada");
		return ;
	}
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
	printf("r%c (rotate)\n", head->stack_name);
}

void	rotate_stack_reverse(t_head_list *head)
{
	t_node	*new_second;
	t_node	*new_first;
	
	if (head->size_list < 2)
	{
		printf("lista de menos de 2 elementos. No hacemos nada");
		return ;
	}
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
	printf("r%c (rotate)\n", head->stack_name);
}
