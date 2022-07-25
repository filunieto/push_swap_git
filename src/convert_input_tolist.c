/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input_tolist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/22 12:00:55 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/* 
** Para cada argumento del input que extraigamos , verificamos que es un numero , convertimos en int,
**  creamos nodo,y vamos apilandolos, primer input ,top del stack A, segundo , al segundo... y verificamos que no esta repetido
*/

void	ft_create_node_addend(t_head_list *head, int value_node, size_t position) //cambiar el nombre a la funcion from_inputnode_tostack_a
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->number = value_node;
	new_node->position = position;
	new_node->next = NULL;
	new_node->prev = NULL;
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

//en esta funcion hay que meter 3 frees al menos
void	print_array(t_head_list *head, char **array_words , size_t *position) //cambiar el nombre extract_input_tonode
{
	int	i;
	int	j;

	i = 0;
	if (!array_words[i])
	{
 		printf("array de 0. Error \n"); //si metemos entre comillas ningun argumento
		exit (1) ;
	}
	while (array_words[i])
	{
		j = 0;
		if ('-' == array_words[i][j])
			j++;
		while (array_words[i][j])
		{
			if (!ft_isdigit(array_words[i][j]))
			{
				printf("ha encontardo un NO digito. Error\n");
				exit (2);
			}
			j++;
		}
		ft_create_node_addend(head, ft_atoi((const char *)array_words[i]), (int) *position);
		//free(array_words[i]); //atencion: creo que no es suficiente con este free para no tener probelmas luego. ivestigar como hacer free
		*position = *position + 1;
		i++;
	}
}

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head, char **array_words) //cambiar nombre a splitting_input
{
	size_t position_node;
	int i;

	position_node = 0;
	i = 0;
	while (i < argc)
	{
		array_words = ft_split(argv1[i], ' ');
		print_array(head, array_words, &position_node);
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