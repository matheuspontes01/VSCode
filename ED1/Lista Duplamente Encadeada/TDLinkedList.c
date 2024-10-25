#include "TDLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox, *ant;
}TNo;

struct _list {
    TNo *inicio, *fim;
};

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->info = info;
        novo->ant = NULL;
        novo->prox = NULL;
    }
    return novo;
}

TDLinkedList* TDLinkedList_create() {
    TDLinkedList* list = malloc(sizeof(TDLinkedList));
    if (list != NULL) {
        list->inicio = NULL;
        list->fim = NULL;
    }
    return list;
}

bool TDLinkedList_insert_end(TDLinkedList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) return false;
    if (list->inicio == NULL) {
        list->inicio = novo;
        list->fim = novo;
    } else {
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
    }
    return true;
}

bool TDLinkedList_insert_begin(TDLinkedList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) return false;
    if (list->inicio == NULL) {
        list->inicio = novo;
        list->fim = novo;
    } else {
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
    }
    return true;
}

void TDLinkedList_print(TDLinkedList* list) {
    printf("Print do inicio ao fim:\n");
    TNo* aux = list->inicio;
    while (aux != NULL) {
        printf("<- %d -> ", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

void TDLinkedList_reverse_print(TDLinkedList* list) {
    printf("Print do fim ao inicio:\n");
    TNo* aux = list->fim;
    while (aux!= NULL) {
        printf(" <- %d -> ", aux->info);
        aux = aux->ant;
    }
    putchar('\n');
}

bool TDLinkedList_sorted(TDLinkedList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) return false;

    if (list->inicio == NULL) {
        list->inicio = novo;
        list->fim = novo;
    } else {
        TNo* aux = list->inicio;

        while (aux != NULL && novo->info > aux->info) {
            aux = aux->prox;
        }

        if (list->inicio == aux) { // verificar se aux esta no inicio
            novo->prox = list->inicio;
            list->inicio->ant = novo;
            list->inicio = novo;
        } else if (aux == NULL){ // verificar se aux esta no final da lista
            novo->ant = list->fim;
            list->fim->prox = novo;
            list->fim = novo;
        } else { // verificar se aux esta no intermediario da lista
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            novo->prox = aux;
            aux->ant = novo;
        }
    }
    return true;
}

bool TDLinkedList_delete_oneValue(TDLinkedList* list, int info) {
    if (list->inicio == NULL) {
        return false;
    }

    TNo* aux = list->inicio;

    while (aux != NULL && aux->info != info) {
        aux = aux->prox;
    }
    if (aux == list->inicio) {
        list->inicio = aux->prox;
        list->inicio->ant = NULL;
        free(aux);
    } else if (aux == list->fim) {
        list->fim = aux->ant;
        list->fim->prox = NULL;
        free(aux);
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
    }

    return true;
}

bool TDLinkedList_deleteList(TDLinkedList* list) {
    if (list->inicio == NULL) {
        return false;
    }

    TNo* aux = list->inicio;
    TNo* temp;
    
    while (aux != NULL) { // prestar atencao nesse detalhe, fiz errado na ultima vez, coloquei aux = aux->prox e depois atribuia pro temp e liberava temp (da erro)
        temp = aux->prox; // armazena o endereco do proximo no em temp
        free(aux); // libera o no atual
        aux = temp; // o no atual recebera o endereco do no proximo dele
    }

    list->inicio = NULL;

    return true;
}