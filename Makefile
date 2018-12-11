# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 11:44:06 by omiroshn          #+#    #+#              #
#    Updated: 2018/12/11 11:44:07 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

CC = g++
FILES = Main FactoryMethod
SRC = $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
HEADERS = -I./

FLAGS = no
ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS	=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS	=	-Wall -Wextra -Werror -std=c++11 -g
	endif
endif

OS = $(shell uname)
ifeq ($(OS), Linux)
#CGFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
else
#CGFLAGS = -lmlx -framework OpenGL -framework AppKit
#INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
#FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer
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
