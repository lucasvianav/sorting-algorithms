all:
	gcc -g3 -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -Wall -Werror -std=c99 main.c -o sort

run:
	./sort
