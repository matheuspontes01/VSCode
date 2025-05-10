#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void print_tree(AvlTree* T) {
    printf("Pre: \n");
    printPreOrder(T->root);
    printf("\n");

    printf("Inorder: \n");
    printInOrder(T->root);
    printf("\n");
}

int main() {
    AvlTree* T = AvlTree_create();
    if (!T) {
        printf("Erro ao criar arvore!\n");
        free(T);
        return 1;
    }

    int V[] = {10, 20, 15, 5, 1, 12, 25, 30};

    for (int i = 0; i < 8; i++) {
        if (!BinTree_insert(T, V[i])) {
            printf("Erro ao inserir o valor V[%d] = %d\n", i, V[i]);
        }
    }
    print_tree(T);

    if (Avl_remove(T, 15)) {
        printf("No removido\n");
    } else {
        printf("No nao removido\n");
    }

    print_tree(T);
}