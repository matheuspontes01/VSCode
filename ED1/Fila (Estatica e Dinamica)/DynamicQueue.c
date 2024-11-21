#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no{
    int info;
    struct _no *prox;
} TNo;

struct queue{
    TNo* end;
    int qty;
};

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo) {
        novo->info = info;
        novo->prox = novo;
    }
    return novo;
}

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

    fila->end = NULL; // para indicar que a lista esta vazia
    fila->qty = 0;
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

int Queue_tail(Queue* fila, int* info) {
    if(Queue_empty(fila)) return 0;
    *info = fila->end->info;
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
        TNo* aux = fila->end->prox; // inicio
        do {
            printf("%d, ", aux->info);
            aux = aux->prox;
        } while (aux != fila->end->prox);
        putchar('\n');
    }
}

Queue* Queue_reverse(Queue* f1) {
    Queue* f2 = Queue_create();
    if(!f2 || !f1) return NULL;
    int temp, i = 0;
    TNo* aux = f1->end;
    do {
        TNo* percorre = f1->end->prox;
        while (percorre->prox != aux) {
            percorre = percorre->prox;
        }
        Queue_enqueue(f2, aux->info);
        aux = percorre;
        i++;
    } while (i != Queue_qty(f1));

    return f2;
}

bool Queue_remove_negative_numbers(Queue* f1) { // nao sei o que deu de errado aq
    if (Queue_empty(f1)) return false;
    TNo* aux = f1->end->prox;
    TNo* anterior = f1->end;
    do {
        if (aux->info < 0) {
            if (aux == f1->end->prox) {
                TNo* oldBegin = aux;
                anterior->prox = oldBegin->prox;
                f1->end->prox = oldBegin->prox;
                aux = oldBegin->prox;
                free(oldBegin);
            } else if (aux == f1->end) {
                TNo* oldEnd = aux;
                anterior->prox = oldEnd->prox;
                f1->end = anterior;
                aux = oldEnd->prox;
                free(oldEnd);
            } else {
                TNo* temp = aux;
                anterior->prox = temp->prox;
                aux = temp->prox;
                free(temp);
            }

            f1->qty--;

            if (Queue_qty(f1) == 0) {
                printf("lista vazia.\n");
                f1->end = NULL;
                break;
            }

        } else {
            anterior = aux;
            aux = aux->prox;
        }
    } while (f1->end && aux != f1->end->prox);

    return true;
}

bool Queue_sorted(Queue* f1, int info) { // revisar dps
    TNo* novo = TNo_createNFill(info);
    if (!novo) return false;

    if (f1->end == NULL) {
        novo->prox = novo;
        f1->end = novo;
    } else {
        TNo* aux = f1->end->prox; 
        TNo* anterior = f1->end;

        do {
            if (novo->info < aux->info) break;  
            anterior = aux;
            aux = aux->prox;
        } while (aux != f1->end->prox);

        anterior->prox = novo;
        novo->prox = aux;

        if (aux == f1->end->prox && novo->info >= anterior->info) {
            f1->end = novo;
        }
    }
    f1->qty++;
    return true;
}

bool Queue_fill_queue(Queue* f1, Queue* f2, Queue* f3) { // nao sei o que de errado aq 
    if (Queue_empty(f1) || Queue_empty(f2)) return false;
    int temp;
    while (Queue_dequeue(f1, &temp)){
        Queue_sorted(f3, temp);
    }

    while (Queue_dequeue(f2, &temp)){
        Queue_sorted(f3, temp);
    }

    return true;
}

bool Queue_concatenate(Queue* f1, Queue* f2) { // nao sei oq esta acontecendo
    if (Queue_empty(f1) || Queue_empty(f2)) return false;

    int temp;
    while (Queue_dequeue(f2, &temp)) {
        printf("Dequeued from f2: %d\n", temp);
        Queue_enqueue(f1, temp);
    }

    printf("Checar se f2 esta vazia: \n");
    Queue_print(f2);

    return true;
}