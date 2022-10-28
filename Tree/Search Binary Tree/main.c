#include <stdio.h>
#include <stdlib.h>

#include "search_binary_tree.h"

int main()
{
    sbt_t* tree = createTree();

    destroyTree(&tree);

    return EXIT_SUCCESS;
}