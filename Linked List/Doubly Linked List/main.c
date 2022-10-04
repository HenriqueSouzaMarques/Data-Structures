#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

int main()
{
    list_t* list = createList();

    destroyList(&list);

    return EXIT_SUCCESS;
}