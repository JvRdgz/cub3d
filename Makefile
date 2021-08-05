# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 20:56:03 by jarodrig          #+#    #+#              #
#    Updated: 2021/08/05 20:48:12 by jarodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3D

SRC		=	get_next_line/get_next_line.c\
			src/main.c\
			src/file_processor.c\
			src/file_processor_aux.c\
			src/check_re_cardinals.c\
			src/ceil_floor.c\
			src/get_map_reads.c\
			src/get_map_reads_aux.c\
			src/parse.c\
			src/exit.c\
			src/floor_sky_draw.c\
			src/init_raycast.c\
			src/raycasting.c\
			src/rc_wall.c\
			src/keyboard.c\
			src/events.c\
			src/load_texture.c\
			src/init_params.c\
			src/utils.c\
			src/init_params_aux.c\
			src/sprites.c\
			src/sprites_casting.c\
			src/screenshoot.c\
			utils/ft_strdup_utils.c\
			utils/ft_strjoin_char.c\
			utils/ft_is.c\
			utils/utilities.c\
			utils/utilities_aux.c\

# LIBOBJ	=	./libft/*.o
LIBFT_DIR = libft
LIBS = libft/libft.a

OBJ		=	$(SRC:.c=.o)

OBJS	=	./*.o

NAME_DIR	=	./cub3D

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

FLAGS	=	-Wall -Wall -Werror -g

CC	=		gcc

INCLUDE	=	includes

RED		=	\033[0;31m
BLUE	=	\033[0;34m
GREEN	=	\033[0;32m
RESET	=	\033[0m

all:	$(NAME)

$(LIBS):
	@echo ""
	@echo "${BLUE}[--- COMPILING libft ---]${RESET}"
	@echo ""
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(LIBS) $(OBJ)
	@echo "${BLUE}[--- REMOVING old cub3d ---]${RESET}"
	@echo ""
	@rm -rf cub3D
	@echo "${BLUE}[--- COMPILING cub3d ---]${RESET}"
	@echo ""
	@$(CC) $(SRC) $(FLAGS) $(MLXFLAGS) -Llibft -lft -o $(NAME)
	#@ar rc $(NAME) $(OBJ)
	@echo "${GREEN}[--- BUILD SUCCESSFUL! ---]"
	@echo ""

run0: all
	clear && ./cub3D maps/map.cub

ifeq ($(detected_OS),Darwin)
norminette:
	norminette src/* includes/* utils/*
endif

clean :
	@echo "${GREEN}[--- REMOVING OBJ ---]${RESET}"
	@rm -rf $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	@echo "${GREEN}[--- REMOVING cub3d ---]${RESET}"
	@rm -f $(NAME_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:	clean all
