/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:33:42 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/03 10:20:45 by fnieves-         ###   ########.fr       */
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
	t_head_list		sorting_copy;
	char **array_words;

	//atexit(check); //borrar solo para emmory leaks
	initialize_list(&head_a, 'a');
	initialize_list(&head_b, 'b');
	initialize_list(&sorting_copy, 'c');
	array_words = NULL;
	if (argc < 2)
	{
		write(1, "Error en el numero de argumentos\n", 34); //cambair el mensaje de error y hcer free
		exit (1);
	}
	split_convert_input_tolist(argc - 1, &argv[1], &head_a, array_words); //revisar esta nomenclatura de punteros de arrays, creo que (&*array_words == array_words)
	if(check_doubles(&head_a))
	{
		printf("en la lista hay valores dobles. Salir\n");
		exit (3);
	}
	if (is_sorted(&head_a))
		exit (4);
	split_convert_input_tolist(argc - 1, &argv[1], &sorting_copy, array_words);
	bubble_sort(&sorting_copy);
	indexing_list(&head_a, &sorting_copy);
	// para 20 o menos no funciona. Creo que no funcikna el de 5
	lets_sorting(&head_a, &head_b);
	//print_stack(&head_a, &head_b);
	return (2);	
}