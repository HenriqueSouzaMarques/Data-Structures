CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o binary_tree.o
BIN = client

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c binary_tree.h
	$(CC) -c $(FLAGS) main.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) -c $(FLAGS) binary_tree.c

valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)