/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/04 19:20:02 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


///para los primeros chunks , enviar las 2 primeras partes y cuando pertenezca al primer chunk rotarlo en b. Mover en una sola direccion
void	move_min(t_head_list *head_a, t_head_list *head_b, int count_chunk)
{
	int	fin_chunk1;
	int fin_chunk2;
	//int ini;
	fin_chunk1 = head_a->chunk * count_chunk - 1;
	fin_chunk2 = head_a->chunk * (count_chunk + 1) - 1;
	//printf("chnk 1 %i, chunk 2 %i\n", fin_chunk1, fin_chunk2);
	// print_list(head_a);
	// print_list(head_b);
	while (head_a->min < fin_chunk2 && (int)head_a->size_list > 3) //cambiar esto. Rotar todo en un sentido e ir pasando lo del chunk
	{
		if (head_a->header->index < fin_chunk2)
		{
			push_topushed(head_a, head_b);
			if (head_b->min < fin_chunk1)
			{
				rotate_stack(head_b);
			}
		}
		rotate_stack(head_a);
	}
}

void	move_min_finalpart(t_head_list *head_a, t_head_list *head_b)
{
	//print_stack(head_a, head_b);
	//printf("tamano de a %i \n", (int)head_a->size_list);
	while(head_a->size_list > 3)
	{
		if (head_a->posit_min < (int)head_a->size_list / 2) //possicion de minimo en 1a mitad
			while (head_a->header->index != head_a->min)
				rotate_stack(head_a);
		else
			while (head_a->header->index != head_a->min)
				rotate_stack_reverse(head_a);
		push_topushed(head_a, head_b);
	}
	sort_three(head_a);

}

void	move_max_a(t_head_list *head_a, t_head_list *head_b)
{
	while(head_b->size_list)
	{
		if (head_b->posit_max < (int) head_b->size_list / 2)
		{
			while (head_b->header->index != head_b->max)
			{
				rotate_stack(head_b);
			}
		}
		else
		{
			while(head_b->header->index != head_b->max)
			{
				rotate_stack_reverse(head_b);
			}
		}
		push_topushed(head_b, head_a);
		//final_sorting_a(head_a);
	}
}


void	algortim_medium(t_head_list *head_a, t_head_list *head_b)
{
	int	parts;
	int	count_chunk;
	//int	quantity;

	parts = 5;
	head_a->chunk = head_a->size_list / parts; // en chunk tenemos la cantidad en cada parte

	//chunk_calculator(head_a); //lo calculamos solo una vez: para 100: 30
	count_chunk = 1; //tienen qe ser 0
	while (parts > count_chunk)
	{
		move_min(head_a, head_b, count_chunk);
		count_chunk++; //jugar con este parametro para incermentar los limites del chunk a cada paso de entrada en move_mi
	}

	//sort_more_three(head_a, head_b);
	move_min_finalpart(head_a, head_b);

	//algortim_short(head_a, head_b);
	move_max_a(head_a, head_b);
	//print_stack(head_a, head_b);
}