#include "TDLinkedList.h"
#include <stdio.h>

int main() {
    TDLinkedList* list = TDLinkedList_create();
    TDLinkedList* list_letras = TDLinkedList_create();
    TDLinkedList* list_num = TDLinkedList_create();
    int V[] = {'A', 1, 'E', 5, 'T', 7, 'W', 8, 'G'};
    for (int i = 0; i < 9; i++) {
        if (!TDLinkedList_insert_end(list, V[i])) {
            printf("Nao foi possivel inserir V[%d] = %c\n", i, V[i]);
        }
    }
    TDLinkedList_print(list);

    TDLinkedList* list2 = TDLinkedList_ordem_caracteres(list, list_letras, list_num);
    TDLinkedList_print(list2);
}