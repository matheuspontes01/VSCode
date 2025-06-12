#ifndef REDBLACK_H
#define REDBLACK_H
#include <stdbool.h>

// Color:
// 0 - Black
// 1 - Red

typedef struct _node {
    struct _node *left, *right, *p;
    int color, key;
} Node;


typedef struct _tree {
    Node* root;
    Node* nil;
} RedBlack;

RedBlack* RedBlack_createTree();
Node* createNode(RedBlack*, int);
void RedBlack_insert(RedBlack*, int);
void left_rotate(RedBlack*, Node*);
void right_rotate(RedBlack*, Node*);
void RedBlack_insertFixUp(RedBlack*, Node*);
void RedBlack_pre(RedBlack*, Node*);
void RedBlack_in(RedBlack*, Node*);
int RedBlack_Height(RedBlack*, Node*);
int RedBlack_height_start(RedBlack*);
Node* RedBlack_min(RedBlack*, Node*);
void RedBlack_transplant(RedBlack*, Node*, Node*);
void RedBlack_delete(RedBlack*, Node*);
void RedBlack_delete_FixUp(RedBlack*, Node*);

#endif