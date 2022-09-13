#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "error.h"

int main()
{
    error_t error;
    element x;

    queue_t* queue = createQueue(&error);

    if(error == no_errors)
    {
        for(int i = 0; i < 20; ++i)
        {
            enqueue(queue, i);
        }

        for(int i = 0; i < 20; ++i)
        {
            dequeue(queue, &x);
            printf("%d ", x);
        }
        printf("\n");
    }

    destroyQueue(&queue);
    
    return EXIT_SUCCESS;
}