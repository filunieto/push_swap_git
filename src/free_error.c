/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:04:19 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/03 17:04:05 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_head_list *head_a, t_head_list *head_b) //hay qe borrar el array de char depsues de split
{
	delete_list(head_a);
	delete_list(head_b);
}
 /*
	message != 0 >>> Escribe error
	exit != 0 >>> Sale con exit
 */
void	error(int message, int needs_exit)
{
	if (message)
		write(1, "Error\n", 7);
	if (needs_exit)
		exit (1);
}

void free_array_list(char **array_words, t_head_list *head)
{
	int	i;

	i = 0;
	while (array_words[i])
	{
		free(array_words[i++]);
	}
	free(array_words);
	delete_list(head);
	error(1, 1);
}

void	exit_freelist(t_head_list *head, int message, int needs_exit)
{
	delete_list(head);
	error(message, needs_exit);
}

/* errores (int error)
	funcionando :
	Si hay duplicados: error
	Letras como inputs o " " no input entre comillas
	Parametro mayores que INT : error >> en funcion atoi ---atencion


	Sin funcionar:
	si pongo un negaivo: me sale 0
	-------
	volver al promt:
	funcionando :
	Si no hay parametros input
	Lista ordnada

	
*/
