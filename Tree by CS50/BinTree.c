#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* BinTree_create() {
    BinTree *T = malloc(sizeof(BinTree));
    if (T) {
        T->root = NULL;
    }

    return T;
}

Node* Node_create(int key) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->p = NULL;
        node->left = NULL;
        node->right = NULL;
        node->key = key;
    }

    return node;
}

bool BinTree_insert(BinTree* T, int key) {
    Node* node = Node_create(key);
    if (!node) return false;

    Node* x = T->root, *y = NULL;

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
    } else if (key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }

    return true;
}

Node* BinTree_search(Node* root, int key) {
    Node* x = root;
    while (x != NULL && x->key != key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

Node* BinTree_search_r(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return BinTree_search(root->left, key);
    } else {
        return BinTree_search(root->right, key);
    }
}

void BinTree_pre(Node* x) {
    if (x) {
        printf("%d, ", x->key);
        BinTree_pre(x->left);
        BinTree_pre(x->right);
    }
}

void BinTree_in(Node* x) {
    if (x) {
        BinTree_in(x->left);
        printf("%d, ", x->key);
        BinTree_in(x->right);
    }
}

void BinTree_pos(Node* x) {
    if (x) {
        BinTree_pos(x->left);
        BinTree_pos(x->right);
        printf("%d, ", x->key);
    }
}

Node* BinTree_min(Node* x) {
    while (x->left != NULL) {
        x = x->left;
    }

    return x;
}

Node* BinTree_max(Node* x) {
    while (x->right != NULL) {
        x = x->right;
    }

    return x;
}

bool BinTree_transplant(BinTree* T, Node* u, Node* v) {
    if (T == NULL) return false;

    if (u->p == NULL) {
        T->root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else if (u == u->p->right) {
        u->p->right = v;
    }

    if (v != NULL) {
        v->p = u->p;
    }

    return true;
}

bool BinTree_delete(BinTree* T, Node* u) {
    if (T == NULL) return false;

    if (u->left == NULL) {
        BinTree_transplant(T, u, u->right);
    } else if (u->right == NULL) {
        BinTree_transplant(T, u, u->left);
    } else {
        Node* y = BinTree_min(u->right);
        if (y->p != u) {
            BinTree_transplant(T, y, y->right);
            y->right = u->right;
            y->right->p = y;
        }
        BinTree_transplant(T, u, y);
        y->left = u->left;
        y->left->p = y;
    }

    return true;
}

void print_tree(BinTree* T) {
    printf("Pre: ");
    BinTree_pre(T->root);
}

int main() {
    int V[6] = {2, 10, 5, 7, 6, 15};
    BinTree* T = BinTree_create();
    if (!T) {
        printf("Erro ao criar a arvore!\n");
        return 1;
    }

    for (int i = 0; i < 6; i++) {
        if (!BinTree_insert(T, V[i])) {
            printf("Nao foi possivel inserir V[%d] = %d\n", i, V[i]);
        }
    }

    print_tree(T);
    printf("\n");

    Node* node_remove = BinTree_search(T->root, 7);

    BinTree_delete(T, node_remove);

    print_tree(T);
    printf("\n");

    Node* min = BinTree_min(T->root);
    Node* max = BinTree_max(T->root);

    printf("min: %d\n", min->key);
    printf("max: %d\n", max->key);

    Node* node_remove2 = BinTree_search(T->root, 15);
    Node* node_remove3 = BinTree_search(T->root, 10);

    BinTree_delete(T, node_remove2);
    BinTree_delete(T, node_remove3);

    print_tree(T);
    printf("\n");
}