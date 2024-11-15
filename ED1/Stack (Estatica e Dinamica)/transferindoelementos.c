#include "Stack.h"
#include <stdio.h>

int main() {
    Stack* stack = stack_create();

    int V[] = {3, 5, 9, 10};

    for (int i = 0; i < 4; i++) {
        if (!Stack_push(stack, V[i])) {
            printf("Erro ao inserir V[%d] = %d\n", i, V[i]);
        }
    }
    printf("Imprimindo os elementos da pilha 1\n");
    Stack_print(stack);

    Stack* stack2 = Stack_transfer(stack);

    printf("Deletendo os itens transferidos na pilha 2\n");
    int item;
    while (Stack_pop(stack2, &item)) {
        printf("%d, ", item);
    }
    putchar('\n');
}