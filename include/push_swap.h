/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/01 12:59:02 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//verificar librerias
# include <stdio.h> //esta fuera 
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h" 

typedef struct s_movements
{
	int			sa;
	int			sb;
}		t_movements;

/*
** number = valor
** position = posicion original
** index = presorting
*/
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int		number;
	int		position;
	int		index;
}	t_node;

typedef struct s_head_list
{
	t_node	*header;
	t_node	*tail;
	size_t	size_list;
	int		max;
	int		posit_max;
	int		min;
	int		posit_min;
	char	stack_name;
	int		chunk;
}	t_head_list;

typedef struct s_stacks
{
	t_head_list		*a;
	t_head_list		*b;
}		t_stacks;

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head, char **array_words);
void	initialize_list(t_head_list *head, char stack_name);
void	print_array(t_head_list *head, char **array_words , size_t *posicion);

void	print_list(t_head_list *head);
void	print_node(t_node *node_tocheck);
void	print_stack(t_head_list *head_a, t_head_list *head_b);


// verificaciones previas
int		check_doubles(t_head_list *head);
int		is_sorted(t_head_list *head_a);



void	error_and_free_all(t_head_list *head_a, t_head_list *head_b);
void	delete_list(t_head_list *head);


void	swap_one(t_head_list *head);
void	push_topushed(t_head_list *head_pusher, t_head_list *head_pushed);
void	rotate_stack(t_head_list *head);
void	rotate_stack_reverse(t_head_list *head);



void	add_node_begginig(t_head_list *head, t_node *new_node);
void	add_node_end(t_head_list *head, t_node *new_node);
void	increas_posit_nodes(t_head_list *head);
void	decreas_posit_nodes(t_head_list *head);


/* Pre Algoritmos Bubble sort*/
void	bubble_sort(t_head_list *head_c);
void	indexing_list(t_head_list *head_a, t_head_list *sorting_copy);
void	convert_index_bin(t_head_list *head_a);
int		num_bin(int num);


/* Operacion en stack para algorotmos*/
void	search_max_stack(t_head_list *head);
void	search_min_stack(t_head_list *head);
void	update_min_max(t_head_list *head_a, t_head_list *head_b);



t_node	*swap_nodes(t_head_list *head, int position);
t_node	*swap_first_node(t_head_list *head);

/* Algortimos de ordenacion: short */
void	algortim_short(t_head_list *head_a, t_head_list *head_b);
void	sort_three(t_head_list *head_a);
void	sort_more_three(t_head_list *head_a, t_head_list *head_b);

/* Algortimos de ordenacion: long */
void	algortim_long(t_head_list *head_a, t_head_list *head_b);
void	chunk_calculator(t_head_list *head);
void	move_min_b(t_head_list *head_a, t_head_list *head_b);

int	find_chunk_from_top(t_head_list *head_a);
int	find_chunk_from_bottom(t_head_list *head_a);
void	move_top(t_head_list *head, int position);
void	move_bottom(t_head_list *head, int position);

void	move_max(t_head_list *head_b, t_head_list *head_a);






#endif