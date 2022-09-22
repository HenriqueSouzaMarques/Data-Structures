#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

typedef struct node node_t;

struct node
{
    element value;
    node_t* next;
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

    if(isEmpty(list))
    {
        list->start = newNode;
    }
    else
    {
        list->end->next = newNode;
    }

    list->end = newNode;
}

void removeElement(list_t* list, element x)
{
    assert(list != NULL);

    node_t* ant = NULL;
    node_t* aux = list->start;
    node_t* prox;

    while(aux != NULL)
    {
        if(aux->value == x)
        {
            if(aux == list->start)
            {
                list->start = list->start->next;
            }
            else if(aux == list->end)
            {
                list->end = ant;
                free(aux);
                list->end->next = NULL;

                break;
            }
            else
            {
                ant->next = aux->next;
            }

            prox = aux->next;
            free(aux);
            aux = prox;
        }
        else
        {
            ant = aux;
            aux = aux->next;
        }
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
