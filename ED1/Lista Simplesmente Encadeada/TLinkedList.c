#include "TLinkedList.h"
#include <stdio.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo *inicio;
};

TNo *TNoCreate_NFill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if (novo != NULL){
        novo->info = info;
        novo->prox = NULL;
    }
    return novo; 
}

TLinkedList* TLinkedList_create(){
    TLinkedList *list = malloc(sizeof(list));
    if (list != NULL){
        list->inicio = NULL;
    }
    return list;
}

bool TLinkedList_insert_begin(TLinkedList* list, int info){
    TNo* novo = TNoCreate_NFill(info);
    if (novo == NULL) return false;
    if (list->inicio != NULL){
        novo->prox = list->inicio;
    }
    list->inicio = novo;
}

bool TLinkedList_insert_end(TLinkedList* list, int info){
    TNo* novo = TNoCreate_NFill(info);
    if (novo == NULL) return false;
    if (list->inicio == NULL){
        list->inicio == novo;
    }
    else
    {
        TNo* aux = list->inicio;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        list->inicio = aux;
    }
}

void TLinkedList_print(TLinkedList* list){
    TNo* aux = list->inicio;
    while (aux != NULL){
        printf("%d, ", aux->info);
        aux = aux->prox;
    }
    putchar("\n");
}