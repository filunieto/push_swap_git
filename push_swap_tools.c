/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/21 11:48:33 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
** Para cada argumento del input que extraigamos , verificamos que es un numero , convertimos en int,
**  creamos nodo,y vamos apilandolos, primer input ,top del stack A, segundo , al segundo... y verificamos que no esta repetido
*/

void	ft_create_node_addend(t_head_list *head, int value_node, size_t position)
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

void	print_array(t_head_list *head, char **array_words , size_t *position)
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
		//free(array_words[i]); //atencion: creo que no es suficiente con este free para no tener probelmas luego. estoy hay que meterlo cada vez que hay un error
		*position = *position + 1;
		i++;
	}
}

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head, char **array_words)
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

/* funcion de chequeo
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
		printf("elemento %i, valor= %i \n",temp->position, temp->number);
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
	if (!node_tocheck->next && !node_tocheck->prev)
		printf("next y previous no apuntan a anda. Nodo en el vacio\n");
	else
		printf("next y previous apuntan a algo. El nodo esta enlazado\n");
	printf("valores de nodo: %i y posicion: %i\n", node_tocheck->number, node_tocheck->position);
	printf("-------FIN DE IMPRESION de unico nodo-------\n");
}

void	swap_one(t_head_list *head) //pasar esta funciona move_stack.c
{
	t_node	*old_first;
	t_node	*new_first;
	t_node	*third;

	if (head->size_list < 2)
		return ;
	old_first = head->header;
	new_first = old_first->next;
	old_first->position = 1;
	new_first->position = 0;
	new_first->prev = NULL;  //1
	head->header = new_first; //2
	old_first->prev = new_first; //3
	printf("s%c\n", head->stack_name); //estoy hay que buscarse como hacerlo mejor
	if (head->size_list == 2)
	{
		new_first->next = old_first;
		old_first->next = NULL;
		head->tail = old_first;
		return ;
	} 
	third = new_first->next;
	third->prev = old_first;
	old_first->next = third;
	new_first->next = old_first; 
}

/* 
** Si la lista pusher esta vacia: no hacemos nada
** Si la lista pusher tiene 1 elemento: guardamos le nodo , e iniciliazamos lista
** Si la lista pusher tiene > 2 elementos: guardamos nodo, y actualizamos lista
*/
void	push_topushed(t_head_list *head_pusher, t_head_list *head_pushed)  //pasar esta funciona move_stack.c
{
	t_node	*pusher;
	t_node	*newfirst_pusher; //solo a usar si hay mas de un elemento en la lista del spusher

	if (head_pusher->size_list == 0)
	{
		printf("Empuja la lista %c pero esta vacia. No action\n", head_pusher->stack_name); //esto hayqque borrarlo
		return ;
	}
	pusher = head_pusher->header;
	pusher->position = 0;
	
	if (head_pusher->size_list == 1)
	{
		initialize_list(head_pusher, head_pusher->stack_name);
	}
	else
	{
		newfirst_pusher = pusher->next;
		newfirst_pusher->prev = NULL;
		pusher->next = NULL;
		head_pusher->header = newfirst_pusher;
		head_pusher->size_list--;
		decreas_posit_nodes(head_pusher);
	}
	
	// printf("---impresion de la lista pusher dentro de funcion push_topushed\n");
	// print_list(head_pusher);
	// printf("---impresion de la lista pushed dentro de funcion push_topushed\n");
	// print_list(head_pushed);
	// print_node(pusher);
	add_node_begginig(head_pushed, pusher);
	printf("p%c\n", head_pushed->stack_name);
	// printf("push%c --- pusher:%c ,  pushed:%c ,\n", head_pushed->stack_name, head_pusher->stack_name, head_pushed->stack_name); lo puedo borrar . solo control
}

void	rotate_stack(t_head_list *head)
{
	t_node	*new_last;
	t_node	*new_first;
	
	if (head->size_list < 2)
	{
		printf("lista de menos de 2 elementos. No hacemos nada");
		return ;
	}
	new_last = head->header;
	new_first = new_last->next;
	new_first->prev = NULL;
	new_last->next = NULL;
	new_last->prev = head->tail;
	head->tail->next = new_last;
	head->header = new_first;
	head->tail = new_last;
	decreas_posit_nodes(head);
	new_last->position = (int)head->size_list - 1;
	printf("r%c (rotate)\n", head->stack_name);
}

void	add_node_begginig(t_head_list *head, t_node *new_node) //pasar esta funcion a operations_in_list.c
{
	t_node	*old_first;

	head->size_list++;
	if (!head->header)
	{
		head->header = new_node;
		head->tail = new_node;
		return ;
	}
	increas_posit_nodes(head);
	old_first = head->header;
	old_first->prev = new_node;
	new_node->next = old_first;
	head->header = new_node;
}

void add_node_end(t_head_list *head, t_node *new_node) //pasar esta funcion a operations_in_list.c
{
	head->size_list++;
	if (!head->header)
	{
		head->header = new_node;
		head->tail = new_node;
		return ;
	}
	new_node->prev = head->tail;
	head->tail->next = new_node;
	head->tail = new_node;
}

void	increas_posit_nodes(t_head_list *head)
{
	t_node	*current;
	
	if (!head->header)
		return ;
	current = head->header;
	while (current)
	{
		current->position++;
		current = current->next;
	}
}

void	rotate_stack_reverse(t_head_list *head)
{
	t_node	*new_second;
	t_node	*new_first;
	
	if (head->size_list < 2)
	{
		printf("lista de menos de 2 elementos. No hacemos nada");
		return ;
	}
	new_second = head->header;
	new_first = head->tail;
	head->tail = head->tail->prev;
	new_first->prev = NULL;
	new_second->prev = new_first;
	new_first->next = new_second;
	head->tail->next = NULL;
	head->header = new_first;
	increas_posit_nodes(head);
	new_first->position = 0;
	printf("r%c (rotate)\n", head->stack_name);
}

void	decreas_posit_nodes(t_head_list *head)
{
	t_node	*current;
	
	if (!head->header)
		return ;
	current = head->header;
	while (current)
	{
		current->position--;
		current = current->next;
	}
}