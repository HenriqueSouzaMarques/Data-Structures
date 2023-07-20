#ifndef _AVL_H
#define _AVL_H

typedef struct avl avl_t;
typedef int element;

avl_t* createAVL();
void destroyAVL(avl_t** avl);

void inOrderPrint(avl_t* avl);

element searchAVL(avl_t* avl, element x);

void insertAVL(avl_t* avl, element x);
void removeAVL(avl_t* avl, element x);

avl_t* concatAVL(avl_t* A, avl_t* B);

void intersecAVL(avl_t* intersec, avl_t* A, avl_t* B);

#endif