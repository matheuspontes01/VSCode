#include "TDLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no{
    int info;
    struct _no *prox, *ant;
} TNo;

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
        } else { // verificar se aux esta no meio/intermediario da lista
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            novo->prox = aux;
            aux->ant = novo;
        }
    }
    return true;
}

bool TDLinkedList_sorted_decrescente(TDLinkedList* list, int info) {
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
        } else { // verificar se aux esta no meio/intermediario da lista
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            novo->prox = aux;
            aux->ant = novo;
        }
    }
    return true;
}

TDLinkedList* TDLinkedList_ordem_caracteres(TDLinkedList* list, TDLinkedList* list_letras, TDLinkedList* list_num) {
    if (!list->inicio) return NULL;
    TNo* aux = list->inicio;
    // verificar se o caractere é uma letra
    do {
        if ((aux->info >= 'A' && aux->info <= 'Z')) {
            TDLinkedList_sorted(list_letras, aux->info);
        } else {
            TDLinkedList_sorted_decrescente(list_num, aux->info);
        }
        aux = aux->prox;
    } while (aux != NULL);

    TDLinkedList* list2 = TDLinkedList_concatenar(list_letras, list_num);
    return list2;
}

void TDLinkedList_print(TDLinkedList* list) {
    printf("Print do inicio ao fim:\n");
    TNo* aux = list->inicio;
    while (aux != NULL) {
        if ((aux->info >= 'A' && aux->info <= 'Z')) {
            printf("<- %c -> ", aux->info);
        } else {
            printf("<- %d -> ", aux->info);
        }
        aux = aux->prox;
    }
    putchar('\n');
}

TDLinkedList* TDLinkedList_concatenar(TDLinkedList* list1, TDLinkedList* list2) {
    TDLinkedList* list3 = TDLinkedList_create();
    if (!list3 || !list1->inicio) return list2;
    if (!list3 || !list2->inicio) return list3;

    TNo* fim = list1->inicio;
    while (fim != NULL) {
        TDLinkedList_insert_end(list3, fim->info);
        fim = fim->prox;
    }
    fim = list2->inicio;

    while (fim != NULL) {
        TDLinkedList_insert_end(list3, fim->info);
        fim = fim->prox;
    }

    return list3;
}