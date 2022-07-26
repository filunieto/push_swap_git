/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:16:50 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/26 12:52:08 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_head_list *head_a)
{
	t_node	*current;
	
	current = head_a->header;
	if (!current->next)
	{
		printf("un solo elemento. Lista ordanda desde el origen\n");
		return (1); //un solo elemento y esta ordenada
	}
	while (current->next)
	{
		if (current->number > current->next->number)
		{
			return (0);
		}
		current = current->next;
	}
	printf("lista ordenada desde el inicio. Salimos\n");
	return (1);
}