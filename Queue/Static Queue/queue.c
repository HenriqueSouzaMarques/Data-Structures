#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "errors.h"

struct queue
{
    int start;
    int end;
    int totalElem;
    element elemVector[QUEUE_SIZE];
};


queue_t* createQueue(error_t* error)
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));

    if(queue == NULL)
    {
        *error = memory_error;
        return NULL;
    }

    queue->start = 0;
    queue->end = 0;
    queue->totalElem = 0;

    *error = no_errors;

    return queue;
}

error_t enqueue(queue_t* queue, element elem)
{
    if(queue == NULL) return invalid_pointer;

    if(isFull(queue)) return full_queue;

    queue->elemVector[queue->end] = elem;

    queue->end = (queue->end + 1) % QUEUE_SIZE;

    queue->totalElem++;

    return no_errors;
}



error_t dequeue(queue_t* queue, element* elem)
{
    if(queue == NULL) return invalid_pointer;

    if(isEmpty(queue)) return empty_queue;

    *elem = queue->elemVector[queue->start];

    queue->start = (queue->start + 1) % QUEUE_SIZE;

    queue->totalElem--;

    return no_errors;
}

BOOL isEmpty(queue_t* queue)
{
    if(queue == NULL || queue->totalElem == 0) 
    {
        return TRUE;
    }

    return FALSE;
}


BOOL isFull(queue_t* queue)
{
    if(queue == NULL || queue->totalElem == QUEUE_SIZE) 
    {
        return TRUE;
    }

    return FALSE;
}

void destroyQueue(queue_t** queue)
{
    if(queue != NULL && *queue != NULL)
    {
        free(*queue);
        *queue = NULL;
    }
}