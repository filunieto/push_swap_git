/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_in_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:33:35 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/02 14:53:38 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//todas las fnciones que tegan que ver con listas 

void	add_node_begginig(t_head_list *head, t_node *new_node) //pasar esta funcion a operations_in_list.c
{
	t_node	*old_first;

	head->size_list++;
	if (!head->header)
	{
		head->header = new_node;
		head->tail = new_node;
		return ;
	}
	increas_posit_nodes(head);
	old_first = head->header;
	old_first->prev = new_node;
	new_node->next = old_first;
	head->header = new_node;
}

void add_node_end(t_head_list *head, t_node *new_node) //pasar esta funcion a operations_in_list.c
{
	head->size_list++;
	if (!head->header)
	{
		head->header = new_node;
		head->tail = new_node;
		return ;
	}
	new_node->prev = head->tail;
	head->tail->next = new_node;
	head->tail = new_node;
}

void	increas_posit_nodes(t_head_list *head) //anadir el incremento de posicion max y min
{
	t_node	*current;
	
	if (!head->header)
		return ;
	current = head->header;
	while (current)
	{
		current->position++;
		current = current->next;
	}
	head->posit_min++;
	head->posit_max++;
}

void	decreas_posit_nodes(t_head_list *head) //anadir el incremento de posicion max y min
{
	t_node	*current;
	
	if (!head->header)
		return ;
	current = head->header;
	while (current)
	{
		current->position--;
		current = current->next;
	}
	head->posit_min--;
	head->posit_max--;
}

void	delete_list(t_head_list *head)
{
	t_node	*node_todelete;
	t_node	*current;

	if (!head->header)
		return ;
	current = head->header;
	while (current)
	{
		node_todelete = current;
		current = current->next;
		node_todelete->next = NULL;
		node_todelete->prev = NULL;
		free(node_todelete);
	}
	head->header = NULL;
	head->tail = NULL;
}
