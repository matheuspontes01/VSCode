#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no{
    int info;
    struct _no *prox;
} TNo;

struct stack{
    TNo* inicio;
    int qty;
};

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo) {
        novo->info = info;
        novo->prox = NULL; 
    }
    return novo;
}

Stack* stack_create() {
    Stack* nova = malloc(sizeof(Stack));
    if (nova) {
        nova->inicio = NULL;
        nova->qty = 0;
    }
    return nova;
}

int Stack_push(Stack* stack, int info) {
    TNo* novo = TNo_createNFill(info);
    if (!novo) return 0; //overflow
    novo->prox = stack->inicio;
    stack->inicio = novo;
    stack->qty++;
    return 1;
}

int Stack_pop(Stack* stack, int* info) {
    if (!Stack_empty(stack)) {
        *info = stack->inicio->info;
        TNo* aux = stack->inicio;
        stack->inicio = stack->inicio->prox;
        free(aux);
        stack->qty--;
        return 1;
    }
    return 0;
}

int Stack_head(Stack* stack, int* info) {
    if (!Stack_empty(stack)) {
        *info = stack->inicio->info;
        return 1;
    }
    return 0;
}

void Stack_destroy(Stack* stack) { // feito por mim (deu certo)
    TNo* aux = stack->inicio;
    TNo* temp;
    while (aux != NULL) {
        temp = aux->prox;
        free(aux);
        aux = temp;
    }
    stack->inicio = NULL;
}

int Stack_full(Stack* stack) { // ficara cheio se passar do limite da memoria alocavel do sistema computacional
    return 0;
}

int Stack_empty(Stack* stack) {
    return stack->qty == 0;
}

int Stack_qty(Stack* stack) {
    return stack->qty;
}

void Stack_print(Stack* stack) { // feito por mim
    if (stack->inicio == NULL) {
        printf("Lista vazia.\n");
    }
    TNo* aux = stack->inicio;
    while (aux != NULL) {
        printf("%d, ", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

bool Stack_element_equals(Stack* stack, int info) {
    if (Stack_empty(stack)) return false;
    TNo* aux = stack->inicio;
    while (aux != NULL) {
        if (aux->info == info) {
            return true;
        }
    }
    return false;
}

int Stack_equals(Stack* stack1, Stack* stack2) {
    TNo* aux1 = stack1->inicio;
    TNo* aux2 = stack2->inicio;

    while (aux1 != NULL || aux2 != NULL) {
        if (aux1->info != aux2->info) {
            printf("As listas nao sao iguais\n");
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    
    if (aux1 == NULL && aux2 == NULL) {
        printf("As listas sao iguais\n");
        return 1;
    } else {
        printf("As listas nao sao iguais.\n");
        return 0;
    }
}
