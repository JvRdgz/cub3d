#!bin/bash

clang -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11 && ./a.out
