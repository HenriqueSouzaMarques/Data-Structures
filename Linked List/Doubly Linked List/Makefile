CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o list.o
BIN = client

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c list.h
	$(CC) -c $(FLAGS) main.c

list.o: list.c list.h
	$(CC) -c $(FLAGS) list.c

valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)
