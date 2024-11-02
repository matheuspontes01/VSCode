#include "TStaticList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typdef struct _list {
    int MAX;
    int qty;
    int* data;
} TStaticList;

TStaticList* TStaticList_create(int size) {
    TStaticList* list = malloc(sizeof(TStaticList));
    if (list != NULL) {
        list->data = malloc(size * sizeof(TStaticList));
        if (list->data == NULL) {
            free(list);
            return NULL;
        }
        list->qty = 0;
        list->MAX = size;
    }
    return list;
}

bool list_is_full(TStaticList* list) {
    return list->data == list->MAX;
}

bool list_is_empty(TStaticList* list) {
    return list->data == 0;
}

bool TStaticList_insert_end(TStaticList* list, int info) {
    if (list_is_full(list)) return false;

    list->data[list->qty] = info;
    list->qty++;
    return true;
}

bool TStaticList_insert_begin(TStaticList* list, int info) {
    if (list_is_full(list)) return false;

    for (int i = list->qty; i > 0; i--) {
        list->data[i] = list->data[i - 1]; 
    }

    list->data[0] = info;
    list->qty++;
    return true;
}

bool TStaticList_sorted(TStaticList* list, int info) {
    if (list_is_full(list)) return false;

    int i = 0;
    while (i < list->qty && list->data[i] != info) {
        i++;
    }

    for (int j = list->qty; j > i; j--) {
        list->data[j] = list->data[j - 1];
    }
    list->data[i] = info;
    list->qty++;
    return true;
}

bool TStaticList_deleteOneValue(TStaticList* list, int info){
    if (list_is_empty(list)) return false;

    int i = 0;
    while (i < list->qty && list->data[i] != info) {
        i++;
    }

    if (i == list->qty) {
        return false;
    }

    for (int j = i; j < list->qty - 1; j--) { // mover os elementos para a esquerda, a partir da onde 'info' foi encontrado
        list->data[j] = list->data[j + 1];
    }

    list->qty--;

    return true;
}

bool TStaticList_deleteList(TStaticList* list) {
    if (list_is_empty(list)) return false;

    list->qty = 0;

    return true;
}

bool TStaticList_info_igual(TStaticList* list, int info) {
    for (int i = 0; i < list->qty; i++) {
        if (list->data[i] == info) return true;
    }
    return false;
}

TStaticList* TStaticList_intersecao(TStaticList* list, TStaticList* list2) {
    if (list_is_empty(list) || list_is_empty(list2)) return false;

    TStaticList* list3 = TStaticList_create(list->qty + list2->qty);
    for (int i = 0; i < list->qty; i++) {
        if (!TStaticList_info_igual) {
            TStaticList_insert_end(list3, list->data[i]);
        }
    }

    for (int i = 0; i < list2->qty; i++) {
        if (!TStaticList_info_igual) {
            TStaticList_insert_end(list3, list2->data[i]);
        }
    }

    return true;
    
}