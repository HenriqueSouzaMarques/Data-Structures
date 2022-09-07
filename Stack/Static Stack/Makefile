CC = gcc
FLAGS = -g -std=c99 -Wall -Werror

OBJECTS = main.o stack.o

client: $(OBJECTS)
	$(CC) -o client $(FLAGS) $(OBJECTS)

main.o: main.c stack.h
	$(CC) -c $(FLAGS) main.c

stack.o: stack.c stack.h
	$(CC) -c $(FLAGS) stack.c

clean: 
	rm *.o client