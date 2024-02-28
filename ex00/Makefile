# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/02/26 09:18:30 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CC	= c++

CPPFLAG	= -std=c++98

CFLAGS	= -Wall -Wextra -Werror

SRCS	=	megaphone.cpp

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(CPPFLAG) $< -o $@

clean:

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re