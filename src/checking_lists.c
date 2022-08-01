/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:41:39 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/01 11:47:26 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* funcion de chequeo de listas , impresion de listas y nodos
*/

void	print_list(t_head_list *head)
{
	int	i;
	t_node	*temp;

	i = 0;
	if (!head->header || !head->tail)
	{
		printf("Lista %c esta vacia o tail vacio. Tenemos %i elementos\n", head->stack_name, (int) head->size_list);
		return ;
	}
	temp = head->header;
	printf("-------Informacion de La lista %c----------\n", head->stack_name);
	printf("elementos de la lista: %i, \n", (int)head->size_list);
	printf("En valores indexados: \nValor de max: %i, Posicion de  max = %i.\n Valor de min: %i, Posicion de min = %i \n", head->max, head->posit_max, head->min, head->posit_min);
	//printf("Imprsion de nodos desde el header hasta el tail\n");
	while (temp)
	{
		printf("elemento %i, valor= %i, index = %i \n",temp->position, temp->number, temp->index);
		temp = temp->next;
	}
	// temp = head->tail;
	// printf("\n----Reves, desde el Tail hasta el header----\n");
	// while (temp)
	// {
	// 	printf("elemento %i, valor= %i \n",temp->position, temp->number);
	// 	temp = temp->prev;
	// }
	printf("-------FIN DE IMPRESION de lista-------\n");
}

void	print_node(t_node *node_tocheck)
{
	printf("-------Informacion un unico nodo----------\n");
	if (!node_tocheck->next)
		printf("next  no apuntan a nada. Ultimo nodo\n");
	else if (!node_tocheck->prev)
		printf("previous no apuntan a anda. Primer nodo\n");
	else
		printf("next y previous apuntan a algo. El nodo esta enlazado\n");
	printf("valores inicial: %i , index (%i) y posicion: %i\n", node_tocheck->number, node_tocheck->index , node_tocheck->position);
	printf("-------FIN DE IMPRESION de unico nodo-------\n");
}

void	print_stack(t_head_list *head_a, t_head_list *head_b)
{
	t_node *i;
	t_node *j;
	int		pad_a;
	int		pad_b;

	pad_a = 0;
	pad_b = 0;
	if (head_a->size_list > head_b->size_list)
		pad_b = head_a->size_list- head_b->size_list;
	if (head_a->size_list< head_b->size_list)
		pad_a = head_b->size_list- head_a->size_list;
	i = head_a->header;
	j = head_b->header;
	printf("-------------------------------\n");
	printf("stack a:\tstack b:\n");
	if (!pad_a && !pad_b)
	{
		while (i != head_a->tail && j != head_b->tail)
		{
			printf("\t%i\t%i\n", i->number, j->number);
			i = i->next;
			j = j->next;
		}
		printf("\t%i\t%i\n", i->number, j->number);
	}
	if (pad_a)
	{
		while (j != head_b->tail)
		{
			if (pad_a)
			{
				printf("\t\t%i\n", j->number);
				pad_a--;
				j = j->next;
			}
			else
			{
				printf("\t%i\t%i\n", i->number, j->number);
				i = i->next;
				j = j->next;
			}
		}
		if (!pad_a)
			printf("\t%i", i->number);
		printf("\t%i\n", j->number);
	}
	if (pad_b)
		{
		while (i != head_a->tail)
		{
			if (pad_b)
			{
				printf("\t%i\n", i->number);
				pad_b--;
				i = i->next;
			}
			else
			{
				printf("\t%i\t%i\n", i->number, j->number);
				i = i->next;
				j = j->next;
			}
		}
		printf("\t%i", i->number);
		if (!pad_b)
			printf("\t%i", j->number);
		printf("\n");
	}
	printf("-------------------------------\n");
}

// //mi fncion copio arriba la de hellen
void	print_stack2(t_head_list *head_a, t_head_list *head_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	// int	numero_elementos_a;
	// int	numero_elementos_b;
	// int	pad;
	//int	espacios;

	// pad = head_a->size_list - head_b->size_list;
	// numero_elementos_a = head_a->size_list;
	// numero_elementos_b = head_b->size_list;
	temp_a = head_a->tail;
	temp_b = head_b->tail;
	// if (numero_elementos_a > numero_elementos_b)
	// {
	// 	espacios = numero_elementos_a - numero_elementos_b;
	// 	while (espacios--)
	// 		printf("\t  \t \n");
	// }
	printf("     -------a   ------b\n");
	while (temp_a || temp_b)
	{
		if (temp_a && temp_b )
		{
			printf("\t %i \t %i\n", temp_a->number, temp_b->number);
			temp_a = temp_a->prev;
			temp_b = temp_b->prev;		

		}
		else if (temp_a && !temp_b)
		{
			printf("\t %i \t \n", temp_a->number);
			temp_a = temp_a->prev;
		}
		else if (!temp_a && temp_b)
		{
			printf("\t \t %i\n", temp_b->number);
			temp_b = temp_b->next;	
		}
	}
}