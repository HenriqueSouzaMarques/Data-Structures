#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <assert.h>

typedef struct binaryTree binary_tree_t;
typedef int element;

binary_tree_t* createTree();

bool isEmpty(binary_tree_t* tree);

bool insertRoot(binary_tree_t* tree, element root);
bool insertRight(binary_tree_t* tree, element father, element rightChild);
bool insertLeft(binary_tree_t* tree, element father, element leftChild);

bool searchElement(binary_tree_t* tree, element x);
element searchFather(binary_tree_t* tree, element x);

bool deleteElement(binary_tree_t* tree, element deletedElement);

int heightTree(binary_tree_t* tree);

void printTree(binary_tree_t* tree);

void destroyTree(binary_tree_t** tree);

#endif // BINARY_TREE_H