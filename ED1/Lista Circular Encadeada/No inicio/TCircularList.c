#include "TCircularList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no
{
    int info;
    struct _no *prox;
} TNo;

struct tcirc_list
{
    TNo *inicio;
};

TCircularList *TCircularList_Create()
{
    TCircularList *list = malloc(sizeof(TNo));
    if (list != NULL)
    {
        list->inicio = NULL;
    }
    return list;
}

TNo *TNo_createNFill(int info)
{
    TNo *novo = malloc(sizeof(TNo));
    if (novo != NULL)
    {
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}

bool TCircularList_insert(TCircularList *list, int info)
{ // inserir no inicio
    TNo *novo = TNo_createNFill(info);
    if (novo == NULL)
    {
        return false;
    }
    if (list->inicio == NULL)
    { // se a lista estiver vazia, vai apontar para ele mesmo
        list->inicio = novo;
        list->inicio->prox = list->inicio; // Ou... novo->prox = novo;
    }
    else
    { // senao, iremos inserir o novo no inicio, mas, precisamos encontrar o ultimo elemento para que ele possa apontar para o novo no
        TNo *aux = list->inicio;
        while (aux->prox != list->inicio)
        { // Percorrer a lista até achar o ultimo elemento
            aux = aux->prox;
        }
        aux->prox = novo;          // Último elemento passa a apontar para o novo nó
        novo->prox = list->inicio; // Próximo de novo deve apontar para o início
        list->inicio = novo;       // Início passa a apontar para o novo nó
    }
    return true;
}

bool TCircularList_insert_end(TCircularList *list, int info)
{
    TNo *novo = TNo_createNFill(info);
    if (novo == NULL)
    {
        return false;
    }
    if (list->inicio == NULL)
    { // se a lista estiver vazia, vai apontar para ele mesmo
        list->inicio = novo;
        list->inicio->prox = list->inicio;
    }
    else
    {
        TNo *aux = list->inicio;
        while (aux->prox != list->inicio)
        { // percorrer a lista ate achar o ultimo elemento
            aux = aux->prox;
        }
        aux->prox = novo;          // o ultimo elemento aponta para o novo no
        novo->prox = list->inicio; // novo aponta para o inicio
    }
    return true;
}

void TCircularList_print(TCircularList *list)
{
    if (list->inicio == NULL)
    {
        return;
    }
    TNo *aux = list->inicio;
    do
    {
        printf("%d, ", aux->info);
        aux = aux->prox;
    } while (aux != list->inicio);
    putchar('\n');
}

bool TCircularList_Resposta(TCircularList *list, int M)
{
    /*
    if (list->inicio == NULL) {
        return false;
    }

    TNo* atual = list->inicio;
    TNo* anterior = NULL;

    while (atual->prox != atual) { // Continua até restar um nó

        for (int i = 1; i < M; i++) {
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = atual->prox;
        free(atual);
        atual = anterior->prox;
    }


    list->inicio = atual;
    return true;
    */
}

bool TCircularList_sorted(TCircularList *list, int info)
{
    TNo *novo = TNo_createNFill(info);

    if (novo == NULL)
        return false;

    if (list->inicio == NULL)
    {
        list->inicio = novo;
        novo->prox = novo;
    }
    else
    {
        TNo *aux = list->inicio;
        
        if (list->inicio->info > novo->info)
        {
            while (aux->prox != list->inicio) {
                aux = aux->prox;
            }
            novo->prox = list->inicio;
            aux->prox = novo;
            list->inicio = novo;
        }
        else
        {
            TNo *anterior;
            do {
                anterior = aux;
                aux = aux->prox;
            } while (aux != list->inicio && novo->info > aux->info);
            anterior->prox = novo;
            novo->prox = aux;
        }
    }
    return true;
}

void TCircularList_print_Resposta(TCircularList *list)
{
    if (list->inicio == NULL)
    {
        return;
    }
    TNo *aux = list->inicio;
    do
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    } while (aux != list->inicio);
    putchar('\n');
}

bool TCircularList_delete(TCircularList *list, int info)
{
    if (list->inicio == NULL)
    {
        return false;
    }

    TNo *aux = list->inicio;
    TNo *anterior = NULL;

    if (list->inicio->info == info)
    {
        while (aux->prox != list->inicio)
        {
            aux = aux->prox;
        }
        TNo *fim = aux;

        if (list->inicio == list->inicio->prox)
        {
            free(list->inicio);
            list->inicio = NULL;
        }
        else
        {
            fim->prox = list->inicio->prox;
            aux = list->inicio;
            list->inicio = list->inicio->prox;
            free(aux);
        }
        return true;
    }

    aux = list->inicio;
    do
    {
        anterior = aux;
        aux = aux->prox;

        if (aux->info == info)
        {
            anterior->prox = aux->prox;
            free(aux);
            return true;
        }
    } while (aux != list->inicio);

    return false;
}

void TCircularList_deleteList(TCircularList *list)
{
    if (list->inicio == NULL)
    {
        return;
    }

    TNo *aux = list->inicio;
    TNo *temp;

    do
    {
        temp = aux->prox;
        free(aux);
        aux = temp;
    } while (aux != list->inicio);

    list->inicio = NULL;
}