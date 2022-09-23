CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o queue.o
BIN = client

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJECTS)

main.o: main.c queue.h
	$(CC) -c $(FLAGS) main.c

queue.o: queue.c queue.h
	$(CC) -c $(FLAGS) queue.c

valgrind: 
	valgrind ./$(BIN)

clean: 
	rm *.o $(BIN)
