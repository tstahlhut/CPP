# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/02/26 13:23:55 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

CC	= c++

CPPFLAG	= -std=c++98

CFLAGS	= -Wall -Wextra -Werror

SRCS	=	main.cpp Contact.class.cpp PhoneBook.class.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(CPPFLAG) $(SRCS) -o $@

clean:

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re