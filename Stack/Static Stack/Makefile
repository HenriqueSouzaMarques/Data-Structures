CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o stack.o
BIN = client

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c stack.h
	$(CC) -c $(FLAGS) main.c

stack.o: stack.c stack.h
	$(CC) -c $(FLAGS) stack.c

valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)
