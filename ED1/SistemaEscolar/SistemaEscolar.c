#include "SistemaEscolar.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _no {
    char nome[30];
    float nota;
    int matricula;
    struct _no *prox;
} TNo;

struct _list {
    TNo* inicio;
};

TNo* TNo_createNFill(char nome[30], float nota, int matricula) {
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->nota = nota;
        novo->matricula = matricula;
    }
    return novo;
}

TCircularList* TCircularList_create() {
    TCircularList* list = malloc(sizeof(TCircularList));
    if (list != NULL) {
        list->inicio = NULL;
    }
    return list;
}

bool TCircularList_insert_end(TCircularList* list, char nome[30], float nota, int matricula) {
    TNo* novo = TNo_createNFill(nome, nota, matricula);
    if (novo == NULL) return false;

    if (list->inicio == NULL) {
        list->inicio = novo;
        novo->prox = novo;
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

bool TCircularList_insert_begin(TCircularList* list, char nome[30], float nota, int matricula) {
    TNo* novo = TNo_createNFill(nome, nota, matricula);
    if (novo == NULL) return false;

    if (list->inicio == NULL) {
        list->inicio = novo;
        novo->prox = novo;
    } else {
        TNo* aux = list->inicio;
        while (aux->prox != list->inicio) {
            aux = aux->prox;
        }
        novo->prox = list->inicio;
        aux->prox = novo;
        list->inicio = novo;
    }

    return true;
}

void TCircularList_print(TCircularList* list) {
    if (list->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    TNo* aux = list->inicio;
    do {
        printf("Nome: %s\n", aux->nome);
        printf("Nota: %.1f\n", aux->nota);
        printf("Matricula: %d\n", aux->matricula);
        printf("------------------------------\n");
        aux = aux->prox;
    } while (aux != list->inicio);
}

float TCircularList_calcular_media(TCircularList* list) {
    if (list->inicio == NULL) {
        printf("Lista vazia.\n");
        return 0;
    }
    TNo* aux = list->inicio;
    float media = 0;
    int alunos = 0;

    do {
        alunos++;
        media += aux->nota;
        aux = aux->prox;
    } while (aux != list->inicio);
    media /= alunos;
    return media;
}