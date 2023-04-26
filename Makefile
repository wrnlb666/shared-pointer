CC = gcc
CFLAG = -g -Wall -Wextra -fsanitize=leak,bounds,undefined
OBJ = sp.o
LIB = 


sp: sp.c
	$(CC) $(CFLAG) $< -c

main: main.c $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $< -o $@