/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/18 11:52:48 by fnieves-         ###   ########.fr       */
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
	int		number;
	int		position;
	struct s_node	*next;
}	t_node;

typedef struct s_head_list
{
	t_node	*header;
	int		size_list;
	t_node	*tail;
}	t_head_list;

void	extract_inputs_tolist(int argc, char **argv1, t_head_list *head);

#endif