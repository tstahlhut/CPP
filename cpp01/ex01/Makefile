# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/03/11 14:32:31 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie

CXX	= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp Zombie.cpp zombieHorde.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re