CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o avl.o
BIN = main

all: $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c avl.h
	$(CC) -c $(FLAGS) main.c

avl.o: avl.c avl.h
	$(CC) -c $(FLAGS) avl.c
 
valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)

run:
	./$(BIN)