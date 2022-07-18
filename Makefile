# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:55:21 by fnieves-          #+#    #+#              #
#    Updated: 2022/07/15 11:19:43 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= ft_PRINT***.c \

LIBFTFILES		= ft_isdigit.c \

LIBFTSRCS		= $(addprefix libft/,$(LIBFTFILES))

OBJS			= $(SRCS:.c=.o)

LIBFTOBJS		= $(LIBFTSRCS:.c:.o)

HEADER			= push_swap.h

CC				= CC
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= push_swap.a

#rules
all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFTOBJS) $(HEADER)
				ac -rcs $(NAME) $(OBJS) $(LIBFTOBJS)

clean:
				$(RM) $(OBJS) $(LIBFTOBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:

.PHONY:			all clean fclean re bonus
