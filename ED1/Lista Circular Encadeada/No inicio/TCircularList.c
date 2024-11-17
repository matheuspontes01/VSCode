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

bool TCircularList_insert(TCircularList *list, int info) // begin
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
        printf("Lista vazia.\n");
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
    if (list->inicio == NULL)
    {
        return false;
    }

    TNo *atual = list->inicio;
    TNo *anterior = NULL;

    while (atual->prox != atual)
    { // Continua até restar um nó

        for (int i = 1; i < M; i++)
        {
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = atual->prox;
        free(atual);
        atual = anterior->prox;
    }

    list->inicio = atual;
    return true;
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
            while (aux->prox != list->inicio)
            {
                aux = aux->prox; // achar o no fim
            }
            novo->prox = list->inicio;
            aux->prox = novo;
            list->inicio = novo;
        }
        else
        {
            TNo *anterior;
            do
            {
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

        if (list->inicio == list->inicio->prox) // se tiver um elemento na lista so, ou seja, um no apontando para si mesmo
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

bool TCircularList_deleteList(TCircularList *list) // ok (errei por um igual a mais no list->inicio = NULL)
{
    if (list->inicio == NULL) return false;

    TNo* aux = list->inicio;
    TNo* temp;

    do {
        temp = aux->prox;
        free(aux);
        aux = temp;
    } while (aux != list->inicio);

    list->inicio = NULL;

    return true;
}

int TCircularList_contar_elementos(TCircularList *list)
{
    int contador = 0;

    if (list->inicio == NULL)
    {
        return contador;
        //printf("Nao ha elementos nessa lista.\n");
    }
    else
    {
        TNo *aux = list->inicio;
        do
        {
            contador++;
            aux = aux->prox;
        } while (aux != list->inicio);
        //printf("Quantidade de elementos: %d\n", contador);
        return contador;
    }
}

bool TCircularList_insert_no_inicio(TCircularList *list, int info) // ok
{
    TNo *novo = TNo_createNFill(info);

    if (novo == NULL || list->inicio == NULL)
        return false;

    TNo *aux = list->inicio;

    while (aux->prox != list->inicio)
    {
        aux = aux->prox;
    }

    TNo *fim = aux;

    novo->prox = list->inicio;
    fim->prox = novo;
    list->inicio = novo;

    return true;
}

TCircularList* TCircularList_concatenar(TCircularList* list1, TCircularList* list2) // ok
{
    if (list1->inicio == NULL || list2->inicio == NULL) return NULL;

    TCircularList *list3 = TCircularList_Create();

    if (list3->inicio == NULL)
    {
        list3->inicio = list1->inicio;
        list3->inicio->prox = list1->inicio->prox;
        TNo *aux = list1->inicio;
        while (aux->prox != list1->inicio)
        {
            aux = aux->prox;
        }
        TNo *fim1 = aux;

        TNo *aux1 = list2->inicio;
        while (aux1->prox != list2->inicio)
        {
            aux1 = aux1->prox;
        }

        TNo *fim2 = aux1;

        fim1->prox = list2->inicio;
        fim2->prox = list3->inicio;
    }

    return list3;
}

TCircularList* TCircularList_intercalar(TCircularList* list1, TCircularList* list2) { //ok

    TCircularList* list3 = TCircularList_Create();

    if (list3 == NULL) return NULL;

    TNo* aux1 = list1->inicio;
    TNo* aux2 = list2->inicio;

    bool intercalando = true;
    do {
        if (aux1 && intercalando) {
            TCircularList_insert_end(list3, aux1->info);
            if (aux1->prox == list1->inicio) {
                aux1 = NULL;
            } else {
                aux1 = aux1->prox;
            }
        }
        if (aux2 && !intercalando) {
            TCircularList_insert_end(list3, aux2->info);
            if (aux2->prox == list2->inicio) {
                aux2 = NULL;
            } else {
                aux2 = aux2->prox;
            }
        }
        intercalando = !intercalando;
    } while (aux1 != NULL || aux2 != NULL);

    return list3;
}


bool TCircularList_info_igual(TCircularList* list, int info) { // verificar se essa info esta presente na lista 
    if (list->inicio == NULL) return false; // lista vazia
    
    TNo* aux = list->inicio;
    do {
        if (aux->info == info) return true; // valor encontrado
        aux = aux->prox;
    } while (aux != list->inicio);
    
    return false; // valor nao encontrado
}

TCircularList* TCircularList_intersecao(TCircularList* list1, TCircularList* list2) { // ok
   TCircularList* list3 = TCircularList_Create();
    if (list1->inicio == NULL || list2->inicio == NULL) return list3;

    TNo* aux1 = list1->inicio;
    do { // cada elemento de list1 esta sendo comparado com todos os elementos de list2**
        TNo* aux2 = list2->inicio;
        do {
            if (aux1->info == aux2->info && !TCircularList_info_igual(list3, aux1->info)) {
                TCircularList_insert_end(list3, aux1->info);
                break; // uma vez que voce encontra um valor que esta presente em ambas as listas, nao ha necessidade de comparar outros elementos de list2 para o mesmo aux1->info
                // evita comparacoes desnecessarias
            }
            aux2 = aux2->prox;
        } while (aux2 != list2->inicio);
        aux1 = aux1->prox;
    } while (aux1 != list1->inicio);

    return list3;
}

float TCircularList_calcular_media(TCircularList* list) {
    if (!list || list->inicio == NULL) return 0;

    TNo* aux = list->inicio;
    float media = 0;
    int qty = 0;

    do {
        media += aux->info;
        qty++;
        aux = aux->prox;
    } while (aux != list->inicio);

    media /= qty;

    return media;
}

bool TCircularList_insert_position(TCircularList* list, int info_list, char direction, int info_insert) {
    TNo* novo = TNo_createNFill(info_insert);
    if (!novo) return false;

    bool position_exist = false;

    TNo* aux = list->inicio;
    TNo* anterior;
    do {
        if (aux->info == info_list) {
            position_exist = true;
            break;
        }
        anterior = aux;
        aux = aux->prox;
    } while (aux != list->inicio);

    TNo* fim = list->inicio;
    while (fim->prox != list->inicio) {
        fim = fim->prox;
    }

    if (position_exist) {
        if (direction == 'e') { // precisamos ver se esta no inicio da lista tambem
            if (aux == list->inicio) { // precisamos achar o final da lista para apontar no novo no
                fim->prox = novo;
                novo->prox = list->inicio;
                list->inicio = novo;
            } else {
                anterior->prox = novo;
                novo->prox = aux;
            }
        } else if (direction == 'd') { // precisamos verificar se esta no final da lista
            if (aux == fim) { 
                fim->prox = novo;
                novo->prox = list->inicio;
            } else {
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }
    } else {
        return false;
    }

    return true;
}

bool TCircularList_equals_list(TCircularList* list1, TCircularList* list2) { // ok
    if (!list1->inicio || !list2->inicio) return false;

    TNo* aux1 = list1->inicio;
    TNo* aux2 = list2->inicio;

    do {
        if (aux1->info != aux2->info) {
            printf("As listas nao sao iguais.\n");
            return false;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    } while (aux1 != list1->inicio || aux2 != list2->inicio);

    if (aux1 == list1->inicio && aux2 == list2->inicio) {
        printf("As listas sao iguais.\n");
        return true;
    } else {
        printf("As listas nao sao iguais.\n");
        return false;
    }
}

TCircularList* TCircularList_reverse_list(TCircularList* list) {
    TCircularList* list2 = TCircularList_Create();
    if (!list2) return NULL;

    TNo* aux = list->inicio;

    do {
        TCircularList_insert(list2, aux->info);
        aux = aux->prox;
    } while (aux != list->inicio);

    return list2;
}