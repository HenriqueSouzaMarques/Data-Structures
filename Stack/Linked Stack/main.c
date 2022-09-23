#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main()
{

    stack_t* stack = createStack();

    destroyStack(&stack);

    return EXIT_SUCCESS;
}