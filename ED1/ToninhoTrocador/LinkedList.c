#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int id;
    float valor;
    int id_prox;
    struct _no *prox;
} TNo;

struct _list {
    TNo* inicio;
};

TNo* TNo_createNFill(int id, float valor, int id_prox) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo) {
        novo->id = id;
        novo->valor = valor;
        novo->id_prox = id_prox;
        novo->prox = NULL;
    }
    return novo;
}

TLinkedList* TLinkedList_create() {
    TLinkedList* nova = malloc(sizeof(TLinkedList));
    if (nova) {
        nova->inicio = NULL;
    }
    return nova;
}

bool TLinkedList_insert_end(TLinkedList* list, int id, float valor, int id_prox) {
    TNo* novo = TNo_createNFill(id, valor, id_prox);
    if (!novo) return false;

    if (list->inicio == NULL) {
        list->inicio = novo;
    } else {
        TNo* aux = list->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return true;
}

void TLinkedList_Toninho(TLinkedList* list) {
    TNo* aux = list->inicio; // vai passar pela lista para imprimir os valores de cada no
    do {
        TNo* aux2 = list->inicio; // vai procurar o proximo no
        printf("%.1f,", aux->valor);
        if (aux->id_prox == 0) break;
        while (aux2->id != aux->id_prox) {
            aux2 = aux2->prox;
        }
        aux = aux2;
    } while (1);
}