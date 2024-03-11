# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/03/11 17:00:48 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= brain

CXX	= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

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