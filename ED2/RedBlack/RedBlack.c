#include "RedBlack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Color:
// 0 - Black
// 1 - Red

RedBlack* RedBlack_createTree() {
    RedBlack* T = malloc(sizeof(RedBlack));
    T->nil = malloc(sizeof(Node));
    T->nil->color = 0;
    T->nil->left = T->nil;
    T->nil->right = T->nil;
    T->nil->p = T->nil;
    T->root = T->nil;
    return T;
}

Node* createNode(RedBlack* T, int key) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->left = T->nil;
        node->right = T->nil;
        node->p = T->nil;
        node->color = 1;
        node->key = key;
    }
    return node;
}

void RedBlack_insert(RedBlack* T, int key) {
    Node* node = createNode(T, key);
    if (!node) {
        free(node);
        return;
    }

    Node* x = T->root, *y = T->nil;
    while (x != T->nil) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }  
    node->p = y;

    if (y == T->nil) {
        T->root = node;
    } else if (node->key < y->key){
        y->left = node;
    } else {
        y->right = node;
    }
    node->left = T->nil;
    node->right = T->nil;
    node->color =  1;

    RedBlack_insertFixUp(T, node);
}

void RedBlack_insertFixUp(RedBlack* T, Node* z) {
    while (z->p->color == 1) {
        if (z->p == z->p->p->left) {
            Node* y = z->p->p->right;
            if (y->color == 1) {
                z->p->color = 0;
                y->color = 0;
                z->p->p->color = 1;
                z = z->p->p;
            } else {
                if (z == z->p->right) {
                    z = z->p;
                    left_rotate(T, z);
                }
                z->p->color = 0;
                z->p->p->color = 1;
                right_rotate(T, z->p->p);
            }
        } else {
            Node* y = z->p->p->left;
            if (y->color == 1) {
                z->p->color = 0;
                y->color = 0;
                z->p->p->color = 1;
                z = z->p->p;
            } else {
                if (z == z->p->left) {
                    z = z->p;
                    right_rotate(T, z);
                }
                z->p->color = 0;
                z->p->p->color = 1;
                left_rotate(T, z->p->p);
            }
        }

        // Se z chegou na raiz, para evitar acesso inválido
        if (z == T->root)
            break;
    }
    T->root->color = 0;
}


void left_rotate(RedBlack* T, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != T->nil) {
        y->left->p = x;
    }
    y->p = x->p;
    
    if (x->p == T->nil) {
        T->root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    y->left = x;
    x->p = y;
}

void right_rotate(RedBlack* T, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != T->nil) {
        x->right->p = y;
    }
    x->p = y->p;

    if (y->p == T->nil) {
        T->root = x;
    } else if (y == y->p->right) {
        y->p->right = x;
    } else {
        y->p->left = x;
    }

    x->right = y;
    y->p = x;
}

void RedBlack_pre(RedBlack* T, Node* root) {
    if (root != T->nil) {
        printf("%d  |  %d\n", root->key, root->color);
        RedBlack_pre(T, root->left);
        RedBlack_pre(T, root->right);
    }
}

void RedBlack_in(RedBlack* T, Node* root) {
    if (root != T->nil) {
        RedBlack_pre(T, root->left);
        printf("%d  |  %d\n", root->key, root->color);
        RedBlack_pre(T, root->right);
    }
}