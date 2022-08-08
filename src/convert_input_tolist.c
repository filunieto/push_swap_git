/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input_tolist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/08 19:31:44 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/* 
	Para cada argumento del input que extraigamos ,
	verificamos que es un numero , convertimos en int,
	creamos nodo,y vamos apilandolos, primer input ,
	top del stack A, segundo , al segundo... y verificamos que no esta repetido
*/

void	tostack_a(t_head_list *head, int value, size_t posit)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->number = value;
	new_node->position = posit;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = posit;
	if (!head->header)
	{
		head->max = new_node->number;
		head->min = new_node->number;
	}
	if (head->max < new_node->number)
		head->max = new_node->number;
	if (head->min > new_node->number)
		head->min = new_node->number;
	add_node_end(head, new_node);
}

/*
	si encuentra un signo menos aislado
	lo interpreta como un 0. corregir
*/
void	extract_inpt(t_head_list *head, char **array_w, size_t *posit)
{
	int	i;
	int	j;

	i = 0;
	if (!array_w[i])
		free_array_list(array_w, head);
	while (array_w[i])
	{
		j = 0;
		if ('-' == array_w[i][j] && ft_isdigit(array_w[i][j + 1]))
			j++;
		while (array_w[i][j])
		{
			if (!ft_isdigit(array_w[i][j]))
				free_chararray_list(array_w, head);
			j++;
		}
		tostack_a(head, ft_atoi((const char *)array_w[i]), (int) *posit);
		free(array_w[i]);
		*posit = *posit + 1;
		i++;
	}
	free(array_w);
}

/*
	position_node : Node position which is creating.
	En el bucle while: Cada argumento 
	(uno o varios si est'an entre comillas),
	se van posicionando en el array de strings
	siempre nullterminated
*/

void	split_input(int argc, char **argv1, t_head_list *head, char **array_w)
{
	size_t	position_node;
	int		i;

	position_node = 0;
	i = 0;
	while (i < argc)
	{
		array_w = ft_split(argv1[i], ' ');
		extract_inpt(head, array_w, &position_node);
		i++;
	}
}

int	check_doubles(t_head_list *head)
{
	t_node	*reference;
	t_node	*current;

	reference = head->header;
	while (reference)
	{
		current = reference->next;
		while (current)
		{
			if (reference->number == current->number)
			{
				return (1);
			}
			current = current->next;
		}
		reference = reference->next;
	}
	return (0);
}
