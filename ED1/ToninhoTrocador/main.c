#include "LinkedList.h"
#include <stdio.h>

int main() {
    int id, id_prox;
    float valor;
    TLinkedList* list = TLinkedList_create();
    do {
        scanf("%d %f %d", &id, &valor, &id_prox);
        if (id == 0 && valor == 0 && id_prox == 0) {
            break;
        }
        TLinkedList_insert_end(list, id, valor, id_prox);
    } while (1);

    TLinkedList_Toninho(list);
    return 0;
}