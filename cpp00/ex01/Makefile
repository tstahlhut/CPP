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

CXX		= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp Contact.class.cpp PhoneBook.class.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS): $(SRCS)
			$(CXX) $(CXXFLAGS) $(SRCS) -c 

clean:
ifneq ("$(wildcard) $(OBJS)", "")
		$(RM) $(OBJS)
endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re