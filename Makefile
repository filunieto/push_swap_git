# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:55:21 by fnieves-          #+#    #+#              #
#    Updated: 2022/07/26 12:42:03 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src #bonus, anadir?  >>> folder
INCFLAGS = -I libft -I include #si ncluimls mas librerias modificar: include , buscara los headers

CC		= cc
FLAGS	= -Wall -Werror -Wextra
# BONUSNAME = push_swap?

NAME	= push_swap
# BONUSNAME = push_swap?
HEADER	= 	include/push_swap.h

#atencion que en uno he puesto carpetas src/ y e otro no. Armonizar
SRC	= 		push_swap.c \
			operations_in_list.c \
			moves_stack.c main.c \
			main.c \
			convert_input_tolist.c \
			checking_lists.c \
			quick_sort.c \
			is_sorted.c \
			bubble_sort.c \

# BON 	= main_bonus.c


LIBS	= libft/libft.a 	# ftprintf/libftprintf.a, ...
OBJ		= $(addprefix obj/,$(notdir $(SRC:.c=.o))) #notdir , no incluir directorio
# BONOBJ	= $(addprefix obj/,$(notdir $(BON:.c=.o)))

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

# bonus : $(BONOBJ) | $(LIBS) . Aqui habra que borrar movidas
# 	$(CC) $(FLAGS) -o $(NAME) $^ -Llibft -lft -Lftprintf -lftprintf -lm -Lmlx -lmlx -framework OpenGL -framework AppKit

clean :
	rm -rf obj

# -(cd ftprintf && make fclean) >> he borrado esto.
fclean : clean
	rm -f $(NAME)
	-(cd libft && make fclean)

re : clean all

libs : fclean all

.PHONY : all clean fclean re bonus


# para compilar mientras funciona 
# gcc -Wall -Wextra -Werror src/checking_lists.c src/convert_input_tolist.c  src/main.c  src/moves_stack.c src/operations_in_list.c src/push_swap.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c -o push_swap