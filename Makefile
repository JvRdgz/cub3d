
NAME			= 	cub3D

src			=	get_next_line/get_next_line_bonus.c\
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
					utils/ft_split.c\
					utils/ft_strdup.c\
					utils/ft_strjoin_char.c\
					utils/ft_strlen.c\
					utils/ft_strtrim.c\
					utils/ft_strchr.c\
					utils/ft_calloc.c\
					utils/ft_is.c\
					utils/ft_atoi.c\
					utils/utilities.c\
					utils/utilities2.c\

#######BUFF QUINES PROPORCIONADO POR @agutierr!!###########

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

#############################

FLAGS			= -Wall -Wall -Werror

GCC 			= gcc

INCLUDE			= -I includes

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
RESET			= \033[0m

all:
			@echo "${RED}[--- REMOVING a.out ---]${RESET}"
			@rm -rf cub3D
			@echo "${PURPLE}[--- COMPILING mlx ---]${RESET}"
			$(GCC) $(src) $(FLAGS) $(MLXFLAGS) -o $(NAME)
			@echo "${GREEN}[#################]"
			@echo "[ BUILD SUCCESSFUL! ]"
			@echo "[#################]${RESET}"

run0: all
	clear && ./cub3D maps/map0.cub

run1: all
	clear && ./cub3D maps/valid_hip_hop.cub

norminette:
	norminette src/* includes/* utils/*

fclean:	clean
	rm -f $(NAME)

clean :
	@echo "\033[0;31m[--- CLEANING PROJECT ---]"
	$(RM) $(OBJS)

re:				fclean all

.PHONY:	clean all
