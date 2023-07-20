#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main()
{
    avl_t* avl = createAVL();
    
    destroyAVL(&avl);

    return EXIT_SUCCESS;
}