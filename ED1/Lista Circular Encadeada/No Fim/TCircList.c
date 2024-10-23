//
// Created by User on 10/17/2024.
//

#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int info;
    struct _no *prox;
}TNo;

struct tcirc_list {
    TNo* fim;
};

TCircList* TCircList_create() {
    TCircList* list = malloc(sizeof(TCircList));
    if (list == NULL) {
        printf("Erro ao alocar na memoria.");
        free(list);
        return NULL;
    } else {
        list->fim = NULL;
    }
    return list;
}

TNo* TNo_createNFill(int info) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->info = info;
        novo->prox = NULL;
    } else {
        free(novo);
        return NULL;
    }
    return novo;
}

bool TCircList_insert_begin(TCircList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) {
        return false;
    }
    if (list->fim == NULL) {
        list->fim = novo;
        list->fim->prox = list->fim;
    } else {
        novo->prox = list->fim->prox;
        list->fim->prox = novo;
    }
    return true;
}

bool TCircList_insert_end(TCircList* list, int info) {
    TNo* novo = TNo_createNFill(info);
    if (novo == NULL) {
        return false;
    }
    if (list->fim == NULL) {
        list->fim = novo;
        list->fim->prox = list->fim;
    } else {
        novo->prox = list->fim->prox;
        list->fim->prox = novo;
        list->fim = novo;
    }
    return true;
}
