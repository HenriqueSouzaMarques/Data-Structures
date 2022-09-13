#ifndef QUEUE_H
#define QUEUE_H

#include "errors.h"

#define BOOL char
#define TRUE 1
#define FALSE 0

#define QUEUE_SIZE 100

typedef int element;
typedef struct queue queue_t;

queue_t* createQueue(error_t* error);

error_t enqueue(queue_t* queue, element elem);
error_t dequeue(queue_t* queue, element* elem);

BOOL isEmpty(queue_t* queue);
BOOL isFull(queue_t* queue);

void destroyQueue(queue_t** queue);

#endif //QUEUE_H