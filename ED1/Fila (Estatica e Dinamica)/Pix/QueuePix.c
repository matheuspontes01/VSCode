#include "QueuePix.h"
#include <stdlib.h>

typedef struct pixed {
    int id_orig;
    int id_dest;
    float valor;
} PixED;

struct queue {
    int qty, size, head, tail;
    PixED **data;
};

PixED* PixED_createNFill(int id_orig, int id_dest, float valor) {
    PixED* novo = malloc(sizeof(PixED));
    if(novo) {
        novo->id_orig = id_orig;
        novo->id_dest = id_dest;
        novo->valor = valor;
    }
    return novo;
}

Queue* Queue_create(int size) {
    Queue* f1 = malloc(sizeof(Queue));
    if (f1) {
        f1->data = malloc(size * sizeof(PixED*));
        if (!f1->data) {
            free(f1);
            return NULL;
        }
        f1->head = 0;
        f1->tail = 0;
        f1->qty = 0;
        f1->size = size;
    }
    return f1;
}

void Queue_destroy(Queue* f1) {
    if (f1) {
        for (int i = 0; i < f1->qty; i++) {
            free(f1->data[(f1->head + i) % f1->size]);
        }
        free(f1->data);
        free(f1);
    }
}

int Queue_enqueue(Queue* f1, int id_orig, int id_dest, float valor) {
    if (Queue_full(f1)) return 0;
    PixED* novo = PixED_createNFill(id_orig, id_dest, valor);
    if (!novo) return 0;
    f1->data[f1->tail] = novo;
    f1->tail = (f1->tail+1) % f1->size;
    f1->qty++; 
    return 1;
}

int Queue_dequeue(Queue* f1, int* id_orig, int* id_dest, float* valor) {
    if (Queue_empty(f1)) return 0;
    PixED* removed = f1->data[f1->head];
    *id_orig = removed->id_orig;
    *id_dest = removed->id_dest;
    *valor = removed->valor;
    free(removed);
    f1->head = (f1->head+1) % f1->size;
    f1->qty--;
    return 1;
}

int Queue_empty(Queue* f1) {
    return f1->qty == 0;
}

int Queue_full(Queue* f1) {
    return f1->qty == f1->size;
}