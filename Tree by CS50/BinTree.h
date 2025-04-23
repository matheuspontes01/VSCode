#ifndef BINTREE_H
#define BINTREE_H
#include <stdbool.h>

typedef struct _no {
    struct _no *p;
    struct _no *left;
    struct _no *right;
    int key;
} Node;

typedef struct _bin {
    Node* root;
} BinTree;

BinTree* BinTree_create();

bool BinTree_insert(BinTree*, int);

Node* BinTree_search(Node*, int);

Node* BinTree_search_r(Node*, int);

void BinTree_pre(Node*);

void BinTree_in(Node*);

void BinTree_pos(Node*);

Node* BinTree_min(Node*);

Node* BinTree_max(Node*);

bool BinTree_transplant(BinTree*, Node*, Node*);

bool BinTree_delete(BinTree*, Node*);


#endif