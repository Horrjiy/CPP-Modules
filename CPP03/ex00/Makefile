# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 19:07:38 by mpoplow           #+#    #+#              #
#    Updated: 2025/06/24 17:36:55 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++17
NAME		:= andopen

SRCS		= main.cpp ClapTrap.cpp
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