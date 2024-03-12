# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/03/12 18:12:20 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fight

CXX	= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

DIRINCL	=	./includes/

DIRSRCS =	./sources/

SRC		= 	main HumanA HumanB Weapon

SRCS	=	$(addprefix $(DIRSRCS), $(addsuffix .cpp, $(SRC)))

OBJS	=	$(SRCS:.cpp=.o)

RM		=	rm -f

all:		$(NAME)

%.o = $(DIRSRCS)%.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(DIRINCL)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $@ -I $(DIRINCL)



clean:

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re