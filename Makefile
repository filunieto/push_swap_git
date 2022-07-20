# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:55:21 by fnieves-          #+#    #+#              #
#    Updated: 2022/07/19 10:46:02 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	push_swap.c \
						push_swap_tools.c \

LIBFTFILES		= 	ft_isdigit.c \
					ft_split.c \
					ft_atoi.c \

LIB				=	libft.a 

LIBFTSRCS		= $(addprefix libft/,$(LIBFTFILES))

OBJS			= $(SRCS:.c=.o)

LIBFTOBJS		= $(LIBFTSRCS:.c:.o)

HEADER			= push_swap.h

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap.a

#rules
all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
				$(CC) $(CFLAGS) -o $(NAME) -L. -lft

$(LIB):			$(LIBFTOBJS) $(HEADER)
				ar -rcs $(LIB) $(LIBFTOBJS)

clean:
				$(RM) $(OBJS) $(LIBFTOBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:

.PHONY:			all clean fclean re bonus


# para compilar miesntras tanto 
# gcc -Wall -Wextra -Werror push_swap.c push_swap_tools.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c -o push_swap