/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:33:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/07 16:20:36 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				number;
	int				position;
	int				index;
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

//Checking leaks
void	check_leaks(void);

// Converting from inputs to nodes and then  list
void	split_input(int argc, char **argv1, \
		t_head_list *head, char **array_words);
void	initialize_list(t_head_list *head, char stack_name);
void	extract_inpt(t_head_list *head, char **array_words, size_t *posicion);
void	print_list(t_head_list *head);
void	print_node(t_node *node_tocheck);
void	print_stack(t_head_list *head_a, t_head_list *head_b);

// Previous verification from users's inputs
int		check_doubles(t_head_list *head);
int		is_sorted(t_head_list *head_a);

// Errors, free lists and / or arrays
void	error_and_free_all(t_head_list *head_a, t_head_list *head_b);
void	delete_list(t_head_list *head);
void	free_array_list(char **array_words, t_head_list *head);
void	error(int message, int needs_exit);
void	free_all(t_head_list *head_a, t_head_list *head_b);
void	exit_freelist(t_head_list *head, int message, int needs_exit);

// Movements in stack
void	swap_one_basic(t_head_list *head);
void	swap_one(t_head_list *head);
void	push_topushed(t_head_list *head_pusher, t_head_list *head_pushed);
void	rotate_stack(t_head_list *head);
void	rotate_stack_reverse(t_head_list *head);
t_node	*swap_nodes(t_head_list *head, int position);
t_node	*swap_first_node(t_head_list *head);
void	print_order(char c, int movement);

// List operations
void	add_node_begginig(t_head_list *head, t_node *new_node);
void	add_node_end(t_head_list *head, t_node *new_node);
void	increas_posit_nodes(t_head_list *head);
void	decreas_posit_nodes(t_head_list *head);

// Pre Algoritmos Bubble sort
void	bubble_sort(t_head_list *head_c);
void	indexing_list(t_head_list *head_a, t_head_list *sorting_copy);
void	convert_index_bin(t_head_list *head_a);
int		num_bin(int num);

// Operations in stack for algorithms
void	search_max_stack(t_head_list *head);
void	search_min_stack(t_head_list *head);
void	update_min_max(t_head_list *head_a, t_head_list *head_b);
void	update_min_max_onelist(t_head_list *head_a);

// Sorting algorithms: short */
void	we_can_finally_sort(t_head_list *head_a, t_head_list *head_b);
void	algortim_short(t_head_list *head_a, t_head_list *head_b);
void	sort_three(t_head_list *head_a);
void	sort_more_three(t_head_list *head_a, t_head_list *head_b);

// Sorting algorithms: medium 
void	algortim_medium(t_head_list *head_a, t_head_list *head_b);
void	move_max_a(t_head_list *head_a, t_head_list *head_b);
void	algo_chunkcreate(t_head_list *head_a, t_head_list *head_b);
void	algo_calcuchunk(t_head_list *head_a);

// Bonus functions
void	checker(t_head_list *head_a, t_head_list *head_b, char *line);
void	free_all_error(t_head_list *head_a, t_head_list *head_b, char *line);



# define NUMB_FILE_DESCR 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_node_gnl
{
	char			*content;
	struct s_node_gnl	*next;
}t_node_gnl;

typedef struct s_head_list_gnl
{
	t_node_gnl	*header;
}t_head_list_gnl;

char	*get_next_line(int fd);
void	ft_read_and_stash(int fd, t_head_list_gnl *head);
void	ft_add_to_stash(t_head_list_gnl *head, char *buff, int readed);
void	clean_stash(t_head_list_gnl *head);
void	ft_extract_line(t_head_list_gnl *head, char **line);
int		found_newline(t_head_list_gnl *head);
t_node_gnl	*ft_lst_get_last(t_head_list_gnl *head);
void	generate_line(t_head_list_gnl *head, char **line);
void	ft_delete_list(t_head_list_gnl *head);

#endif