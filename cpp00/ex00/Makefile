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

CXX		= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		=	megaphone.cpp

OBJ		=	$(SRC:%.cpp=%.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
ifneq ("$(wildcard $(OBJ))", "")
		$(RM) $(OBJ)
endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re