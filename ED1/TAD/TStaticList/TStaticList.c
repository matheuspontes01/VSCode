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

void lista_print(TStaticList* list) {
    for (unsigned int i = 0; i < list->qty; i++) {
        printf("%d, ", list->data[i]);
    }
    printf("\n");
}
