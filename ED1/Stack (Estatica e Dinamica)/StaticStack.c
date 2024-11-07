#include "Stack.h"
#include <stdlib.h>
#define MAX 10

struct stack {
    int index; // marca a posicao do dado, (e nao a quantidade de elementos)
    int data[MAX];
};

Stack* stack_create() {
    Stack* nova = malloc(sizeof(Stack));
    if (nova) {
        nova->index = -1; // marcar que a pilha esta vazia
    }
    return nova;
}

int Stack_push(Stack* stack, int info) {
    if (!Stack_full(stack)) {
        stack->index++; // index fica 0, que vai ser o indice da alocacao do primeiro elemento
        stack->data[stack->index] = info;
        return 1;
    }
    return 0; // overflow
}

int Stack_pop(Stack* stack, int* info) { // coloca o endereco de info no parametro
    if (!Stack_empty(stack)) {
        *info = stack->data[stack->index]; // conteudo de info recebe o conteudo do dado na pilha que vai ser removido
        stack->index--;
        return 1;
    }
    return 0; // underflow
}

int Stack_head(Stack* stack, int* info) {
    if (!Stack_empty(stack)) {
        *info = stack->data[stack->index];
        return 1;
    }
    return 0;
} 

void Stack_destroy(Stack* stack) {
    free(stack);
}

int Stack_full(Stack* stack) {
    return (stack->index) == MAX-1;
}

int Stack_empty(Stack* stack) {
    return stack->index == -1;
}

int Stack_qty(Stack* stack) {
    return stack->index+1;
}