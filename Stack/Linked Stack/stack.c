#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

typedef struct node node_t;

struct node
{
    element value;
    node_t* next;
};


struct stack
{
    node_t *start; node_t *end;
};

stack_t* createStack()
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    assert(stack != NULL);

    stack->start = NULL;
    stack->end = NULL;

    return stack;
}

void push(stack_t* stack, element x)
{
    assert(stack != NULL);

    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->value = x;
    newNode->next = NULL;

    if(isEmpty(stack))
    {
        stack->start = newNode;
    }
    else
    {
        stack->end->next = newNode;
    }

    stack->end = newNode;
}

element pop(stack_t* stack)
{
    assert(stack != NULL);

    element x;

    int size = getSize(stack);

    node_t* aux = stack->start;
    node_t* ant = NULL;

    x = stack->end->value;

    if(size == 1)
    {
        stack->start = stack->start->next;

        free(aux);
    }
    else
    {
        while(aux != stack->end)
        {
            ant = aux;
            aux = aux->next;
        }

        free(aux);
        stack->end = ant;
        stack->end->next = NULL;
    }

    return x;
}

bool isEmpty(stack_t* stack)
{
    assert(stack != NULL);

    if(stack->start == NULL)
    {
        return true;
    }

    return false;
}

void printStack(stack_t* stack)
{
    assert(stack != NULL);

    stack_t* stackAux = createStack();
    assert(stackAux != NULL);

    element x;
    while(!isEmpty(stack))
    {
        x = pop(stack);
        printf("%d ", x);

        push(stackAux, x);
    }
    printf("\n");

    while(!isEmpty(stackAux))
    {
        x = pop(stackAux);

        push(stack, x);
    }

    destroyStack(&stackAux);
}

void destroyStack(stack_t** stack)
{
    if(stack == NULL || *stack == NULL) return;

    node_t* aux = (*stack)->start;
    while(aux != NULL)
    {
        (*stack)->start = aux->next;
        free(aux);
        aux = (*stack)->start;
    }

    free(*stack);
}

int getSize(stack_t* stack)
{
    assert(stack != NULL);

    int size = 0;

    node_t* aux = stack->start;
    while(aux != NULL)
    {
        size++;
        aux = aux->next;
    }

    return size;
}