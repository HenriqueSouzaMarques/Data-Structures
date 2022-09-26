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

    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->value = x;
    newNode->next = NULL;
    newNode->previous = NULL;

    node_t* aux = list->start;
    node_t* pre = NULL;

    while(aux != NULL && x > aux->value)
    {
        pre = aux;
        aux = aux->next;
    }

    if(aux != NULL && x == aux->value)
    {
        free(newNode);
        return;
    }

    if(pre == NULL)
    {
        newNode->next = list->start;
        if(list->start != NULL)
        {
            list->start->previous = newNode;
        }
    
        list->start = newNode;
    }
    else
    {
        newNode->next = aux;
        pre->next = newNode;

        if(aux != NULL)
        {
            aux->previous = newNode;
        }
        else
        {
            list->end = newNode;
        }

        newNode->previous = pre;
    }
}

void removeElement(list_t* list, element x)
{
    assert(list != NULL);

    node_t* aux = list->start;
    node_t* pre = NULL;

    while(aux != NULL && x > aux->value)
    {
        pre = aux;
        aux = aux->next;
    }

    if(aux == NULL) return;

    if(pre == NULL)
    {
        list->start = list->start->next;

        if(list->start != NULL )
        {
            list->start->previous = NULL;
        }
        else
        {
            list->end = NULL;
        }
    }
    else
    {
        if(aux->next == NULL)
        {
            list->end = pre;
            pre->next = NULL;
        }
        else
        {
            pre->next = aux->next;
            aux->next->previous = pre;
        }
    }

    free(aux);
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
