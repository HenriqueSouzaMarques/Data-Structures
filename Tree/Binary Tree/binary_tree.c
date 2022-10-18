#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

typedef struct node node_t;

struct node
{
    element value;
    node_t* rightChild;
    node_t* leftChild;
};


struct binaryTree
{
    node_t* root;
};


binary_tree_t* createTree()
{
    binary_tree_t* newTree = (binary_tree_t*)malloc(sizeof(binary_tree_t));
    assert(newTree != NULL);

    newTree->root = NULL;

    return newTree;
}


bool isEmpty(binary_tree_t* tree)
{
    assert(tree != NULL);

    return(tree->root == NULL);
}


node_t* _searchElement(node_t* root, element x)
{
    if(root == NULL) return NULL;

    if(root->value == x) return root;

    node_t* searched = _searchElement(root->leftChild, x);
    if(searched == NULL)
    {
        searched = _searchElement(root->rightChild, x);
    }

    return searched;
}

bool searchElement(binary_tree_t* tree, element x)
{
    assert(tree != NULL);

    node_t* searched = _searchElement(tree->root, x);

    return (searched != NULL);
}


node_t* _searchFather(node_t* root, element x)
{
    if(root == NULL) return NULL;

    if(root->leftChild != NULL && root->leftChild->value == x)
    {
        return root;
    }
    
    if(root->rightChild != NULL && root->rightChild->value == x)
    {
        return root;   
    }
    
    node_t* searched = _searchFather(root->leftChild, x);
    if(searched == NULL)
    {
        searched = _searchFather(root->rightChild, x);
    }

    return searched;
}

element searchFather(binary_tree_t* tree, element x)
{
    assert(tree != NULL);

    node_t* searched = _searchFather(tree->root, x);
    if(searched == NULL) return -404;

    return searched->value;
}


bool insertRoot(binary_tree_t* tree, element root)
{
    if(!isEmpty(tree)) return false;

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = root;

    tree->root = newNode;

    return true;
}

bool insertRight(binary_tree_t* tree, element father, element rightChild)
{
    if(searchElement(tree, rightChild)) return false;

    node_t* fatherNode = _searchElement(tree->root, father);

    if(fatherNode == NULL || fatherNode->rightChild != NULL) return false;

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->value = rightChild;

    fatherNode->rightChild = newNode;

    return true;
}

bool insertLeft(binary_tree_t* tree, element father, element leftChild)
{
    if(searchElement(tree, leftChild)) return false;

    node_t* fatherNode = _searchElement(tree->root, father);

    if(fatherNode == NULL || fatherNode->leftChild != NULL) return false;

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->leftChild = NULL;
    newNode->leftChild = NULL;
    newNode->value = leftChild;

    fatherNode->leftChild = newNode;

    return true;
}

bool _deleteElement(binary_tree_t* tree, element deletedElement)
{
    node_t* father, *aux;
    bool isLeft;

    /* First Step: find where's the node we want to delete */
    if(tree->root != NULL && tree->root->value == deletedElement)
    {
        father = NULL;
        aux = tree->root;
    }
    else
    {
        father = _searchFather(tree->root, deletedElement);
        if(father != NULL)
        {
            if(father->leftChild != NULL && father->leftChild->value == deletedElement)
            {
                isLeft = true;
                aux = father->leftChild;
            }
            else
            {
                isLeft = false;
                aux = father->rightChild;
            }
        }
        else
        {
            return false;
        }
    }


    /* Second Step: delete it properly */
    if(aux->leftChild == NULL && aux->rightChild == NULL)
    {
        if(father == NULL)
        {
            tree->root = NULL;
        }
        else
        {
            if(isLeft) father->leftChild = NULL;
            else father->rightChild = NULL;
        }

        free(aux);
        return true;
    }
    else
    {
        if(aux->leftChild != NULL)
        {
            aux->value = aux->leftChild->value;
            aux->leftChild->value = deletedElement;
        }
        else
        {
            aux->value = aux->rightChild->value;
            aux->rightChild->value = deletedElement;
        }

        return _deleteElement(tree, deletedElement);
    }
}

bool deleteElement(binary_tree_t* tree, element deletedElement)
{
    assert(tree != NULL);

    return _deleteElement(tree, deletedElement);
}

int _heightTree(node_t* root)
{
    if(root == NULL) return 0;

    int heightLeft = 1 + _heightTree(root->leftChild);
    int heightRight = 1 + _heightTree(root->rightChild);

    if(heightLeft > heightRight) return heightLeft;

    return heightRight;
}

int heightTree(binary_tree_t* tree)
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

void printTree(binary_tree_t* tree)
{
    assert(tree != NULL);

    if(tree->root == NULL) return;

    _printTree(tree->root);
    
    printf("\n");
}

void _destroyTree(node_t** root)
{
    if(*root == NULL) return;

    _destroyTree(&(*root)->leftChild);
    _destroyTree(&(*root)->rightChild);

    free(*root);
    *root = NULL;
}

void destroyTree(binary_tree_t** tree)
{
    if(tree == NULL || *tree == NULL) return;

    _destroyTree(&(*tree)->root);

    free(*tree);

    *tree = NULL;
}