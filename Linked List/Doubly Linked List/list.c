#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

typedef struct node node_t;

struct node
{
    element value;
    node_t* next, *previous;
};


struct list
{
    node_t *start; node_t *end;
};

list_t* createList()
{
    list_t* list = (list_t*)malloc(sizeof(list_t));
    assert(list != NULL);

    list->start = NULL;
    list->end = NULL;

    return list;
}

void insert(list_t* list, element x)
{
    assert(list != NULL);

    /* Only new elements can be added */
    if(findElement(list, x)) return;

    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->value = x;
    newNode->next = NULL;
    newNode->previous = NULL;

    node_t* aux = list->start;

    while(aux != NULL && x > aux->value)
    {
        aux = aux->next;
    }

    if(list->start == NULL) // adding the new node in a empty list
    {
        list->start = newNode;
        list->end = newNode;
    }
    else if(aux == list->start) // adding the new node at the beginning of the list
    {
        newNode->next = list->start;
        list->start->previous = newNode;
        list->start = newNode;
    }
    else if(aux == NULL) // adding the new node at the end of the list
    {
        newNode->previous = list->end;
        list->end->next = newNode;
        list->end = newNode;
    }
    else // adding the new node between two other nodes
    {
        aux->previous->next = newNode;
        newNode->previous = aux->previous;

        aux->previous = newNode;
        newNode->next = aux;
    }
}

void removeElement(list_t* list, element x)
{
    assert(list != NULL);

    node_t* aux = list->start;

    while(aux != NULL && x > aux->value)
    {
        aux = aux->next;
    }

    if(aux == NULL) return;

    if(aux->value == x)
    {
        if(aux == list->start) // removing from the beginning of the list
        {
            if(aux == list->end)
            {
                list->start = NULL;
                list->end = NULL;
            }
            else
            {
                list->start = aux->next;
                list->start->previous = NULL;
            }
        }
        else if(aux == list->end) // removing from the end at the list
        {
            list->end = aux->previous;
            list->end->next = NULL;
        }
        else // removing a node in between two other nodes
        {
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
        }
        free(aux);
    }
}

bool isEmpty(list_t* list)
{
    assert(list != NULL);

    if(list->start == NULL)
    {
        return true;
    }

    return false;
}

bool findElement(list_t* list, element x)
{
    assert(list != NULL);

    node_t* aux = list->start;
    while(aux != NULL)
    {
        if(aux->value == x) return true;

        if(aux->value > x) break;

        aux = aux->next;
    }

    return false;
}

void printList(list_t* list)
{
    assert(list != NULL);

    node_t* aux = list->start;
    while(aux != NULL)
    {
        printf("%d ", aux->value);
        
        aux = aux->next;
    }
    printf("\n");
}

void printListReverse(list_t* list)
{
    assert(list != NULL);

    node_t* aux = list->end;
    while(aux != NULL)
    {
        printf("%d ", aux->value);
        
        aux = aux->previous;
    }
    printf("\n");
}

void destroyList(list_t** list)
{
    if(list == NULL || *list == NULL) return;

    node_t* aux = (*list)->start;
    while(aux != NULL)
    {
        (*list)->start = aux->next;
        free(aux);
        aux = (*list)->start;
    }

    free(*list);
}
