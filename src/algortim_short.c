/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_short.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/04 20:04:14 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algortim_short(t_head_list *head_a, t_head_list *head_b)
{
	if (head_a->size_list == 2)
		swap_one(head_a);
	else if (head_a->size_list == 3)
		sort_three(head_a);
	else if (head_a->size_list > 3)
		sort_more_three(head_a, head_b);
	//print_stack(head_a, head_b);
}

void	sort_three(t_head_list *head_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = head_a->header->number;
	middle  = head_a->header->next->number;
	bottom = head_a->header->next->next->number;
	//printf("top %i, middel, %i, bottom %i\n", top, middle, bottom);
	if (top > middle && top < bottom && middle < bottom) // caso 1
		swap_one(head_a);
	else if (top > middle && top > bottom && middle > bottom) //caso 2
	{
		swap_one(head_a);
		rotate_stack_reverse(head_a);
	}
	else if (top > middle && top > bottom && middle < bottom) //caso 3
		rotate_stack(head_a);
	else if (top < middle && top < bottom && middle > bottom) //caso 4
	{
		swap_one(head_a);
		rotate_stack(head_a);
	}
	else if (top < middle && top > bottom && middle > bottom) // if (top < middle && top < bottom && middle > bottom) . borrar si no da problemas
		rotate_stack_reverse(head_a);
}

 /* 
** Pasamos a la pila b el maximo de a, hasta que nos queden 3 elementos en a
** una vez ordenemos a, vamos pasando los maximos y rotando
** igual podemos mejorar la eficiencia si calculamos. no parece que mejore
 */
void	sort_more_three(t_head_list *head_a, t_head_list *head_b)
{
	int	i;
	int	j;
	
	j = 0;
	i = (int)head_a->size_list;
	while (i-- > 3)
	{
		if (head_a->posit_max > (int) head_a->size_list / 2)
			while (head_a->header->index != head_a->max)
				rotate_stack_reverse(head_a);
		else
			while (head_a->header->index != head_a->max)
				rotate_stack(head_a);
		push_topushed(head_a, head_b);
		j++;
	}
	sort_three(head_a);
	while (j--)
	{
		push_topushed(head_b, head_a);
		rotate_stack(head_a);
	}
}