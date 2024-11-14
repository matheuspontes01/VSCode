#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Obs.: Utilizar as funcoes de DynamicStack.c

// **Tentar fazer sem utilizar outra pilha para trocar os numeros de lugares

// Invertendo os lugares de cada numero da pilha
int main() {
    Stack* stack = stack_create();
    int V[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        if(!Stack_push(stack, V[i])) {
            printf("Nao foi possível inserir V[%d] = %d\n", i, V[i]);
        }
    }
    
    Stack* stack2 = stack_create();
    int item;
    printf("Removendo elementos da pilha 1 e inserindo na pilha 2\n");
    while (Stack_pop(stack, &item)) {
        printf("%d\n", item);
        Stack_push(stack2, item);
    }
    printf("Removendo elementos da pilha 2 com os elementos invertidos\n");
    while(Stack_pop(stack2, &item)) {
        printf("%d\n", item);
    }
}