/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/02 15:35:27 by fnieves-         ###   ########.fr       */
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
	//printf("1. valor de chunk: %i\n", head->chunk);
}

void	move_min(t_head_list *head_a, t_head_list *head_b, int count_chunk)
{
	int	fin;
	int ini;
	
	ini	= head_a->chunk * count_chunk; //cada vez que entre el bucle while los limites del chunk tienen que pasar al siguiente intervalo
	if (head_a->chunk * (count_chunk + 1) > (int)head_a->size_list) //cuando crea el intervalo y para el ultimo chunk, no debe rebasar el numero maximo de elementos en la lista
		fin	= head_a->chunk * (count_chunk) + (int)head_a->size_list - 1;
	else	
		fin	= head_a->chunk * (count_chunk + 1) - 1;
	while (head_a->min < fin && head_a->size_list > 3)
	{
		if (head_a->posit_min < (int)head_a->size_list / 2) //possicion de minimo en 1a mitad
		{
			while (head_a->posit_min && head_a->size_list > 4)
			{
				if (head_a->header->index < fin)
				{
					push_topushed(head_a, head_b);
					rotate_stack(head_b);
				}
				rotate_stack(head_a);
			}
		}
		else
		{
			while(head_a->posit_min < (int)head_a->size_list && head_a->size_list > 4)
			{
				if (head_a->header->index < fin)
				{
					push_topushed(head_a, head_b);
					rotate_stack(head_b);
				}
				rotate_stack_reverse(head_a);
			}
		}
		push_topushed(head_a, head_b);
	}
	// printf("3 index minimo (%i) esta en posicion %i: ini = %i y fin : %i\n", head_a->min, head_a->posit_min, ini, fin);
	// printf("tamano de la lista a %i\n",(int) head_a->size_list);
	//print_stack(head_a, head_b);
	//printf("fin = %i y salimos al bucle while de nuevo\n", fin);
}








void	algortim_long(t_head_list *head_a, t_head_list *head_b)
{
	int	count_chunk;

	//print_stack(head_a, head_b);
	chunk_calculator(head_a); //lo calculamos solo una vez: para 100: 30
	count_chunk = 0; //tienen qe ser 0
	while (head_a->size_list > 3)
	{
		//printf("1. valor de chunk: %i\n", head_a->chunk);
		move_min(head_a, head_b, count_chunk);
		//printf("count chunk in while: %i\n", count_chunk);
		count_chunk++; //jugar con este parametro para incermentar los limites del chunk a cada paso de entrada en move_min
	}
	algortim_short(head_a, head_b);
	//print_stack(head_a, head_b);
	//sizeList = head_b->size_list;
	// while (head_b->size_list)
	// {
	// 	move_max(head_b, head_a);
	// }
	//print_stack(head_a, head_b);
}


//usar las funciones de busqueda de top y bottom
void	move_min3(t_head_list *head_a, t_head_list *head_b, int count_chunk) // ha funcionado esta funcion no esta muy optimizada
{
	int	fin;
	int ini;
	int chunk_while;
	
	chunk_while = head_a->chunk;
	ini	= head_a->chunk * count_chunk; //cada vez que entre el bucle while los limites del chunk tienen que pasar al siguiente intervalo
	if (head_a->chunk * (count_chunk + 1) > (int)head_a->size_list) //cuando crea el intervalo y para el ultimo chunk, no debe rebasar el numero maximo de elementos en la lista
		fin	= head_a->chunk * (count_chunk + 1) - (int)head_a->size_list;
	else	
		fin	= head_a->chunk * (count_chunk + 1);
	while (chunk_while-- && head_a->size_list > 3) //va a ejecutarse chunk veces (30)
	{
		// printf("1.primer nodo despues while: index minimo (%i) esta en posicion %i: ini = %i y fin : %i\n", head_a->min, head_a->posit_min, ini, fin);
		// print_node(head_a->header);
		//min = head_a->posit_min; //posicion del minimo
		if (head_a->posit_min > (int)head_a->size_list / 2) //esta en la segunda mitad
		{
			while (head_a->posit_min < (int)head_a->size_list) //mientars posicion de minimo no este el  top, rota la pila
			{
				if (head_a->header->index < fin) //a partir del segudo chunk . todos los indices seran mayores  que el chunk
				{
					// printf("2.1 index minimo (%i) esta en posicion %i: ini = %i y fin : %i\n", head_a->min, head_a->posit_min, ini, fin);
					// print_node(head_a->header);
					push_topushed(head_a, head_b);
				}
				rotate_stack_reverse(head_a);
				head_a->posit_min++;
			}
		}
		else
		{
			while (head_a->posit_min)
			{
				if (head_a->header->index < fin)
				{
					// printf("2.2 index minimo (%i) esta en posicion %i: ini = %i y fin : %i\n", head_a->min, head_a->posit_min, ini, fin);
					// print_node(head_a->header);
					push_topushed(head_a, head_b);

				}
				head_a->posit_min--; //esta orden tarstoca la posicion del minimo 
				rotate_stack(head_a); //aqui se actualiza la posicion del minimo 
			}
		}
		printf("3 index minimo (%i) esta en posicion %i: ini = %i y fin : %i\n", head_a->min, head_a->posit_min, ini, fin);
		printf("tamano de la lista a %i\n",(int) head_a->size_list);
		// print_node(head_a->header);
		push_topushed(head_a, head_b);
		//print_stack(head_a, head_b);
		// search_min_stack(head_a); la lista se actualiza con cada push
	}
}



void	move_min_b2(t_head_list *head_a, t_head_list *head_b) //no funciona muy bien 
{
	int	fin;
	int	position_chunk_top;
	int	position_chunk_bottom;
		
	fin	= head_a->chunk;
	while (fin-- && head_a->size_list > 3)
	{
		position_chunk_top = find_chunk_from_top(head_a);
		position_chunk_bottom = find_chunk_from_bottom(head_a);
		if (position_chunk_bottom > position_chunk_top) //el elemento esta mas cerca del top
			move_top(head_a, position_chunk_top); //va a mover el stack
		else
			move_bottom(head_a, position_chunk_bottom);
		push_topushed(head_a, head_b);
		search_min_stack(head_a); //el maximo ya no estara correcto en la posicion o si?
		search_max_stack(head_a);
	}
}

int	find_chunk_from_top(t_head_list *head_a)
{
	t_node	*current;
	int	fin;
	int	pos_top;
	
	pos_top = 0;
	current = head_a->header;
	if ((int)head_a->size_list > head_a->chunk)
		fin = head_a->chunk;
	else
		fin = (int)head_a->size_list;
	while (current)
	{
		if (current->index < fin)
			return (pos_top);
		current = current->next;
		pos_top++;
	}
	return (pos_top);
}

int	find_chunk_from_bottom(t_head_list *head_a)
{
	t_node	*current;
	int	fin;
	int	pos_bottom;
	
	pos_bottom = head_a->size_list - 1;
	current = head_a->tail;
	if ((int)head_a->size_list > head_a->chunk)
		fin = head_a->chunk;
	else
		fin = head_a->size_list;
	while (current)
	{
		if (current->index < fin)
			return (pos_bottom);
		current = current->prev;
		pos_bottom--;
	}
	return (pos_bottom);
}



void	move_top(t_head_list *head, int position)
{
	while (position--)
	{
		rotate_stack(head);
	}
}

void	move_bottom(t_head_list *head, int position)
{
	while ((int)head->size_list > position++)
	{
		rotate_stack_reverse(head);
	}
}



void	move_max(t_head_list *head_b, t_head_list *head_a) //esta funcion no esta muy optimizada
{
	//int	ini;
	//int	fin;
	//t_node	*current;
	
	//fin	= head_a->chunk;
	while (head_b->size_list)
	{
		//ini	= head_a->min;
		if (head_b->posit_max > (int) head_b->size_list / 2)
		{
			while (head_b->posit_max++ < (int)head_a->size_list)
				rotate_stack_reverse(head_b);
		}
		else
			while (head_b->posit_max--)
				rotate_stack(head_b);
		push_topushed(head_b, head_a);
		search_min_stack(head_b); //el maximo ya no estara correcto en la posicion o si?
		search_max_stack(head_b);
	}
}