# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/06/10 16:24:56 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=  array
CXX		=	c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
FILEEXT	= .cpp
SRCDIR   = ./sources
INCDIR   = ./includes
OBJDIR   = ./objects

# List of source files
SRC      = main

# List of source files with file extension .cpp
SRCS	= $(addsuffix $(FILEEXT), $(SRC))

# List of object files to be created from source files
OBJS     = $(SRCS:%$(FILEEXT)=$(OBJDIR)/%.o)

# List of header files
INCLS    = $(wildcard $(INCDIR)/*.hpp)



all: $(OBJDIR) $(NAME)

# Creation of object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Rule to compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%$(FILEEXT) $(INCLS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCDIR)

# Rule to link object files into executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
ifneq ("$(wildcard $(OBJS))", "")
	rm -rf $(OBJDIR)
endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
			$(RM) $(NAME)
endif

re:		fclean all

.PHONY: all clean fclean re
