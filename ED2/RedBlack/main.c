#include "RedBlack.h"
#include <stdlib.h>
#include <stdio.h>

void print_Tree(RedBlack* T) {
    printf("Pre:\n");
    printf(" KEY  |  COLOR  \n");
    RedBlack_pre(T, T->root);

    printf("In:\n");
    printf(" KEY  |  COLOR  \n");
    RedBlack_in(T, T->root);
}

int main() {
    RedBlack* T = RedBlack_createTree();
    if (!T) {
        printf("Erro ao criar a arvore!\n");
        free(T);
        return 1;
    }

    int V[10] = {28, 30, 1, 5, 13, 8, 25, 12, 6, 2};

    for (int i = 0; i < 10; i++) {
        RedBlack_insert(T, V[i]);
    }

    print_Tree(T);

    printf("Altura da arvore: %d\n", RedBlack_height_start(T));
}