# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/04/29 17:14:21 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= brain
CXX		= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
FILEEXT	= .cpp

# List of source files
SRC      = main

# List of source files with file extension .cpp
SRCS	= $(addsuffix $(FILEEXT), $(SRC))

# List of object files to be created from source files
OBJS     = $(SRCS:%$(FILEEXT)=%.o)



all: $(NAME)

# Rule to compile object files
%.o: %$(FILEEXT)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
ifneq ("$(wildcard $(OBJS))", "")
	rm -rf $(OBJS)
endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY: all clean fclean re
