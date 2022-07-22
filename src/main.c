/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:33:42 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/21 18:42:42 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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