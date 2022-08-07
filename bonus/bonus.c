/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:38:29 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/07 16:36:13 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	exit_checker(t_dlst *a, t_dlst *b, char *line)
// {
// 	free(line);
// 	dlst_clear(a);
// 	dlst_clear(b);
// 	ft_putstr_fd("Error\n", STDERR_FILENO);
// 	exit(0);
// }

void	checker(t_head_list *head_a, t_head_list *head_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap_one(head_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_one(head_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_stack(head_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_stack(head_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rotate_stack_reverse(head_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rotate_stack_reverse(head_b);
	// else if (!ft_strncmp(line, "rr\n", 3))
	// 	ft_r_sim(a, b);
	// else if (!ft_strncmp(line, "rrr\n", 4))
	// 	ft_rr_sim(a, b);
	// else if (!ft_strncmp(line, "ss\n", 3))
	// 	ft_ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_topushed(head_a, head_b);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_topushed(head_b, head_a);
	else
		free_all_error(head_a, head_b, line);
}

// void	check_dupl_b(t_dlst *a)
// {
// 	t_dlst	sor;

// 	check_dupl(a, &sor);
// 	dlst_clear(&sor);
// }

int	main(int argc, char **argv)
{
	t_head_list		head_a;
	t_head_list		head_b;
	char			**array_words;
	char	*line;


	if (argc == 1)
		return (0);
	initialize_list(&head_a, 'a');
	initialize_list(&head_b, 'b');
	array_words = NULL;
	split_input(argc - 1, &argv[1], &head_a, array_words);
	if (check_doubles(&head_a))
		exit_freelist(&head_a, 1, 1);//habra que cambiar el mensaje de rror
	//make_stack_a(argc, argv, &a);
	//check_dupl_b(&a);
	
	// dlst_init(&b, 'b');
	// a.name = 'c';
	// b.name = 'c';
	
	line = get_next_line(0);
	while (line != NULL)
	{
		checker(&head_a, &head_b, line); //cambiamos la funcion
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(&head_a) && !head_b.header)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&head_a, &head_b);
}
