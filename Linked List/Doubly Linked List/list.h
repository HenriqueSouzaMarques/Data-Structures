#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int element;
typedef struct list list_t;

list_t* createList();

void insert(list_t* list, element x);

void removeElement(list_t* list, element x);

bool isEmpty(list_t* list);

bool findElement(list_t* list, element x);

void printList(list_t* list);

void printListReverse(list_t* list);

void destroyList(list_t** list);

#endif //LIST_H