/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/05 12:58:17 by fnieves-         ###   ########.fr       */
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
	t_head_list		*head_a;
	t_head_list		*head_b;
	t_head_list		*sorting_copy;
}		t_stacks;

//Checking leaks
void	check_leaks(void);

// Converting from inputs to nodes and then  list
void	split_input(int argc, char **argv1, t_head_list *head, char **array_words);
void	initialize_list(t_head_list *head, char stack_name);
void	extract_inpt(t_head_list *head, char **array_words , size_t *posicion);

void	print_list(t_head_list *head);
void	print_node(t_node *node_tocheck);
void	print_stack(t_head_list *head_a, t_head_list *head_b);


// verificaciones previas
int		check_doubles(t_head_list *head);
int		is_sorted(t_head_list *head_a);


// errors, free lists and / or arrays

void	error_and_free_all(t_head_list *head_a, t_head_list *head_b);
void	delete_list(t_head_list *head);
void	free_array_list(char **array_words, t_head_list *head);
void	error(int message, int needs_exit);
void	free_all(t_head_list *head_a, t_head_list *head_b);
void	exit_freelist(t_head_list *head, int message, int needs_exit);



void	swap_one_basic(t_head_list *head);
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
void	update_min_max_onelist(t_head_list *head_a);



t_node	*swap_nodes(t_head_list *head, int position);
t_node	*swap_first_node(t_head_list *head);


void	we_can_finally_sort(t_head_list *head_a, t_head_list *head_b);
/* Algortimos de ordenacion: short */
void	algortim_short(t_head_list *head_a, t_head_list *head_b);
void	sort_three(t_head_list *head_a);
void	sort_more_three(t_head_list *head_a, t_head_list *head_b);

/* Algortimos de ordenacion: medium */

void	algortim_medium(t_head_list *head_a, t_head_list *head_b);
void	move_min_finalpart(t_head_list *head_a, t_head_list *head_b);

/* Algortimos de ordenacion: long */
void	algortim_long(t_head_list *head_a, t_head_list *head_b);
void	chunk_calculator(t_head_list *head);
void	move_min(t_head_list *head_a, t_head_list *head_b, int count_chunk);

int		find_chunk_from_top(t_head_list *head_a);
int		find_chunk_from_bottom(t_head_list *head_a);
void	move_top(t_head_list *head, int position);
void	move_bottom(t_head_list *head, int position);

//comunes
void	move_max(t_head_list *head_b, t_head_list *head_a);
void	move_min_finalpart(t_head_list *head_a, t_head_list *head_b);
void	move_max_a(t_head_list *head_a, t_head_list *head_b);

//uevo algoritmo
void	algo_chunkcreate(t_head_list *head_a, t_head_list *head_b);
void	algo_calcuchunk(t_head_list *head_a);







#endif