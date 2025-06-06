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

bool BinTree_transplant(BinTree* T, TNo* u, TNo* v) { // Substituir o subárvore enraizada no nó u pela subárvore enraizada no nó v dentro da árvore T.
    if (!T) return false; // Se a arvore e nula, retorna falso

    if (u->p == NULL) // Se o no u tem pai igual a nulo
        T->root = v; // Entao u e a raiz da arvore, logo v vira a raiz da arvore
    else if (u == u->p->left) // Se u e filho da esquerda de seu pai
        u->p->left = v; // Atualiza o ponteiro da esquerda do pai para apontar em v
    else // Caso contrario, u e filho da direita de seu pai
        u->p->right = v; // Atualiza o ponteiro da direita do pai para apontar em v

    if (v != NULL) // Caso v nao seja nulo
        v->p = u->p; // Atualiza o ponteiro para pai de v

    return true; // Transplante concluido com sucesso
}

bool BinTree_delete(BinTree* T, TNo* z) { // Remover o nó z da árvore binária de busca T.
    if (!T) return false; // Caso a arvore seja nula, entao retorna false

    if (z->left == NULL) { // Caso o no nao tem filho a esquerda (substitui pelo filho da direita) 
        BinTree_transplant(T, z, z->right);
    } else if (z->right == NULL) { // Caso o no nao tem filho a direita (substitui pelo filho da esquerda)
        BinTree_transplant(T, z, z->left);
    } else { // Caso que o no possui dois filhos
        TNo* y = BinTree_min(z->right); // Achamos o sucessor desse no
        if (y->p != z) { // Caso o sucessor nao seja filho direito de z
            BinTree_transplant(T, y, y->right); // Faça o transplante de y pelo seu filho a direita
            y->right = z->right; // Ajusta o ponteiro da direita de y para apontar para a direita de z
            y->right->p = y; // Atualiza o ponteiro do novo pai da direita de y
        } 
        BinTree_transplant(T, z, y); // Faz o transplante de z pelo y (sucessor de z) -> substitui z por y
        y->left = z->left; // Ajusta o ponteiro da esquerda de y para apontar para a esquerda de z
        y->left->p = y; // Atualiza o ponteiro do pai do novo filho esquerdo de y
    }

    return true; // Remocao concluida
}

int BinTree_count_elements(TNo* x) {
    if (x == NULL) {
        return 0;
    }

    return 1 + BinTree_count_elements(x->left) + BinTree_count_elements(x->right);
}

int BinTree_count_nonleafs(TNo* x) {
    if (x == NULL || (x->left == NULL && x->right == NULL)){
        return 0;
    }

    return 1 + BinTree_count_nonleafs(x->left) + BinTree_count_nonleafs(x->right);
}

int BinTree_count_leafs(TNo* x) {
    if (x == NULL)
        return 0;

    if (x->left == NULL && x->right == NULL)
        return 1;

    return BinTree_count_leafs(x->left) + BinTree_count_leafs(x->right);
}

int BinTree_height(TNo* x) {
    if (x == NULL) return -1;

    int hl = 0, hr = 0;

    hl = BinTree_height(x->left);
    hr = BinTree_height(x->right);

    if (hl > hr) {
        return hl + 1;
    } else {
        return hr + 1;
    }
}

void BinTree_print_odd(TNo* x) {
    if (x != NULL) {
        if (x->key % 2 != 0) {
            printf("%d, ", x->key);
        }
        BinTree_print_odd(x->left);
        BinTree_print_odd(x->right);
    }
}

int BinTree_onechild(TNo* x) {
    if (x == NULL) return 0;

    int count = 0;
    if ((x->left == NULL && x->right != NULL) || (x->left != NULL && x->right == NULL)) 
        count = 1;

    return count + BinTree_onechild(x->left) + BinTree_onechild(x->right);
}

TNo* BinTree_invert(TNo* root) {
    if (root != NULL) {
        TNo* temp = root->right;
        root->right = root->left;
        root->left = temp;

        BinTree_invert(root->left);
        BinTree_invert(root->right);
    }

    return root;
}

int BinTree_find_value(TNo* root, int key) {
    if (root == NULL) return 1;

    if (key == root->key) return 0;

    if (BinTree_find_value(root->left, key) == 0) return 0; 
    if (BinTree_find_value(root->right, key) == 0) return 0;

    return 1;
}