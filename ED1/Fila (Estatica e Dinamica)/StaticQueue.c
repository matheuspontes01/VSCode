#include "Queue.h"
#include <stdlib.h>
#define MAX 5

struct queue{
    int qty, head, tail;
    int data[MAX];
};

Queue* Queue_create() {
    Queue* nova = malloc(sizeof(Queue));
    if (nova) {
        nova->qty = 0;
        nova->head = 0;
        nova->tail = 0;
    } return nova;
}

void Queue_destroy(Queue* fila) {
    free(fila);
}

int Queue_enqueue(Queue* fila, int info) {
    if (Queue_full(fila)) return 0;
    fila->data[fila->tail] = info;
    fila->tail = (fila->tail + 1) % MAX;
    fila->qty++;
    return 1;
}

int Queue_dequeue(Queue* fila, int* info) {
    if (Queue_empty(fila)) return 0;
    *info = fila->data[fila->head];
    fila->head = (fila->head+1) % MAX;
    fila->qty--;
    return 1;
}

int Queue_head(Queue* fila, int* info) {
    if (Queue_empty(fila)) return 0;
    *info = fila->data[fila->head];
    return 1;
}

int Queue_full(Queue* fila) {
    return fila->qty == MAX;
}

int Queue_empty(Queue* fila) {
    return fila->qty == 0;
}

int Queue_qty(Queue* fila) {
    return fila->qty;
}

// O operador modulo é utilizado para garantir que, ao incrementar os ponteiros
// tail e head, eles "voltem ao inicio" ao atingir o limite da 
// capacidade maxima (MAX). Isso é fundamental para evitar que os
// ponteiros saiam do intervalo valido do array que representa a fila.

// A fila circular trata o final da estrutura como conectado ao inicio
// formando um ciclo logico. Assim, o proximo indice apos a ultima
// posicao volta ao indice 0.