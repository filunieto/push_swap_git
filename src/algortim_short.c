/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/28 21:22:45 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algortim_short(t_head_list *head_a, t_head_list *head_b)
{
	int	i;


	i = head_a->size_list;
	if (head_a->size_list == 2)
	{
		printf("2 elementos en algoritmo short. Hacemo algo y pafuera\n");
		return ;
	}

	if (head_a->size_list > 3)
	{
		while (i > 3)
		{
			push_topushed(head_a, head_b);
			i--;
		}
	}
	//falta ordenar 2, 4 y 5 elementos
	sort_three(head_a);
}


void	sort_three(t_head_list *head_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = head_a->header->number;
	middle  = head_a->header->next->number;
	bottom = head_a->header->next->next->number;
	if (top > middle && top < bottom && middle < bottom)
		swap_one(head_a);
	else if (top > middle && top > bottom && middle > bottom)
	{
		swap_one(head_a);
		rotate_stack_reverse(head_a);
	}
	else if (top > middle && top > bottom && middle < bottom)
		rotate_stack(head_a);
	else if (top < middle && top < bottom && middle > bottom)
	{
		swap_one(head_a);
		rotate_stack(head_a);
	}
	else // if (top < middle && top < bottom && middle > bottom) . borrar si no da problemas
		rotate_stack_reverse(head_a);
}
