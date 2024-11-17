#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

void Stack_print(Stack* stack) {
    if (!Stack_empty(stack)) {
        for (int i = 0; i <= stack->index; i++) {
            printf("%d, ", stack->data[i]);
        }
    }
    putchar('\n');
}

void Stack_reversed(Stack* stack) { // inverter as posicoes de numeros de uma pilha estatica
    if (Stack_empty(stack)) return;
    int aux;
    for (int i = 0; i < stack->index; i++) {
        aux = stack->data[stack->index];
        for (int j = stack->index; j > i; j--) {
            stack->data[j] = stack->data[j-1];
        }
        stack->data[i] = aux;
    }
    return;
}

bool Stack_info_igual(Stack* stack, int info) {
    for (int i = 0; i < stack->index+1; i++) {
        if (stack->data[i] == info) {
            return true;
        }
    }
    return false;
}

Stack* Stack_intersecao(Stack* stack1, Stack* stack2) {
    Stack* stack3 = stack_create();
    if (!stack1 || !stack2 || !stack3) return NULL;
    for (int i = 0; i < stack1->index+1; i++) {
        for (int j = 0; j < stack2->index+1; j++) {
            if (stack1->data[i] == stack2->data[j]) {
                if (!Stack_info_igual(stack3, stack1->data[i])){
                    Stack_push(stack3, stack1->data[i]);
                }
            }
        }
    }
    return stack3;
}