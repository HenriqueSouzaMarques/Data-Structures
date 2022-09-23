#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{

    queue_t* queue = createQueue();

    destroyQueue(&queue);

    return EXIT_SUCCESS;
}