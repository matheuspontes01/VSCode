#ifndef BINTREE_H
#define BINTREE_H
#include <stdbool.h>

typedef struct _node {
    struct _node *left, *right, *p;
    int key;
} TNo;

typedef struct {
    TNo* root;
} BinTree;

BinTree* BinTree_create();

bool BinTree_insert(BinTree*, int);

TNo* BinTree_search(TNo*, int);

TNo* BinTree_search_r(TNo*, int);

void BinTree_pre(TNo*);

void BinTree_in(TNo*);

void BinTree_pos(TNo*);

TNo* BinTree_min(TNo*);

TNo* BinTree_max(TNo*);

bool BinTree_transplant(BinTree*, TNo*, TNo*);

bool BinTree_delete(BinTree*, TNo*);

#endif