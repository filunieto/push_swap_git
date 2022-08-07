/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:16:50 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/07 15:45:15 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
	gives 0, if not sorted
	1 if no list or is sorted
*/
int	is_sorted(t_head_list *head_a)
{
	t_node	*current;

	current = head_a->header;
	if (!current->next)
	{
		return (1);
	}
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}
