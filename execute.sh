#!bin/bash

# clang ./src/get_next_line_bonus.c ./src/main.c \
#	./src/raycast.c ./src/read.c ./utils/get_nest_line_utils_bonus.c \
#	-lbsd -lmlx -lXext -lX11 && ./a.out ./maps/elpepe.txt

# gcc ./src/*.c ./utils/*.c ./includes/cub3d.h \
#	-lmlx -lXext -lX11 && ./a.out && rm -rf ./includes/*.gch

make fclean && make && ./cub3d
