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
    } else { // na fila, o elemento e inserido no final da fila
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

void Queue_print(Queue* fila) { // ok
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

Queue* Queue_reverse(Queue* f1) { // ok
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

<<<<<<< HEAD
bool Queue_remove_negative_numbers(Queue* f1) { // ok
    if (Queue_empty(f1)) return false;

=======
bool Queue_remove_negative_numbers(Queue* f1) { // nao sei o que deu de errado aq
    if (Queue_empty(f1)) return false;
>>>>>>> a227b1f86fc1c67ccb11fe440ef0b614a429fdf3
    TNo* aux = f1->end->prox;
    TNo* anterior = f1->end;

    do {
        if (aux->info < 0) { // preciso que aux continue percorrendo a fila, que seja um no dps do no anterior
            if (aux == f1->end->prox) {
                f1->end->prox = aux->prox;
                free(aux);
                aux = f1->end->prox;
            } else if (aux == f1->end) { 
                anterior->prox = aux->prox; 
                free(aux);
                f1->end = anterior; 
                aux = anterior->prox; 
            } else { 
                TNo* temp = aux;
                anterior->prox = aux->prox; 
                aux = aux->prox; 
                free(temp);
            }

            f1->qty--; 

            if (f1->qty == 0) {
                f1->end = NULL; 
                break;
            }
        } else { 
            anterior = aux;
            aux = aux->prox;
        }
    } while (aux != f1->end->prox); 

    return true;
}

<<<<<<< HEAD
bool Queue_sorted(Queue* f1, int info) { // ok
=======
bool Queue_sorted(Queue* f1, int info) { // revisar dps
>>>>>>> a227b1f86fc1c67ccb11fe440ef0b614a429fdf3
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

<<<<<<< HEAD
        if (aux == f1->end->prox) {
            novo->prox = f1->end->prox;
            f1->end->prox = novo;
        } else if (aux == f1->end) {
            anterior->prox = novo;
            novo->prox = f1->end;
        } else {
            novo->prox = aux; // aq pode ocorre tambem caso novo->info seja a maior informacao tbm
            anterior->prox = novo;
=======
        anterior->prox = novo;
        novo->prox = aux;

        if (aux == f1->end->prox && novo->info >= anterior->info) {
            f1->end = novo;
>>>>>>> a227b1f86fc1c67ccb11fe440ef0b614a429fdf3
        }
    }
    f1->qty++;
    return true;
}

<<<<<<< HEAD
bool Queue_fill_queue(Queue* f1, Queue* f2, Queue* f3) { // nao sei pq deu errado aq 
=======
bool Queue_fill_queue(Queue* f1, Queue* f2, Queue* f3) { // nao sei o que de errado aq 
>>>>>>> a227b1f86fc1c67ccb11fe440ef0b614a429fdf3
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

<<<<<<< HEAD
bool Queue_concatenate(Queue* f1, Queue* f2) { // nao sei pq deu errado aq
    if (!f1 || !f2) return false;

    int temp;

    while (!Queue_empty(f2)) {
        Queue_dequeue(f2, &temp);
        Queue_enqueue(f1, temp);
    }
    f2->end = NULL;

    return true;
}

void Queue_compare_size(Queue* f1, Queue* f2) { // ok
    if (Queue_qty(f1) == Queue_qty(f2)) {
        printf("A fila 1 e fila 2 sao iguais\n");
    } else if (Queue_qty(f1) > Queue_qty(f2)) {
        printf("A fila 1 e maior que a fila 2\n");
    } else {
        printf("A fila 2 e maior que a fila 1\n");
    }
}

void Queue_pares_e_impares(Queue* f1) { // ok
    int pares = 0, impares = 0;
    TNo* aux = f1->end->prox;
    do {
        if (aux->info % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
        aux = aux->prox;
    } while (aux != f1->end->prox);

    printf("Quantidade de pares da fila: %d\n", pares);
    printf("Quantidade de impares da fila: %d\n", impares);
}

void Queue_media(Queue* f1) { //ok
    if (Queue_empty(f1)) return;

    float media = 0;
    int maior, menor; // caso nao tenha valor negativo na fila, colocar igual a 0 nessas duas variaveis
    TNo* aux1 = f1->end->prox;

    maior = menor = aux1->info;
    do {
        media += aux1->info;

        if (aux1->info > maior) {
            maior = aux1->info;
        } 
        if (aux1->info < menor) {
            menor = aux1->info;
        }

        aux1 = aux1->prox;
    } while (aux1 != f1->end->prox);
    media /= Queue_qty(f1);
    printf("Media aritmetica dos elementos presentes na fila: %.2f\n", media);
    printf("Maior elemento da fila: %d\n", maior);
    printf("Menor elemento da fila: %d\n", menor);
}   

Queue* queue_intercalar(Queue* f1, Queue* f2) {
    if (Queue_empty(f2)) return f1;
    if (Queue_empty(f1)) return f2;
    Queue* f3 = Queue_create();
    if (!f3) return NULL;

    TNo* aux1 = f1->end->prox;
    TNo* aux2 = f2->end->prox;

    bool intercalando = true;
    do {
        if (intercalando && aux1) {
            Queue_enqueue(f3, aux1->info);
            aux1 = aux1->prox;
            if (aux1 == f1->end->prox) {
                aux1 = NULL;
            }
        }
        if (!intercalando && aux2) {
            Queue_enqueue(f3, aux2->info);
            aux2 = aux2->prox;
            if (aux2 == f2->end->prox) {
                aux2 = NULL;
            }
        }
        intercalando = !intercalando;
    } while (aux1 != NULL || aux2 != NULL);

    return f3;
=======
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
>>>>>>> a227b1f86fc1c67ccb11fe440ef0b614a429fdf3
}