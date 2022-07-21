/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/21 11:46:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//verificar librerias
# include <stdio.h> //esta fuera 
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_movements
{
	int			sa;
	int			sb;
}		t_movements;

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int		number;
	int		position;
}	t_node;

typedef struct s_head_list
{
	t_node	*header; // t_node stack_a;
	t_node	*tail; //// t_node stack_b;
	size_t	size_list;
	int		max;
	int		min;
	char	stack_name;
}	t_head_list;

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head, char **array_words);
void	initialize_list(t_head_list *head, char stack_name);
void	print_array(t_head_list *head, char **array_words , size_t *posicion);

void	print_list(t_head_list *head);
void	print_node(t_node *node_tocheck);

int		check_doubles(t_head_list *head);


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



#endif