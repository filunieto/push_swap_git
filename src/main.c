/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:33:42 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/05 15:07:58 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	atexit(check_leaks);
*/
void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_head_list		head_a;
	t_head_list		head_b;
	t_head_list		sorting_copy;
	char			**array_words;

	initialize_list(&head_a, 'a');
	initialize_list(&head_b, 'b');
	initialize_list(&sorting_copy, 'c');
	array_words = NULL;
	if (argc < 2)
		exit (1);
	split_input(argc - 1, &argv[1], &head_a, array_words);
	if (check_doubles(&head_a))
		exit_freelist(&head_a, 1, 1);
	if (is_sorted(&head_a))
		exit_freelist(&head_a, 0, 1);
	split_input(argc - 1, &argv[1], &sorting_copy, array_words);
	indexing_list(&head_a, &sorting_copy);
	we_can_finally_sort(&head_a, &head_b);
	return (1);
}
