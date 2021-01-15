
NAME			= 	cub3D

SRC			=		src/get_next_line_bonus.c\
					src/main.c\
					src/read.c\
					utils/get_next_line_utils_bonus.c\

LIBOBJS			=		libft/*.o

####### DETECCION DE SO PROPORCIONADO POR @agutierr!! ###########

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

############### COMPILADORES SEGUN SO. #####################

FLAGS			= -Wall -Wall -Werror
ifeq ($(detected_OS),Linux)
        GCC		= clang
endif
ifeq ($(detected_OS),Darwin)
        GCC		= gcc
endif

INCLUDE			= -I includes

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
RESET			= \033[0m

lib:
			@$(MAKE) -C libft all

all:
			@echo "${RED}[--- REMOVING a.out ---]${RESET}"
			@rm -rf cub3D

			@echo "${PURPLE}[--- COMPILING mlx ---]${RESET}"
			lib $(GCC) $(SRC) $(FLAGS) $(MLXFLAGS) -o $(NAME)

			@echo "${GREEN}[#################]"

			@echo "[ BUILD SUCCESSFUL! ]"
			@echo "[#################]${RESET}"

run0: all
	clear && ./cub3D maps/map.cub

#run1: all
#	clear && ./cub3D maps/valid_hip_hop.cub
ifeq ($(detected_OS),Darwin)
norminette:
	norminette src/* includes/* utils/*
endif

fclean:	clean
	rm -f $(NAME)

clean :
	@echo "\033[0;31m[--- CLEANING PROJECT ---]"
	$(RM) $(OBJS) $(LIBOBJS)

re:				fclean all

.PHONY:	clean all
