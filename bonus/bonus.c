/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:38:29 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/07 19:20:24 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


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
	// else if (!ft_strncmp(line, "rr\n", 3))  //necesito poner esto y listo
	// 	ft_r_sim(a, b);
	// else if (!ft_strncmp(line, "rrr\n", 4))
	// 	ft_rr_sim(a, b);
	// else if (!ft_strncmp(line, "ss\n", 3))
	// 	ft_ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_topushed(head_b, head_a);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_topushed(head_a, head_b);
	else
		free_all_error(head_a, head_b, line);
}

int	main(int argc, char **argv)
{
	t_head_list		head_a;
	t_head_list		head_b;
	char			**array_words;

	if (argc == 1)
		return (0);
	initialize_list(&head_a, 'a');
	initialize_list(&head_b, 'b');
	array_words = NULL;
	split_input(argc - 1, &argv[1], &head_a, array_words);
	if (check_doubles(&head_a))
		exit_freelist(&head_a, 1, 1);
	lets_bonus(&head_a, &head_b);
}

void		lets_bonus(t_head_list *head_a, t_head_list *head_b)
{
	char	*line;
	
	head_a->stack_name = 'd';
	head_b->stack_name = 'd';
	line = get_next_line(0);
	while (line != NULL)
	{
		checker(head_a, head_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(head_a) && !head_b->header)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(head_a, head_b);

}