#include "TStaticList.h"
#include <stdio.h>
#include <stdlib.h>

struct _lista {
    unsigned int MAX;
    unsigned int qty;
    int *data;
};

TStaticList* lista_create(unsigned int size) {
    TStaticList* list = malloc(sizeof(TStaticList));
    if (list != NULL) {
        list->data = malloc(sizeof(int) * size);
        if (list->data == NULL) {
            free(list);
            return NULL;
        }
        list->qty = 0;
        list->MAX = size;
    }
    return list;
}

bool lista_insert_end(TStaticList* list, int n1) {
    if (lista_is_full(list)) {
        return false;
    }
    list->data[list->qty] = n1;
    list->qty++;
    return true;
}

bool lista_insert_begin(TStaticList* list, int n1) {
    if (lista_is_full(list)) {
        return false;
    }

    for (int i = list->qty; i > 0; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[0] = n1;
    list->qty++;
    return true;
}

bool lista_sorted(TStaticList* list, int n1) {
    if (lista_is_full(list)) {
        return false;
    }

    int i = 0;
    while (i < list->qty && list->data[i] < n1) {
        i++;
    }

    for (int k = list->qty; k > i; k--) {
        list->data[k] = list->data[k - 1];
    }

    list->data[i] = n1;
    list->qty++;
    return true;
}

bool lista_is_full(TStaticList* list) {
    return list->qty == list->MAX;
}

bool lista_is_empty(TStaticList* list){
    return list->qty == 0;
}

void lista_print(TStaticList* list) {
    for (unsigned int i = 0; i < list->qty; i++) {
        printf("%d, ", list->data[i]);
    }
    printf("\n");
}

bool TStaticList_is_empty(TStaticList* lista){
  return (lista->qty == 0);
}

bool TStaticList_delete_end(TStaticList* lista, int* valor){
  return TStaticList_delete_at(lista, valor, lista->qty-1);
}

bool TStaticList_delete_begin(TStaticList* lista, int* valor){
  return TStaticList_delete_at(lista, valor, 0);
}

bool TStaticList_delete_at(TStaticList* lista, int* valor, int pos){
  if (TStaticList_is_empty(lista) || pos<0 || pos>=lista->qty)
    return false;
  *valor = lista->data[pos];
  //Copiar os dados
  for(int i=pos; i < lista->qty-1; i++)
    lista->data[i] = lista->data[i+1];
  lista->qty--;
  return true;  
}

bool TStaticList_delete_beginMine(TStaticList* list){
    if (lista_is_empty(list)){
        return false;
    }

    for (int i = 0; i < list->qty-1; i++){
        list->data[i] = list->data[i+1];
    }

    list->qty--;
    return true;
}

bool TStaticList_deleteOneValue(TStaticList* list, int valor){
    if (lista_is_empty(list)){
        return false;
    }

    int i = 0;
    while (i < list->qty && list->data[i] != valor){
        i++;
    }

    if (i == list->qty){
        return false; // valor nao encontrado
    }

    for (int k = i; k < list->qty-1; k++){
        list->data[k] = list->data[k+1];
    }

    list->qty--;
    return true;
}
