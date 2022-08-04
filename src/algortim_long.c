/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/04 17:26:06 by fnieves-         ###   ########.fr       */
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


void	move_min2(t_head_list *head_a, t_head_list *head_b, int count_chunk)
{
	int	fin;
	//int ini;
	
	//ini	= head_a->chunk * count_chunk; //cada vez que entre el bucle while los limites del chunk tienen que pasar al siguiente intervalo
	if (head_a->chunk * (count_chunk + 1) > (int)head_a->size_list) //cuando crea el intervalo y para el ultimo chunk, no debe rebasar el numero maximo de elementos en la lista
		fin	= head_a->chunk * (count_chunk) + (int)head_a->size_list - 4;
	else	
		fin	= head_a->chunk * (count_chunk + 1) - 1;
	while (head_a->min < fin && head_a->size_list > 3)
	{
		if (head_a->posit_min < (int)head_a->size_list / 2) //possicion de minimo en 1a mitad
		{
			while (head_a->posit_min)
			{
				if (head_a->header->index < fin)  //&& (head_a->header->index != head_a->max || head_a->header->index != head_a->max - 1)
				{
					push_topushed(head_a, head_b);
					//rotate_stack(head_b);
				}
				rotate_stack(head_a);
			}
		}
		else
		{
			while(head_a->posit_min < (int)head_a->size_list)
			{
				if (head_a->header->index < fin)
				{
					push_topushed(head_a, head_b);
					//rotate_stack(head_b);
				}
				rotate_stack_reverse(head_a);
			}
		}
		push_topushed(head_a, head_b);
		rotate_stack(head_b);
	}
}

// void	move_max_a(t_head_list *head_a, t_head_list *head_b)
// {
// 	while(head_b->size_list)
// 	{
// 		if (head_b->posit_max < (int) head_b->size_list / 2)
// 		{
// 			while (head_b->header->index != head_b->max)
// 			{
// 				rotate_stack(head_b);
// 			}
// 		}
// 		else
// 		{
// 			while(head_b->header->index != head_b->max)
// 			{
// 				rotate_stack_reverse(head_b);
// 			}
// 		}
// 		push_topushed(head_b, head_a);
// 		//final_sorting_a(head_a);
// 	}
// }


// void 	final_sorting_a(t_head_list *head_a)
// {
// 	if (head_a->tail->index != head_a->max)
// }


void	algortim_long(t_head_list *head_a, t_head_list *head_b)
{
	int	count_chunk;

	chunk_calculator(head_a); //lo calculamos solo una vez: para 100: 30
	count_chunk = 0; //tienen qe ser 0
	while (head_a->size_list > 3)
	{
		move_min2(head_a, head_b, count_chunk);
		count_chunk++; //jugar con este parametro para incermentar los limites del chunk a cada paso de entrada en move_min
	}
	algortim_short(head_a, head_b);
	//move_max_a(head_a, head_b);

}
