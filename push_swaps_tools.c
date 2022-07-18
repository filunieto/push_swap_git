/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaps_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/18 20:43:53 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
** Para cada argumento del input que extraigamos , verificamos que es un numero , convertimos en int,
**  creamos nodo,y vamos apilandolos, primer input ,top del stack A, segundo , al segundo... y verificamos que no esta repetido
*/

void	print_array(char **array_words , int *posicion)
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
		//printf("palabra No %i : %s. Numero entero : %i\n", i, array_words[i], ft_atoi((const char *)array_words[i]));
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
			//printf("digito ok! sigue\n");
			j++;
		}
		printf("palabra No %i : %s. Numero entero : %i ira en la posicion del stack: %iª \n",
		 i, array_words[i], ft_atoi((const char *)array_words[i]), *posicion);
		// ft_create_node(). Usamos los parametros de arriba , numero entero y posicion del stack
		*posicion = *posicion + 1;
		i++;
	}
}

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head, char **array_words)
{
	size_t position_node;
	int i;

	position_node = 0;
	int i = 0;
	while (i < argc)
	{
		array_words = ft_split(argv1[i], ' ');
		printf("--- imprimirmos el arc: %i ----\n", i);
		print_array(array_words, &position_node);
		i++;
	}
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