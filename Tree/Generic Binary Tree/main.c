#include <stdio.h>
#include <stdlib.h>

#include"binary_tree.h"

int main()
{
    binary_tree_t* tree = createTree();

    destroyTree(&tree);

    return EXIT_SUCCESS;
}