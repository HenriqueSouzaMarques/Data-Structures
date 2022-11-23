#include <stdio.h>
#include <stdlib.h>

#include "search_binary_tree.h"

typedef struct node node_t;

struct node
{
    element value;
    node_t* rightChild;
    node_t* leftChild;
};


struct searchBinaryTree
{
    node_t* root;
};


sbt_t* createTree()
{
    sbt_t* newTree = (sbt_t*)malloc(sizeof(sbt_t));
    assert(newTree != NULL);

    newTree->root = NULL;

    return newTree;
}


bool isEmpty(sbt_t* tree)
{
    assert(tree != NULL);

    return(tree->root == NULL);
}


node_t* _searchElement(node_t* root, element x)
{
    if(root == NULL) return NULL;

    if(x < root->value) return _searchElement(root->leftChild, x);

    if(x > root->value) return _searchElement(root->rightChild, x);

    return root;
}

bool searchElement(sbt_t* tree, element x)
{
    assert(tree != NULL);

    node_t* searched = _searchElement(tree->root, x);

    return (searched != NULL);
}

bool _insertElement(node_t** root, element x)
{
    if(*root == NULL)
    {
        *root = (node_t*)malloc(sizeof(node_t));
        assert(*root != NULL);

        (*root)->leftChild = NULL;
        (*root)->rightChild = NULL;
        (*root)->value = x;

        return true;
    }

    if(x < (*root)->value) return _insertElement(&((*root)->leftChild), x);

    if(x > (*root)->value) return _insertElement(&((*root)->rightChild), x);

    return false;
}

bool insertElement(sbt_t* tree, element x)
{
    assert(tree != NULL);

    return _insertElement(&(tree->root), x);
}

bool _deleteElement(node_t** root, element deletedElement)
{
    if(*root == NULL || root == NULL) return false;

    if(deletedElement == (*root)->value)
    {
        if((*root)->leftChild == NULL && (*root)->rightChild == NULL) /* Removind a leaf */
        {
            free(*root);
            *root = NULL;
        }
        else if((*root)->leftChild == NULL) /* Removing when node has the left child */
        {
            node_t* aux = *root;
            *root = (*root)->rightChild;

            free(aux);
        }
        else if((*root)->rightChild == NULL) /* Removing when node has the right child */
        {
            node_t* aux = *root;
            *root = (*root)->leftChild;

            free(aux);
        }
        else /* Removing when node has both children */
        {
            node_t* aux = (*root)->leftChild;
            
            while(aux->rightChild != NULL && aux->rightChild->value > aux->value)
            {
                aux = aux->rightChild;
            }

            (*root)->value = aux->value;
            aux->value = deletedElement;

            return _deleteElement(&(*root)->leftChild, deletedElement); 
        }

        return true;
    }
    else if(deletedElement > (*root)->value)
    {
        return _deleteElement(&(*root)->rightChild, deletedElement);
    }

    return _deleteElement(&(*root)->leftChild, deletedElement); 

}

bool deleteElement(sbt_t* tree, element deletedElement)
{
    assert(tree != NULL);

    return _deleteElement(&(tree->root), deletedElement);
}

int _heightTree(node_t* root)
{
    if(root == NULL) return 0;

    int heightLeft = 1 + _heightTree(root->leftChild);
    int heightRight = 1 + _heightTree(root->rightChild);

    if(heightLeft > heightRight) return heightLeft;

    return heightRight;
}

int heightTree(sbt_t* tree)
{
    assert(tree != NULL);

    return _heightTree(tree->root);
}

void _printTree(node_t* root)
{
    if(root == NULL)
    {
        printf("_");
    }
    else
    {
        printf("%d(", root->value);
        _printTree(root->leftChild);
        printf(",");
        _printTree(root->rightChild);
        printf(")");
    }
}

void printTree(sbt_t* tree)
{
    assert(tree != NULL);

    if(tree->root == NULL) return;

    _printTree(tree->root);
    
    printf("\n");
}

void _destroyTree(node_t** root)
{
    if(root == NULL || *root == NULL) return;

    _destroyTree(&(*root)->leftChild);
    _destroyTree(&(*root)->rightChild);

    free(*root);
    *root = NULL;
}

void destroyTree(sbt_t** tree)
{
    if(tree == NULL || *tree == NULL) return;

    _destroyTree(&(*tree)->root);

    free(*tree);

    *tree = NULL;
}