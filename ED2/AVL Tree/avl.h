#ifndef AVL_H
#define AVL_H
#include <stdbool.h>

typedef struct _node{
    int key, bal;
    struct _node *right, *left;
} Node;

typedef struct _tree{
    Node* root;
} AvlTree;

AvlTree* AvlTree_create();
Node* createNode(int);
void CASE_1(Node**, bool*);
void CASE_2(Node**, bool*);
int getHeight(Node*);
bool BinTree_insert(AvlTree*, int);
bool Avl_remove(AvlTree*, int);
Node* findMin(Node*);
void printInOrder(Node*);
void printPreOrder(Node*);

#endif