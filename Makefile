# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:44:06 by omiroshn          #+#    #+#              #
#    Updated: 2019/01/30 22:23:02 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_vm
CC = g++
FILES = Main AbstractVM FactoryMethod Exception
SRC = $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
HEADERS = -I./

FLAGS = yes
ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS	= -std=c++11 -g
	endif
	ifeq ($(FLAGS), yes)
CFLAGS	= -Wall -Wextra -Werror -std=c++11 -g
	endif
endif

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re

$(NAME): $(OBJ)
	@echo "\033[36mLinking...\033[0m"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ)
	@echo "\033[32m[ ✔ ] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
obj/%.o: src/%.cpp
	@$(CC) -o $@ $(CFLAGS) $(HEADERS) -c $^ -I src
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"
clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31mremoved. \033[0m"
fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31mremoved. \033[0m"
	@echo "\033[31m[ ✔ ] Binary \033[1;31m$(NAME) \033[1;0m\033[31mremoved.\033[0m"
re: fclean all
