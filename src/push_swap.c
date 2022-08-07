/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:44 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/07 14:11:29 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	initialize_list(t_head_list *head, char stack_name)
{
	head->header = NULL;
	head->tail = NULL;
	head->max = 0;
	head->posit_max = 0;
	head->min = 0;
	head->posit_min = 0;
	head->size_list = 0;
	head->stack_name = stack_name;
	head->chunk = 0;
}

void	we_can_finally_sort(t_head_list *head_a, t_head_list *head_b)
{
	if (head_a->size_list <= 5)
		algortim_short(head_a, head_b);
	else
		algortim_medium(head_a, head_b);
	free_all(head_a, head_b);
}

void	print_order(char c, int movement)
{
	if (movement == 1)
		write(1, "s", 1);
	else if (movement == 2)
		write(1, "p", 1);
	else if (movement == 3)
		write(1, "r", 1);
	else if (movement == 4)
		write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
