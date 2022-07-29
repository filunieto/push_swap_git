/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/29 19:05:24 by fnieves-         ###   ########.fr       */
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
	printf("el valor res o quiza chunk de size: %i es :%i\n", size, res);
	head->chunk = res;
}

void	algortim_long(t_head_list *head_a, t_head_list *head_b)
{
	chunk_calculator(head_a);
	move_min_b(head_a, head_b);
}

/*
de momento coge los numeros mas peqiuenos en el intervalo [0 - chunk] y los pasa a satck b. Hacer lo mismo con los siguientes chunks
*/
void	move_min_b(t_head_list *head_a, t_head_list *head_b)
{
	//int	ini;
	int	fin;
	//t_node	*current;
	
	fin	= head_a->chunk;
	while (fin--)
	{
		//ini	= head_a->min;
		if (head_a->posit_min > (int) head_a->size_list / 2)
		{
			while (head_a->posit_min++ < (int)head_a->size_list)
				rotate_stack_reverse(head_a);
		}
		else
			while (head_a->posit_min--)
				rotate_stack(head_a);
		push_topushed(head_a, head_b);
		search_min_stack(head_a); //el maximo ya no estara correcto en la posicion o si?
	}
}