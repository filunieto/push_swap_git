/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:33:42 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/25 17:25:08 by fnieves-         ###   ########.fr       */
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
	printf("List no ordenada continuamos para bingo. \n");

	// ./push_swap 9 5 8 1 6 2 4 10 3 7 : numeros de prueba
	//creamos la lista c en al que amos a hacer un presorting
	extract_inputs_tolist(argc - 1, &argv[1], &sorting_copy, array_words); 
	// if (!head_a.header) // Necesito verificr esto??
	// {
	// 	printf("Problemas convirtiendo inputs en lista\n"); //hariamos directamente un error and free
	// 	return (1);
	// }

	//2. tenemos la lista en el stack a. Comenzamos a ordenar:
	//sorting_list(&head_a);
	
	return (2);
}