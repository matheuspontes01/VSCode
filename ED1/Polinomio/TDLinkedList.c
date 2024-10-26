#include "TDLinkedList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct _no {
    int coeficiente;
    int expoente;
    struct _no *prox, *ant;
} TNo;

struct _list {
    TNo* inicio;
    TNo* fim;
};

TNo* TNo_createNFill(int coeficiente, int expoente) { // ok
    TNo* novo = malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->coeficiente = coeficiente;
        novo->expoente = expoente;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    return novo;
}

TDLinkedList* inicializar_polinomio() { // ok
    TDLinkedList* list = malloc(sizeof(TDLinkedList));
    if (list != NULL) {
        list->inicio = NULL;
        list->fim = NULL;
    }
    return list;
}

bool inserir_polinomio(TDLinkedList* list, int coeficiente, int expoente) { // ok
    TNo* novo = TNo_createNFill(coeficiente, expoente);
    TNo* temp;
    if (novo == NULL) return false;

    if (list->inicio == NULL) {
        list->inicio = novo;
        list->fim = novo;
    } else {
        TNo* aux = list->inicio;
        TNo* anterior = NULL;

        while (aux != NULL) {
            if (aux->expoente == novo->expoente) {
                aux->coeficiente += novo->coeficiente;

                if (aux->coeficiente == 0) {
                    if (anterior != NULL) {
                        anterior->prox = aux->prox;
                    } else {
                        list->inicio = aux->prox;
                    }
                    if (aux->prox != NULL) {
                        aux->prox->ant = anterior;
                    } else {
                        list->fim = anterior;
                    }
                    free(aux);
            }
            free(novo);
            return true;
        }
        
        anterior = aux; 
        aux = aux->prox;
    }
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
    }
    return true;
}

void imprimir_polinomio(TDLinkedList* list) { // ok
    TNo* aux = list->inicio;

    if (list->inicio == NULL) {
        printf("0x^0\n");
    }

    while (aux != NULL) {
        if (aux->expoente == 0) {
            printf(" %+d ", aux->coeficiente);
        } else {
            printf(" %+dx^%d ", aux->coeficiente, aux->expoente);
        }
        aux = aux->prox;
    }
    putchar('\n');
}

bool eliminar_termo(TDLinkedList* list, int expoente) { // ok
    TNo* aux = list->inicio;

    if (list->inicio == NULL) return false;

    while (aux != NULL && aux->expoente != expoente) {
        aux = aux->prox;
    }


    if (aux == list->inicio) {
        list->inicio = aux->prox;
        free(aux);
    } else if (aux == list->fim) {
        aux->ant = list->fim;
        free(aux);
     } else if (aux == NULL) {
        printf("Nao ha o termo de grau %d.\n", expoente);
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
    }

    return true;
}

bool reiniciar_polinomio(TDLinkedList* list) { // ok
    if (list->inicio == NULL) return false;

    TNo* aux = list->inicio;
    TNo* temp;

    while (aux != NULL) {
        temp = aux->prox;
        free(aux);
        aux = temp;
    }
    list->inicio = NULL;

    return true;
}

int calcular_polinomio(TDLinkedList* list, int n) { // ok
    int resultado = 0;

    TNo* aux = list->inicio;

    while (aux != NULL) {
        if (aux->coeficiente > 0) {
            resultado += (aux->coeficiente)*(pow(n, aux->expoente));
        } else {
            resultado += (aux->coeficiente)*(pow(n, aux->expoente));
        }
        aux = aux->prox;
    }

    return resultado;
}  



