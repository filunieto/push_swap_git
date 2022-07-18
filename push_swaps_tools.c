/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaps_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/18 12:31:50 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
** Para cada argumento del input que extraigamos , verificamos que es un numero , convertimos en int,
**  creamos nodo,y vamos apilandolos, primer input ,top del stack A, segundo , al segundo... y verificamos que no esta repetido
*/
void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head)
{
	
}


/* en una lista doble el previos del primer puntero tiene que ir a NULL
*/
void	print_list(t_head_list *head)
{
	int	i;
	t_node	*temp;

	i = 0;
	if (!head->header || !head->tail)
	{
		printf("empty list o no se ha enlazado correctamente al tail\n");
		return ;
	}
	temp = head->header;
	printf("----desde el header hasta el tail----\n");
	while (temp)
	{
		printf("elemento posic %i, valor: %i \n", temp->position, temp->number);
		temp = temp->next;
	}
	temp = head->tail;
	printf("\n----Reves, desde el Tail hasta el header----\n");
	while (temp)
	{
		printf("elemento posic %i, valor: %i \n", temp->position, temp->number);
		temp = temp->prev;
	}
	printf("-----FIN DE IMPRESION----\n");
}