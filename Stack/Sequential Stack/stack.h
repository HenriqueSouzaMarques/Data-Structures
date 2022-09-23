#ifndef STACK_H
#define STACK_H

#define STACK_LIMIT 100

#define BOOL char
#define TRUE 1
#define FALSE 0

typedef enum error
{
    /*  */
    no_errors,

    /*  */
    invalid_pointer,

    /*  */
    memory_error,

    /*  */
    empty_stack,

    /*  */
    full_stack,

} error_t;

typedef struct stack stack_t;
typedef int element;

stack_t* createStack(error_t* error);

error_t pop(stack_t* stack, element* elem);
error_t push(stack_t* stack, element* elem);
error_t top(stack_t* stack, element* elem);

BOOL isEmpty(stack_t* stack);
BOOL isFull(stack_t* stack);


void destroyStack(stack_t** stack);

#endif // STACK_H