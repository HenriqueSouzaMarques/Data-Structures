#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int main()
{
    /*  Using stack to convert "n" decimal to binary:  */
    int n = 120;

    int currentBit;

    error_t error;

    stack_t* stack = createStack(&error);

    if(error == no_errors)
    {
        while(n != 0)
        {   
            currentBit = n % 2;
            push(stack, &currentBit);
            n /= 2;
        }

        while(!isEmpty(stack))
        {
            pop(stack, &currentBit);
            printf("%d", currentBit);
        }
        printf("\n");
    }

    destroyStack(&stack);

    return EXIT_SUCCESS;
}