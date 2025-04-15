#include "BinTree.h"
#include <stdio.h>

void print_tree(BinTree* T) {
    printf("Pre: ");
    BinTree_pre(T->root);
    printf("\n");

    printf("In: ");
    BinTree_in(T->root);
    printf("\n");

    printf("Pos: ");
    BinTree_pos(T->root);
    printf("\n");
}

int main() {
    BinTree* T = BinTree_create();

    int V[] = {2, 15, 19, 4, 9, 13, 8};

    for (int i = 0; i < sizeof(V)/sizeof(int); i++) {
        if (!BinTree_insert(T, V[i])) {
            printf("Erro ao inserir V[%d] = %d\n", i, V[i]);
        }
    }

    print_tree(T);

    TNo* max = BinTree_max(T->root);
    TNo* min = BinTree_min(T->root);

    printf("Maximo: %d\n", max->key);
    printf("Minimo: %d\n", min->key);

    BinTree_delete(T, max);

    BinTree_delete(T, BinTree_search_r(T->root, 9));
    BinTree_delete(T, BinTree_search_r(T->root, 4));
    BinTree_delete(T, BinTree_search_r(T->root, 8));

    print_tree(T);
}