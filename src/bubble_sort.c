/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:41:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/26 13:25:14 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	quick_sort(t_head_list *head)
// {
// 	int	*ini;
// 	int	*fin;
// 	int	*pivot;
	
// 	left = head->header;
// 	right = head->tail;
// 	position_pivote = 4; //cambiamos valor variable por lista/2 vemos si impar o par
// 	pivot = left;
// 	while (position_pivote--)
// 	{
// 		pivot = pivot->next;
// 	}
// 	if (left->number >)
	
	
// }

void	bubble_sort(t_head_list *head_c) //recierda actualizar al final head.tail al ultimo elemento
{
	int	swap_counter;
	t_node	*current;

	swap_counter = -1;
	//current = head_c->header;
	printf("Lista cuando entra en bubble\n");
	print_list(head_c);
	while (swap_counter != 0)
	{
		current = head_c->header;
		swap_counter = 0;
		while (--head_c->size_list && current->next) //aqui hay que poner la size
		{
			if (current->number > current->next->number)
			{
				if (current->position == 0)
					swap_first_node(head_c);
				else
					swap_nodes(head_c, current->position);
				swap_counter++;
			}
			current = current->next;
		}
		printf("valores en buuble sort: swap counter %i, --head_csize: %i", swap_counter, (int) head_c->size_list);
	}
}

void 	swap_nodes(t_head_list *head, int position)
{
	t_node	*old_first;
	t_node	*new_first;
	t_node	*third;
	t_node	*before_first;

	if (head->size_list < 2) //esto lo puedo borrar poruq e las listas seran mayores de 2 elementos
		return ;
	old_first = head->header;
	while (position > 0)
	{
		old_first = old_first->next;
		position--;
	}
	new_first = old_first->next; //poner todo en funcion de old first. Seguir aqui
	third = new_first->next;
	before_first = old_first->prev;
	//cambiamos los indices
	// old_first->index = new_first->position ; 
	// new_first->index = old_first->position ; 
	new_first->position = new_first->position - 1; 
	old_first->position = old_first->position + 1; 
	//colocamos los enlaces al old first
	third->prev = old_first; 
	old_first->next = third;
	old_first->prev = new_first;
	//colocamos los enlaces al new first
	new_first->next = old_first;
	new_first->prev = before_first;
	before_first->next = new_first;
	// if (counter == 0) //en el caso de que sea el primer nod a intercambiar
	// {
	// 	//new_first->prev = old_first->prev;
	// 	head->header = new_first;
	// }
	printf("hemos cambiado  2  elementos no al inicio, y los index\n");
}

// void	ss(t_head_list *head) //pasar esta funciona move_stack.c
void 	swap_first_node(t_head_list *head)
{
	t_node	*old_first;
	t_node	*new_first;
	t_node	*third;
	
	// if (head->size_list < 2)
	// 	return ;
	old_first = head->header;
	new_first = old_first->next;
	third = new_first->next;
	//cambiamos los indices
	// old_first->index = new_first->position ; 
	// new_first->index = old_first->position ; 
	new_first->position = new_first->position - 1; 
	old_first->position = old_first->position + 1; 
	//colocamos los enlaces al old first
	third->prev = old_first; 
	old_first->next = third;
	old_first->prev = new_first;
	//colocamos los enlaces al new first
	new_first->next = old_first; 
	new_first->prev = NULL;  //1
	head->header = new_first; //2
 //3
	// if (head->size_list == 2)
	// {
	// 	new_first->next = old_first;
	// 	old_first->next = NULL;
	// 	head->tail = old_first;
	// 	return ;
	// } 
	printf("hemos cambiado primer por segundo elemento\n");
}

