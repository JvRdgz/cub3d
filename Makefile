# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 20:56:03 by jarodrig          #+#    #+#              #
#    Updated: 2021/01/17 15:39:19 by jarodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3D

SRC		=	./src/get_next_line_bonus.c\
			./src/main.c\
			./src/read.c\
			./src/raycast.c\
			./utils/get_next_line_utils_bonus.c\

LIBOBJS	=	libft/*.o

OBJS	=	$(SRC:.c=.o)

####### DETECCION DE S.O. PROPORCIONADO POR @agutierr!! ###########

# Sistema Windows
ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif
# Sistema MAC OS
ifeq ($(detected_OS),Darwin)
	MLXFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
endif
# Sistema GNU Linux
ifeq ($(detected_OS),Linux)
	MLXFLAGS = -lm -lbsd -lmlx -lXext -lX11
endif

############### COMPILADORES SEGUN S.O. #####################

FLAGS	=	-Wall -Wall -Werror
ifeq ($(detected_OS),Linux)
	GCC	=	clang
endif
ifeq ($(detected_OS),Darwin)
	GCC	=	gcc
endif

INCLUDE	=	-I includes

RED		=	\033[0;31m
PURPLE	=	\033[0;35m
GREEN	=	\033[1;32m
RESET	=	\033[0m

lib:
	@$(MAKE) -C ./libft all

$(NAME):	lib
	@echo "${RED}[#################]"
	@echo "${RED}[--- REMOVING a.out ---]${RESET}"
	@rm -rf cub3D
	@echo "${RED}[#################]"
	@echo "${PURPLE}[#################]"
	@echo "${PURPLE}[--- COMPILING mlx ---]${RESET}"
	@$(GCC) $(FLAGS) -c $(SRC) $(INCLUDE) $(MLXFLAGS)
	@ar rc $(NAME) $(OBJS) $(LIBOBJS)
	@echo "${PURPLE}[#################]"
	@echo "${GREEN}[#################]"
	@echo "[--- BUILD SUCCESSFUL! ---]"
	@echo "[#################]${RESET}"

all:	$(NAME)

#run0: all
#	clear && ./cub3D maps/map.cub

#run1: all
#	clear && ./cub3D maps/valid_hip_hop.cub
ifeq ($(detected_OS),Darwin)
norminette:
	norminette src/* includes/* utils/*
endif

clean :
	@echo "\033[0;31m[--- REMOVING OBJS ---]"
	@rm -f $(OBJS)
	@$(MAKE) -C ./libft clean

fclean:	clean
	@echo "\033[0;31m[--- REMOVING cub3D ---]"
	@rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

re:	fclean all

.PHONY:	clean all
