CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o search_binary_tree.o
BIN = client

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c search_binary_tree.h
	$(CC) -c $(FLAGS) main.c

search_binary_tree.o: search_binary_tree.c search_binary_tree.h
	$(CC) -c $(FLAGS) search_binary_tree.c

valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)