/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:44 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/18 17:01:48 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* vammos a pasar una direccion al array a partir del segundo elemento &argv[1] como un aray de strings
y usaremos la funcion ft_split para separar los argumentos con espacios y transformarlos en un array
No olvidar free despues de ft_split
una vez tengamos el array de string , lo vamos convirtiendo a con atoi, a la vez que iremos verificando que son numeros
*/

int	main(int argc, char **argv)
{
	t_head_list		head_a;
	// declaramos todas las variables y las iniciliazmos a NULL. Para cuando tengamos un error hacemos free de todo: stack a , b y ft split. Hacer funcion free.
	head_a.header = NULL;
	if (argc < 2)
		return (0);
	// 1. funcion que extraiga los inputs y los vaya metiendo en una lista . Devuelve el header 
	extract_inputs_tolist(argc - 1, &argv[1], &head_a);
	//1.1 si la lista esta vacia o hay algun error >>> Salir (verificar si hay que hacer alg'un free de malloc)
	if (!head_a.header)
	{
		printf("problemas convirtiendo inputs en lista\n");
		return (1);
	}
	//2. tenemos la lista en el stack a. Comenzamos a ordenar:
	sorting_list(&head_a);
	return (2);
}