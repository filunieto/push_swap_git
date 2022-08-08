# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:55:21 by fnieves-          #+#    #+#              #
#    Updated: 2022/08/08 19:37:24 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src bonus
INCFLAGS = -I libft -I include

CC		= cc
FLAGS	=  -Wall -Werror -Wextra

NAME		=	push_swap
BONUSNAME	=	checker

HEADER	= 	include/push_swap.h

SRC	= 		push_swap.c \
			operations_in_list.c \
			main.c \
			moves_basic_stack.c \
			convert_input_tolist.c \
			is_sorted.c \
			bubble_sort.c \
			algortim_short.c \
			algortim_medium.c \
			search_limits_stack.c \
			free_error.c \
			get_next_line_utils.c \
			get_next_line.c \


BON 	= 	bonus.c \
	 		push_swap.c \
			operations_in_list.c \
			moves_basic_stack.c \
			convert_input_tolist.c \
			is_sorted.c \
			bubble_sort.c \
			algortim_short.c \
			algortim_medium.c \
			search_limits_stack.c \
			free_error.c \
			get_next_line_utils.c \
			get_next_line.c \


LIBS	= libft/libft.a
OBJ		= $(addprefix obj/,$(notdir $(SRC:.c=.o)))
BONOBJ	= $(addprefix obj/,$(notdir $(BON:.c=.o)))

$(NAME) : $(OBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $@ $^ -Llibft -lft
	@echo "push_swap is compiled"


obj/%.o : %.c $(LIBS) $(HEADER) | obj
	$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj :
	mkdir obj


$(LIBS) :
	-(cd libft && make)
	-(cd libft && make clean)

all : $(NAME)

bonus : $(BONOBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $(BONUSNAME) $^ -Llibft -lft
	@echo "Checker from bonus is compiled"

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME) $(BONUSNAME)
	-(cd libft && make fclean)

re : clean all

libs : fclean all

.PHONY : all clean fclean re bonus

