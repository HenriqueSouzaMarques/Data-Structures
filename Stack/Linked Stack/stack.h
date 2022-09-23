#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int element;
typedef struct stack stack_t;

stack_t* createStack();

void push(stack_t* stack, element x);

element pop(stack_t* list);

bool isEmpty(stack_t* stack);

int getSize(stack_t* stack);

void printStack(stack_t* stack);

void destroyStack(stack_t** stack);

#endif //STACK_H