# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 19:07:38 by mpoplow           #+#    #+#              #
#    Updated: 2025/07/15 14:24:09 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++17 -g
NAME		:= bureaucracy

SRCS		= main.cpp Bureaucrat.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo "⭐ creating program ⭐"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SILENT: $(OBJS) $(NAME) 
.PHONY: all clean fclean re