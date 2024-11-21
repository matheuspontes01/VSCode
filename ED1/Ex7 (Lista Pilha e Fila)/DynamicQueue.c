#include "Queue.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

struct queue{
    TNo* end;
    int qty;
};

Queue* Queue_create() {
    Queue* nova = malloc(sizeof(Queue));
    if (nova) {
        nova->end = NULL;
        nova->qty = 0;
    } return nova;
}

void Queue_destroy(Queue* fila) { // fazer dps
    if (fila->end == NULL) return;

    TNo* aux = fila->end->prox;
    TNo* temp;
    
    do {
        temp = aux->prox;
        free(aux);
        aux = temp;
    } while (aux != fila->end->prox);
    
    // Como é uma lista circular, nao possui nó com NULL, causando loop infinito
    // Entao, nossa condicao de parada deve ser no ponto inicial, quando aux for novamente igual a fila->end->prox
    free(aux);
    fila->end = NULL; // para indicar que a lista esta vazia
    fila->qty = 0;
    free(fila);
}

int Queue_enqueue(Queue* fila, int info) {
    TNo* novo = TNo_createNFill(info);
    if(!novo) return 0;
    if(fila->end == NULL) {
        fila->end = novo;
    } else {
        novo->prox = fila->end->prox;
        fila->end->prox = novo;
        fila->end = novo;
    } 
    fila->qty++;
    return 1;
}

int Queue_dequeue(Queue* fila, int* info) {
    if(Queue_empty(fila)) return 0;
    TNo* oldBegin = fila->end->prox;
    *info = oldBegin->info;
    fila->end->prox = oldBegin->prox;
    free(oldBegin);
    fila->qty--;
    return 1;
}

int Queue_head(Queue* fila, int* info) {
    if(Queue_empty(fila)) return 0;
    TNo* oldBegin = fila->end->prox;
    *info = oldBegin->info;
    return 1;
}

int Queue_full(Queue* fila) {
    return 0;
}

int Queue_empty(Queue* fila) {
    return fila->end == NULL;
}

int Queue_qty(Queue* fila) {
    return fila->qty;
}

void Queue_print(Queue* fila) {
    if (fila->end == NULL) {
        printf("Lista vazia\n");
    } else {
        TNo* aux = fila->end->prox;
        do {
            printf("%d, ", aux->info);
            aux = aux->prox;
        } while (aux != fila->end->prox);
        putchar('\n');
    }
}