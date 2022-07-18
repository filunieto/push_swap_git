/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:44 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/18 20:45:26 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
No olvidar free despues de ft_split
una vez tengamos el array de string , lo vamos convirtiendo a con atoi, a la vez que iremos verificando que son numeros
*/
void	initialize_list(t_head_list *head)
{
	head->header = NULL;
	head->tail = NULL;
	head->max = 0;
	head->min = 0;
	head->size_list = 0;
}

int	main(int argc, char **argv)
{
	t_head_list		head_a;
	t_head_list		head_b;
	char **array_words;

	// declaramos todas las variables y las iniciliazmos a NULL. Para cuando tengamos un error hacemos free de todo: stack a , b y ft split. Hacer funcion free.
	initialize_list(&head_a);
	initialize_list(&head_b);
	array_words = NULL;
	if (argc < 2)
	{
		write(1, "Error en el numero de argumentos\n", 34); //cambair el mensaje de error
		exit (1);
	}
	// 1. funcion que extraiga los inputs y los vaya metiendo en una lista . Devuelve el header 
	extract_inputs_tolist(argc - 1, &argv[1], &head_a, &array_words);
	//1.1 si la lista esta vacia o hay algun error >>> Salir (verificar si hay que hacer alg'un free de malloc)
	if (!head_a.header)
	{
		printf("problemas convirtiendo inputs en lista\n"); //hariamos directamente un error and free
		return (1);
	}
	//2. tenemos la lista en el stack a. Comenzamos a ordenar:
	sorting_list(&head_a);
	return (2);
}

void	error_and_free_all(t_head_list *head_a, t_head_list *head_b, char **array_words)
{
	/* borar listas y free todo e imprimir el mensaje de error*/
}