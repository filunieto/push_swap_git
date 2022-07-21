/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:44 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/21 11:50:50 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_list(t_head_list *head, char stack_name)
{
	head->header = NULL;
	head->tail = NULL;
	head->max = 0;
	head->min = 0;
	head->size_list = 0;
	head->stack_name = stack_name;
}

void	check(void) //funcion para borrar
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_head_list		head_a;
	t_head_list		head_b;
	char **array_words;

	//atexit(check); //borrar solo para emmory leaks
	initialize_list(&head_a, 'a');
	initialize_list(&head_b, 'b');
	array_words = NULL;
	if (argc < 2)
	{
		write(1, "Error en el numero de argumentos\n", 34); //cambair el mensaje de error y hcer free
		exit (1);
	}
	extract_inputs_tolist(argc - 1, &argv[1], &head_a, &*array_words); //revisar esta nomenclatura de punteros de arrays
	// if(check_doubles(&head_a)) Verificams si hay dobles. Ya veremos el valor de retorno
	// 	error_and_free_all(t_head_list *head_a, t_head_list *head_b)
	// swap_one(&head_a); solo para pruebas
	printf("---impresion de la lista de datos original: head_a\n");
	print_list(&head_a);
	//print_list(&head_b);

	printf("\n\n");

	rotate_stack_reverse(&head_a);
	printf("---impresion de la lista rotada reversa head_a\n");
	print_list(&head_a);
	rotate_stack_reverse(&head_a);
	printf("---impresion de la lista rotada reversa head_a\n");
	print_list(&head_a);
	rotate_stack(&head_a);
	rotate_stack(&head_a);
	printf("---impresion de la lista rotada 2 veces inversamente  tiene que ser original head_a\n");
	print_list(&head_a);

	// printf("---impresion de la lista pushed head_b\n");
	// print_list(&head_b);
	
	
	// if (!head_a.header) // Necesito verificr esto??
	// {
	// 	printf("Problemas convirtiendo inputs en lista\n"); //hariamos directamente un error and free
	// 	return (1);
	// }
	
	//2. tenemos la lista en el stack a. Comenzamos a ordenar:
	//sorting_list(&head_a);
	
	return (2);
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

void	delete_list(t_head_list *head)
{
	t_node	*node_todelete;
	t_node	*current;

	if (!head->header)
		return ;
	current = head->header;
	while (current)
	{
		node_todelete = current;
		current = current->next;
		node_todelete->next = NULL;
		node_todelete->prev = NULL;
		free(node_todelete);
	}
	head->header = NULL;
	head->tail = NULL;
}
