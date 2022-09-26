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

    if(isEmpty(list))
    {
        list->start = newNode;
        list->end = newNode;
    }
    else
    {
        node_t* aux = list->start;
        while(aux != NULL)
        {
            element actual = aux->value;

            if(actual > x)
            {
                newNode->next = aux;

                if(aux == list->start)
                {
                    list->start = newNode;
                    aux->previous = newNode;
                }
                else
                {
                    node_t* previous = aux->previous;
                    previous->next = newNode;
                    newNode->previous = previous;
                }

                break;
            }
            
            if(actual == x)
            {
                free(newNode);
                break;
            }

            if(aux == list->end)
            {
                aux->next = newNode;
                newNode->previous = aux;
                list->end = newNode;
                break;
            }

            aux = aux->next;
        }
    }
}

void removeElement(list_t* list, element x)
{
    assert(list != NULL);

    node_t* aux = list->start;
    while(aux != NULL)
    {
        if(aux->value == x)
        {
            if(aux == list->start)
            {
                list->start = aux->next;
                list->start->previous = NULL;
            }
            else if(aux == list->end)
            {
                list->end = list->end->previous;
                list->end->next = NULL;
            }           
            else
            {
                node_t* ant = aux->previous;
                node_t* prox = aux->next;

                ant->next = prox;
                prox->previous = ant;
            }

            free(aux);
            break;
        }

        aux = aux->next;
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
