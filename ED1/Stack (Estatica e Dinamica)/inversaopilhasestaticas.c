#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack* stack = stack_create();
    int V[] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++) {
        if(!Stack_push(stack, V[i]))
            printf("Nao foi possivel inserir V[%d] = %d\n", i, V[i]);
    }
    printf("Imprimindo uma pilha em sua posicao normal: \n");
    int item;
    while (Stack_pop(stack, &item)) {
        printf("%d \n", item);
    }

    for (int i = 0; i < 4; i++) {
        if(!Stack_push(stack, V[i]))
            printf("Nao foi possivel inserir V[%d] = %d\n", i, V[i]);
    }

    Stack_reversed(stack);
    
    printf("Imprimindo pilha invertida: \n");
    while (Stack_pop(stack, &item)) {
        printf("%d \n", item);
    }
}