/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/18 20:22:07 by fnieves-         ###   ########.fr       */
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
	t_node	*header;
	t_node	*tail;
	size_t	size_list;
	int		max;
	int		min;
}	t_head_list;

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head, char **array_words);
void	initialize_list(t_head_list *head);

#endif