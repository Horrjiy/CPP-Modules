# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 14:40:55 by mpoplow           #+#    #+#              #
#    Updated: 2025/06/18 12:22:40 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++17
NAME		:= replace

SRCS		= main.cpp replace_in_file.cpp test.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo "creating program"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

notxt:
	@echo "remove all .txt and .txt.replace files"
	@rm -f *.txt
	@rm -f *.txt.replace

fcleantxt: fclean notxt
	
.SILENT: $(OBJS) $(NAME) 
.PHONY: all clean fclean re notxt fcleantxt