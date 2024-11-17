#include "TDLinkedList.h"
#include <stdio.h>

int main() {
    TDLinkedList* list1 = TDLinkedList_create();
    int V[] = {2, 4, 3, 8};
    for (int i = 0; i < 4; i++) {
        if (!TDLinkedList_insert_end(list1, V[i])) {
            printf("Erro ao inserir V[%d] = %d\n", i, V[i]);
        }
    }
    printf("Lista 1: \n");
    TDLinkedList_print(list1);

    TDLinkedList* list2 = TDLinkedList_reverse_list(list1);
    printf("Lista 1 invertida: \n");
    TDLinkedList_print(list2);

}