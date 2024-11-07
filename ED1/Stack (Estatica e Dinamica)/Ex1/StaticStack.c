#include "StaticStack.h"
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct stack {
    int index; // marca a posicao do dado, (e nao a quantidade de elementos)
    char* data[MAX];
};

Stack* stack_create() {
    Stack* nova = malloc(sizeof(Stack));
    if (nova) {
        nova->index = -1; // marcar que a pilha esta vazia
    }
    return nova;
}

int Stack_push(Stack* stack, char* info) {
    if (!Stack_full(stack)) {
        stack->index++; // index fica 0, que vai ser o indice da alocacao do primeiro elemento
        stack->data[stack->index] = malloc(strlen(info) + 1);
        if (stack->data[stack->index] == NULL) {
            return 0;
        }
        strcpy(stack->data[stack->index], info);
        return 1;
    }
    return 0;
}

int Stack_full(Stack* stack) {
    return stack->index == MAX-1;
}

int Stack_empty(Stack* stack) {
    return stack->index == -1;
}

int Stack_pop(Stack* stack, char* info) { // coloca o endereco de info no parametro
    if (!Stack_empty(stack)) {
        strcpy(info, stack->data[stack->index]);
        free(stack->data[stack->index]);
        stack->index--;
        return 1;
    }
    return 0; // underflow
}