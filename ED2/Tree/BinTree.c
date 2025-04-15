#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>


BinTree* BinTree_create() {
    BinTree* T = malloc(sizeof(BinTree));
    if (T) {
        T->root = NULL;
    }

    return T;
}

TNo* TNo_createNFill(int key) {
    TNo* node = malloc(sizeof(TNo));
    if (node) {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->p = NULL;
    }

    return node;
}

bool BinTree_insert(BinTree* T, int key) {
    TNo* node = TNo_createNFill(key);
    if (!node) return false;

    TNo* x = T->root, *y = NULL;

    while (x != NULL) {
        y = x;
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->p = y;

    if (y == NULL) {
        T->root = node;
    } else {
        if (node->key < y->key) {
            y->left = node;
        } else {
            y->right = node;
        }
    }

    return true;
}

TNo* BinTree_search(TNo* x, int key) { // iterative
    while (x != NULL && x->key != key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    return x;
}

TNo* BinTree_search_r(TNo* x, int key) {
    if (!x) return NULL;

    if (x == NULL || x->key == key) {
        return x;
    }

    if (key < x->key) {
        return BinTree_search_r(x->left, key);
    } else {
        return BinTree_search_r(x->right, key);
    }
}

void BinTree_pre(TNo* root) {
    if (root) {
        printf("%d, ", root->key);
        BinTree_pre(root->left);
        BinTree_pre(root->right);
    }
}

void BinTree_in(TNo* root) {
    if (root) {
        BinTree_pre(root->left);
        printf("%d, ", root->key);
        BinTree_pre(root->right);
    }
}

void BinTree_pos(TNo* root) {
    if (root) {
        BinTree_pre(root->left);
        BinTree_pre(root->right);
        printf("%d, ", root->key);
    }
}

TNo* BinTree_min(TNo* x) {
    while (x->left != NULL) {
        x = x->left;
    }

    return x;
}

TNo* BinTree_max(TNo* x) {
    
    while (x->right != NULL) {
        x = x->right;
    }

    return x;
}

bool BinTree_transplant(BinTree* T, TNo* u, TNo* v) {
    if (!T) return false;

    if (u->p == NULL)
        T->root = v;
    else if (u == u->p->left) 
        u->p->left = v;
    else
        u->p->right = v;

    if (v != NULL)
        v->p = u->p;

    return true;
}

bool BinTree_delete(BinTree* T, TNo* z) {
    if (!T) return false;

    if (z->left == NULL) {
        BinTree_transplant(T, z, z->right);
    } else if (z->right == NULL) {
        BinTree_transplant(T, z, z->left);
    } else {
        TNo* y = BinTree_min(z->right);
        if (y->p != z) {
            BinTree_transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        } 
        BinTree_transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }

    return true;
}
