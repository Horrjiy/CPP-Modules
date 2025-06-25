# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 19:07:38 by mpoplow           #+#    #+#              #
#    Updated: 2025/06/20 16:58:38 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++17
NAME		:= moreusefulclass

SRCS		= main.cpp fixed.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo "creating program\n"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SILENT: $(OBJS) $(NAME) 
.PHONY: all clean fclean re