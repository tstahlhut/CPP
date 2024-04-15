# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/03/09 14:53:50 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= global_banksters

CXX	= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	=	Account.cpp tests.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS) -o $@

$(OBJS): $(SRCS)
		$(CXX) $(CXXFLAGS) $(SRCS) -c			

clean:
ifneq ("$(wildcard $(OBJS))", "")
		$(RM) $(OBJS)
endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re