# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:13:04 by vm                #+#    #+#              #
#    Updated: 2024/05/26 16:47:24 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=  serialize
CXX		=	c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
FILEEXT	= .cpp
SRCDIR   = ./sources
INCDIR   = ./includes
OBJDIR   = ./objects

# List of source files
SRC      = main Serializer

# List of source files with file extension .cpp
SRCS	= $(addsuffix $(FILEEXT), $(SRC))

# List of object files to be created from source files
OBJS     = $(SRCS:%$(FILEEXT)=$(OBJDIR)/%.o)

# List of header files
INCLS    = $(wildcard $(INCDIR)/*.h)



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
