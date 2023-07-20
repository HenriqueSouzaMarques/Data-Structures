#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "avl.h"

#define BOOL char
#define TRUE 1
#define FALSE 0

typedef struct node node_t;

struct node
{
    element item;
    int height;

    node_t* left;
    node_t* right;
};

struct avl
{
    node_t* root;
};


avl_t* createAVL()
{
    avl_t* p = (avl_t*)malloc(sizeof(avl_t));
    assert(p != NULL);

    p->root = NULL;

    return p;
}

void deleteAllNodes(node_t** no)
{
    if(*no != NULL)
    {
        deleteAllNodes(&(*no)->left);
        deleteAllNodes(&(*no)->right);

        free(*no);
        *no = NULL;
    }
}

void destroyAVL(avl_t** avl)
{
    if(*avl == NULL || avl == NULL) return;

    deleteAllNodes(&(*avl)->root);

    free(*avl);

    *avl = NULL;
}


BOOL isEmpty(avl_t* avl)
{
    if(avl->root == NULL) return TRUE;

    return FALSE;
}

int heightNode(node_t* no)
{
    if(no == NULL) return 0;

    int alt_esq = 1 + heightNode(no->left);
    int alt_dir = 1 + heightNode(no->right);

    if(alt_esq > alt_dir) return alt_esq;

    return alt_dir;
}

int getBalance(node_t* no)
{
    if(no == NULL) return 0;

    return heightNode(no->left) - heightNode(no->right);
}

void inOrder(node_t* no)
{
    if(no == NULL) return;

    inOrder(no->left);

    printf("%d ", no->item);

    inOrder(no->right);
}

void inOrderPrint(avl_t* avl)
{
    assert(avl != NULL);

    inOrder(avl->root);

    printf("\n");
}

node_t* nodeSearch(node_t* no, element x)
{
    if(no == NULL) return NULL;

    element elem_no = no->item;

    if(x == elem_no) return no;

    if(x < elem_no) return nodeSearch(no->left, x);

    return nodeSearch(no->right, x); 
}

element searchAVL(avl_t* avl, element x)
{
    node_t* aux = nodeSearch(avl->root, x);
    
    if(aux != NULL) return aux->item;

    return -404;
}

node_t *rrRotation(node_t *desb)
{
    node_t *aux = desb->left;

    desb->left = aux->right;

    aux->right = desb;

    return aux;
}

node_t *llRotation(node_t *desb)
{
    node_t *aux = desb->right;

    desb->right = aux->left;

    aux->left = desb;

    return aux;
}

node_t* createNode(element x)
{
    node_t* no = (node_t*)malloc(sizeof(node_t));
    assert(no != NULL);

    no->item = x;
    no->left = NULL;
    no->right = NULL;
    no->height = 1;

    return no;
}

node_t* insertNode(node_t* no, element x)
{
    if(no == NULL) return createNode(x);

    element elem_no = no->item;
    element elem_item = x;

    if(elem_item < elem_no)
    {
        no->left = insertNode(no->left, x);
    }
    else if(elem_item > elem_no)
    {
        no->right = insertNode(no->right, x);
    }
    else
    {
        printf("This element is already in the tree!\n");

        return no;
    }

    no->height = heightNode(no);

    int fb = getBalance(no);

    if(fb > 1 && elem_item < no->left->item) return rrRotation(no);

    if(fb < -1 && elem_item > no->right->item) return llRotation(no);

    if(fb > 1 && elem_item > no->left->item)
    { 
        no->left = llRotation(no->left);

        return rrRotation(no);
    }

    if(fb < -1 && elem_item < no->right->item)
    {
        no->right = rrRotation(no->right);

        return llRotation(no);
    }

    return no;
}

void insertAVL(avl_t* avl, element x)
{
    assert(avl != NULL);
    
    if(x == -404)
    {
        printf("This is an error code! You can't insert it.\n");
    }
    else
    {
        avl->root = insertNode(avl->root, x);
    }
}

element maxValue(node_t* no)
{
    while(no->right != NULL)
    {
        no = no->right;
    }

    return no->item;
}

void deleteNode(node_t** no)
{
    assert(no != NULL);

    (*no)->left = NULL;
    (*no)->right = NULL;

    free(*no);

    *no = NULL;
}

node_t* removeNode(node_t* no, element x)
{
    if(no == NULL) return no;

    element elem_no = no->item;

    if(x < elem_no) no->left =  removeNode(no->left, x);

    else if(x > elem_no) no->right = removeNode(no->right, x);

    else
    {
        if(no->left == NULL || no->right == NULL){
            node_t* filho = no->left ? no->left : no->right;

            if(filho == NULL)
            {
                filho = no;

                no = NULL;
            }
            else
            {
                no->item = filho->item;

                no->right = NULL;
                no->left = NULL;
            }

            deleteNode(&filho);
        }
        else
        {            
            element maior = maxValue(no->left);

            no->item = maior;

            no->left = removeNode(no->left, maior);
        }
    }

    if(no == NULL) return no;

    no->height = heightNode(no);

    int fb = getBalance(no);
    int fb_esq = getBalance(no->left);
    int fb_dir = getBalance(no->right);

    if(fb > 1 && fb_esq >= 0) return rrRotation(no);

    if(fb < -1 && fb_dir <= 0) return llRotation(no);

    if(fb > 1 && fb_esq < 0)
    {
        no->left = llRotation(no->left);

        return rrRotation(no);
    }

    if(fb < -1 && fb_dir > 0)
    {
        no->right = rrRotation(no->right);

        return llRotation(no);
    }

    return no;
}

void removeAVL(avl_t* avl, element x)
{
    assert(avl != NULL);

    avl->root = removeNode(avl->root, x);
}

node_t* cloneAVL(node_t* raiz)
{
    if(raiz == NULL) return NULL;

    node_t* novo_no = createNode(raiz->item);
    
    novo_no->left = cloneAVL(raiz->left);
    novo_no->right = cloneAVL(raiz->right);

    return novo_no;
}

avl_t* copyAVL(avl_t* avl)
{
    avl_t* copia = createAVL();

    copia->root = cloneAVL(avl->root);

    return copia;
}

void _concatAVL(avl_t* uniao, node_t* root)
{
    if(root == NULL) return;

    _concatAVL(uniao, root->left);
    _concatAVL(uniao, root->right);

    element elemento_atual = root->item;

    if((searchAVL(uniao, elemento_atual)) != -404) return;

    insertAVL(uniao, elemento_atual);
}

avl_t* concatAVL(avl_t* A, avl_t* B)
{
    avl_t* uniao = copyAVL(A);

    _concatAVL(uniao, B->root);

    return uniao;
}

void _insersecAVL(avl_t* intersec, node_t* raiz_a, avl_t* arvore_b)
{
    if(raiz_a == NULL) return;

    _insersecAVL(intersec, raiz_a->left, arvore_b);
    _insersecAVL(intersec, raiz_a->right, arvore_b);

    element elemento_atual = raiz_a->item;

    if((searchAVL(arvore_b, elemento_atual)) == -404) return;

    insertAVL(intersec, elemento_atual);
}

void intersecAVL(avl_t* intersec, avl_t* A, avl_t* B)
{
    _insersecAVL(intersec, A->root, B);
}