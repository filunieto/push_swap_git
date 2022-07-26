/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:53:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/25 15:58:03 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//este programa de momento no sirev para bnda. Brar archivo
void	quick_sort(t_head_list *head_a, t_head_list *head_b)
{
	t_node	*ini_pivote;
	t_node	*fin;
	
	ini_pivote = head_a->header;
	fin = head_a->tail;
	print_node(ini_pivote); //Para verificar que todo va bien
	print_node(fin);
	print_list(head_b);
	// while (ini_pivote->next) //mientras ini pivote no llegeue al final de l alista
	// {
		
	// }
	
	
}