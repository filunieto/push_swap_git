# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:55:21 by fnieves-          #+#    #+#              #
#    Updated: 2022/07/22 10:30:55 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src #bonus, anadir?
INCFLAGS = -I libft -I include #si ncluimls mas librerias modificar

CC		= cc
FLAGS	= -Wall -Werror -Wextra
RM		= rm -f
# BONUSNAME = push_swap?

NAME	= push_swap
# BONUSNAME = push_swap?
HEADER	= 	include/push_swap.h

SRC	= 		push_swap.c \ 
			operations_in_list.c \ 
			moves_stack.c main.c \
			main.c \
			convert_input_tolist.c \
			checking_lists.c \

# BON 	= main_bonus.c


LIBS	= libft/libft.a 	# ftprintf/libftprintf.a, ...
OBJ		= $(addprefix obj/,$(notdir $(SRC:.c=.o)))
# BONOBJ	= $(addprefix obj/,$(notdir $(BON:.c=.o)))

# tengo que quitar el (-lm  -framework OpenGL -framework AppKit) de abajo?
$(NAME) : $(OBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $@ $^ -Llibft -lft 

obj/%.o : %.c $(LIBS) $(HEADER) | obj
	$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj :
	mkdir obj

# -(cd ftprintf && make && make clean). Lo he borrado de abajo
$(LIBS) :
	-(cd libft && make)
	-(cd libft && make clean)

all : $(NAME)

# bonus : $(BONOBJ) | $(LIBS) . Aqui habra que borrar movidas
# 	$(CC) $(FLAGS) -o $(NAME) $^ -Llibft -lft -Lftprintf -lftprintf -lm -Lmlx -lmlx -framework OpenGL -framework AppKit

clean :
	$(RM) obj

# -(cd ftprintf && make fclean) >> he borrado esto.
fclean : clean
	rm -f $(NAME)
	-(cd libft && make fclean)
	-(cd ftprintf && make fclean)

re : clean all

libs : fclean all

.PHONY : all clean fclean re bonus


# para compilar mientras funciona 
# gcc -Wall -Wextra -Werror src/checking_lists.c src/convert_input_tolist.c  src/main.c  src/moves_stack.c src/operations_in_list.c src/push_swap.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c -o push_swap