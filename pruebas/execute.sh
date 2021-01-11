#!bin/bash

clang main.c -lbsd -lmlx -lXext -lX11 && ./a.out
