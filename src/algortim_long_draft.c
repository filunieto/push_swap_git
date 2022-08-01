/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/01 12:50:52 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	chunk_calculator(t_head_list *head)
{
	int	res;
	int	size;

	size = head->size_list;
	res = 0;
	if (size > 1)
	{
		res = ((3 * size) / 40) + (45 / 2);
		while (res % 5 != 0)
			res += 1;
	}
	head->chunk = res;
}

void	algortim_long(t_head_list *head_a, t_head_list *head_b)
{
	int	sizeList;

	sizeList = 100;
	//print_stack(head_a, head_b);
	chunk_calculator(head_a);
	//print_list(head_a);
	// print_list(head_b);
	while (sizeList > 3)
	{
		move_min_b(head_a, head_b);
		sizeList = head_a->size_list;
	}
	
	//sort_three(head_a);
	//print_stack(head_a, head_b);
	//sizeList = head_b->size_list;
	// while (head_b->size_list)
	// {
	// 	move_max(head_b, head_a);
	// }
	//print_stack(head_a, head_b);
}


void	move_min_b(t_head_list *head_a, t_head_list *head_b)
{
	int	fin;
	
	fin	= head_a->chunk;
	while (fin-- && head_a->size_list > 3) //hasta que ocurra chunk veces (20 veces) o queden 3 elementos en a
	{
		if (head_a->posit_min > (int) head_a->size_list / 2)
		{
			
		}
	}
}
