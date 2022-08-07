# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:55:21 by fnieves-          #+#    #+#              #
#    Updated: 2022/08/07 16:33:08 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src bonus
INCFLAGS = -I libft -I include #si ncluimls mas librerias modificar: include , buscara los headers

CC		= cc
FLAGS	=  -Wall -Werror -Wextra

NAME		=	push_swap
BONUSNAME	=	checker

HEADER	= 	include/push_swap.h

#atencion que en uno he puesto carpetas src/ y e otro no. Armonizar
SRC	= 		push_swap.c \
			operations_in_list.c \
			main.c \
			moves_basic_stack.c \
			convert_input_tolist.c \
			checking_lists.c \
			is_sorted.c \
			bubble_sort.c \
			algortim_short.c \
			algortim_medium.c \
			search_limits_stack.c \
			free_error.c \
			get_next_line_utils.c \
			get_next_line.c \


BON 	= 	bonus.c


LIBS	= libft/libft.a 	# ftprintf/libftprintf.a, ...
OBJ		= $(addprefix obj/,$(notdir $(SRC:.c=.o))) #notdir , no incluir directorio
BONOBJ	= $(addprefix obj/,$(notdir $(BON:.c=.o)))

# tengo que quitar el (-lm (matematica)  -framework OpenGL -framework AppKit) de abajo? tpdp librerias de fractol
$(NAME) : $(OBJ) | $(LIBS) #la barra significa que no es necesario volver a hacer el direct OBJ. si esta hecho no lo hagas
	$(CC) $(FLAGS) -o $@ $^ -Llibft -lft

obj/%.o : %.c $(LIBS) $(HEADER) | obj
	$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj :
	mkdir obj

#(cd ftprintf && make && make clean). Lo he borrado de abajo

$(LIBS) :
	-(cd libft && make)
	-(cd libft && make clean)

all : $(NAME)

bonus : $(BONOBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $(NAME) $^ -Llibft -lft

clean :
	rm -rf obj

# -(cd ftprintf && make fclean) >> he borrado esto.
fclean : clean
	rm -f $(NAME)
	-(cd libft && make fclean)

re : clean all

libs : fclean all

.PHONY : all clean fclean re bonus

