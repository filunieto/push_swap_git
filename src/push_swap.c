/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:44 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/25 19:00:44 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	initialize_list(t_head_list *head, char stack_name)
{
	head->header = NULL;
	head->tail = NULL;
	head->max = 0;
	head->min = 0;
	head->size_list = 0;
	head->stack_name = stack_name;
}


void	error_and_free_all(t_head_list *head_a, t_head_list *head_b) //hay qe borrar el array de char depsues de split
{
	/* borar listas y free el char ** de malloc  e imprimir el mensaje de error*/
	//int	i;
	delete_list(head_a);
	delete_list(head_b);
	//i = 0;
	// while (array_words[i])
	// {
	// 	printf("ha borrado las listas y va a borrar el array :%i, %s\n", i, array_words[i]);
	// }
	write(1, "Salida de Funcion error_and_free_all\n", 38); //modificar esto
	//exit (2);
}

//void	push_swap.c()
