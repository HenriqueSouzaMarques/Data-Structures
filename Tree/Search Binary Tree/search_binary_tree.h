#ifndef SEARCH_BINARY_TREE_H
#define SEARCH_BINARY_TREE_H

#include <stdbool.h>
#include <assert.h>

typedef struct searchBinaryTree sbt_t;
typedef int element;

sbt_t* createTree();

bool isEmpty(sbt_t* tree);

bool insertElement(sbt_t* tree, element x);

bool searchElement(sbt_t* tree, element x);

bool deleteElement(sbt_t* tree, element deletedElement);

int heightTree(sbt_t* tree);

void printTree(sbt_t* tree);

void destroyTree(sbt_t** tree);

#endif // SEARCH_BINARY_TREE_H