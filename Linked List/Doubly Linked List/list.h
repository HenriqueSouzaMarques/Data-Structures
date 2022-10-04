#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int element;
typedef struct list list_t;

list_t* createList();

/* Inserts x in the list, in crescent order */
void insert(list_t* list, element x);

/* Removes x from the list */
void removeElement(list_t* list, element x);

/* Returns true if the list is empty, otherwise returns false */
bool isEmpty(list_t* list);

/* Returns true if x is found in the list, otherwise returns false */
bool findElement(list_t* list, element x);

/* Print list in crescent order */
void printList(list_t* list);

/* Print list in decrescent order */
void printListReverse(list_t* list);

/* Deallocate the list */
void destroyList(list_t** list);

#endif //LIST_H