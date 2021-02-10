#!bin/bash

clang main2.c -lmlx -lXext -lX11 && ./a.out
clang main2.c && ./a.out
