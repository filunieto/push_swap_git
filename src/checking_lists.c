/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:41:39 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/26 11:57:56 by fnieves-         ###   ########.fr       */
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
	printf("elementos de la lista: %i, max = %i y min = %i \n", (int)head->size_list, head->max, head->min);
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
	printf("valores de nodo: %i y posicion: %i\n", node_tocheck->number, node_tocheck->position);
	printf("-------FIN DE IMPRESION de unico nodo-------\n");
}