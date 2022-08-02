/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:33:42 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/02 18:09:07 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check(void) //funcion para borrar
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	//podemos declarar un puntero a las 2 pilas 
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
	extract_inputs_tolist(argc - 1, &argv[1], &head_a, array_words); //revisar esta nomenclatura de punteros de arrays, creo que (&*array_words == array_words)
	if(check_doubles(&head_a))
	{
		printf("en la lista hay valores dobles. Salir\n");
		exit (3);
	}
	if (is_sorted(&head_a))
		exit (4);

	//creamos la lista c en al que amos a hacer un presorting
	//print_stack(&head_a, &head_b);
	extract_inputs_tolist(argc - 1, &argv[1], &sorting_copy, array_words);
	bubble_sort(&sorting_copy);
	indexing_list(&head_a, &sorting_copy);
	


	

	if (head_a.size_list <= 5)
		algortim_short(&head_a, &head_b);
	else
		algortim_long(&head_a, &head_b);
	
	return (2);
	//antes de return free de listas Realizar los otrso free a medida que no los necesitemos mas
	
}