#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


struct stack
{
    int top;
    int stack[STACK_LIMIT];
};

stack_t* createStack(error_t* error)
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));

    if(stack == NULL)
    {
        *error = memory_error;
        return NULL;
    }

    stack->top = -1;

    *error = no_errors;

    return stack;
}

error_t pop(stack_t* stack, element* elem)
{
    error_t error = top(stack, elem);

    if(error == no_errors) stack->top--;

    return error;
}

error_t push(stack_t* stack, element* elem)
{   
    if(stack == NULL) return invalid_pointer;
    if(isFull(stack)) return full_stack;

    stack->top++;
    stack->stack[stack->top] = *elem;

    return no_errors;
}

error_t top(stack_t* stack, element* elem)
{
    if(stack == NULL) return invalid_pointer;
    if(isEmpty(stack)) return empty_stack;

    *elem = stack->stack[stack->top];

    return no_errors;
}

BOOL isEmpty(stack_t* stack)
{
    if(stack == NULL || stack->top == -1) return TRUE;

    return FALSE;
}

BOOL isFull(stack_t* stack)
{
    if(stack == NULL || stack->top == STACK_LIMIT) return TRUE;

    return FALSE;
}


void destroyStack(stack_t** stack)
{
    if(*stack == NULL) return;

    free(*stack);
    *stack = NULL;
}