# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 20:56:03 by jarodrig          #+#    #+#              #
#    Updated: 2021/07/18 15:00:24 by jarodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3d

SRC		=	get_next_line/get_next_line.c\
			src/main.c\
			src/file_procesator.c\
			src/file_procesator2.c\
			src/check_nd_save.c\
			src/ceil_floor.c\
			src/get_map_reads.c\
			src/get_map_reads2.c\
			src/parse.c\
			src/create_and_clean.c\
			src/floor_sky_draw.c\
			src/init_raycast.c\
			src/raycasting.c\
			src/rc_wall.c\
			src/keyboard.c\
			src/handle_events.c\
			src/load_texture.c\
			src/init_params.c\
			src/utils.c\
			src/init_params2.c\
			src/sprites.c\
			src/sprites_casting.c\
			src/screenshoot.c\
			utils/ft_strdup_utils.c\
			utils/ft_strjoin_char.c\
			utils/ft_is.c\
			utils/utilities.c\
			utils/utilities2.c\

# LIBOBJ	=	./libft/*.o
LIBFT_DIR = libft
LIBS = libft/libft.a

OBJ		=	$(SRC:.c=.o)

OBJS	=	./*.o

NAME_DIR	=	./cub3d

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
	@rm -rf cub3d
	@echo "${BLUE}[--- COMPILING cub3d ---]${RESET}"
	@echo ""
	@$(CC) $(SRC) $(FLAGS) $(MLXFLAGS) -Llibft -lft -o $(NAME)
	#@ar rc $(NAME) $(OBJ)
	@echo "${GREEN}[--- BUILD SUCCESSFUL! ---]"
	@echo ""

#run0: all
#	clear && ./cub3d maps/map.cub

#run1: all
#	clear && ./cub3d maps/valid_hip_hop.cub
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
