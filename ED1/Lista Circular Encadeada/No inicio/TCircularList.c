#include "TCircularList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no *prox;
}TNo;

struct tcirc_list {
    TNo* inicio;
};

TCircularList* TCircularList_Create() {
    TCircularList* list = malloc(sizeof(TNo));
    if (list != NULL) {
        list->inicio = NULL;
    }
    return list;
}

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}

bool TCircularList_insert(TCircularList* list, int info) { // inserir no inicio
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) {
        return false;
    }
    if (list->inicio == NULL) {
        list->inicio = novo;
        list->inicio->prox = list->inicio; //Ou... novo->prox = novo;
    } else {
        TNo* aux = list->inicio;
        while (aux->prox != list->inicio) { // Percorrer a lista até achar o ultimo elemento
            aux = aux->prox;
        }
        aux->prox = novo; // Último elemento passa a apontar para o novo nó
        novo->prox = list->inicio; // Próximo de novo deve apontar para o início
        list->inicio = novo; // Início passa a apontar para o novo nó
    }
    return true;
}

bool TCircularList_insert_end(TCircularList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) {
        return false;
    }
    if (list->inicio == NULL) {
        list->inicio = novo;
        list->inicio->prox = list->inicio;
    } else {
        TNo* aux = list->inicio;
        while (aux->prox != list->inicio) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = list->inicio;
    }
    return true;
}

void TCircularList_print(TCircularList* list) {
    if (list->inicio == NULL) {
        return;
    }
    TNo* aux = list->inicio;
    do {
        printf("%d, ", aux->info);
        aux = aux->prox;
    } while (aux != list->inicio);
    putchar('\n');
}

bool TCircularList_sorted(TCircularList* list, int M) {
    if (list->inicio == NULL) {
        return false;
    }

    TNo* atual = list->inicio;
    TNo* anterior = NULL;

    while (atual->prox != atual) { // Continua até restar um nó

        // Mover até o M-ésimo nó
        for (int i = 1; i < M; i++) {
            anterior = atual;
            atual = atual->prox;
        }

        // Eliminar o M-ésimo nó
        anterior->prox = atual->prox;
        free(atual);
        atual = anterior->prox; // Avança para o próximo nó
    }

    // O último nó restante é o sobrevivente
    list->inicio = atual;
    return true;
}

void TCircularList_print_Resposta(TCircularList* list) {
    if (list->inicio == NULL) {
        return;
    }
    TNo* aux = list->inicio;
    do {
        printf("%d ", aux->info);
        aux = aux->prox;
    } while (aux != list->inicio);
    putchar('\n');
}

bool TCircularList_delete(TCircularList* list, int info) {
    if (list->inicio == NULL) {
        return false;
    }

    TNo* aux = list->inicio;
    TNo* anterior = NULL;

    if (list->inicio->info == info) {
        while (aux->prox != list->inicio) {
            aux = aux->prox;
        }
        TNo* fim = aux;

        if (list->inicio == list->inicio->prox) {
            free(list->inicio);
            list->inicio = NULL;
        } else {
            fim->prox = list->inicio->prox;
            aux = list->inicio;
            list->inicio = list->inicio->prox;
            free(aux);
        }
        return true;
    }

    aux = list->inicio;
    do {
        anterior = aux;
        aux = aux->prox;

        if (aux->info == info) {
            anterior->prox = aux->prox;
            free(aux);
            return true;
        }
    } while (aux != list->inicio);

    return false;
}

void TCircularList_deleteList(TCircularList* list) {
    if (list->inicio == NULL) {
        return;
    }

    TNo* aux = list->inicio;
    TNo* temp;

    do {
        temp = aux->prox;
        free(aux);
        aux = temp;
    } while (aux != list->inicio);

    list->inicio = NULL;
}