# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 10:55:47 by rjesus-d          #+#    #+#              #
#    Updated: 2025/07/21 10:55:54 by rjesus-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
# CONFIG                                                                       #
#==============================================================================#

NAME = fixed

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -rf

#==============================================================================#
# SOURCE FILES                                                                 #
#==============================================================================#

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

#==============================================================================#
# COLORS                                                                       #
#==============================================================================#

RED = \033[1;31m

GREEN = \033[1;32m

RESET = \033[0m

#==============================================================================#
# RULES                                                                        #
#==============================================================================#

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Compilation Successful:$(RESET) $(NAME) created"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if ls $(OBJS) 1> /dev/null 2>&1; then \
		$(RM) $(OBJS); \
		echo "$(GREEN)Intermediate object files removed:$(RESET)\n$(OBJS)"; \
	else \
		echo "$(RED)No object files to remove.$(RESET)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		echo "$(GREEN)Compiled executable removed:$(RESET)\n$(NAME)"; \
	else \
		echo "$(RED)No executable to remove.$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re

################################################################################
