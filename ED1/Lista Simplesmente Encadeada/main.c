#include "TLinkedList.h"
#include <stdio.h>

int main(){
    TLinkedList* list = TLinkedList_create();
    int V[] = {10, 2, 5};
    for(int i=0; i<3; i++)
        if(!TLinkedList_sorted(list, V[i]))
            printf("Erro ao inserir %d\n", V[i]);
    TLinkedList_print(list);
    TLinkedList_insert_begin(list, -1);
    TLinkedList_print(list);
    //TLinkedList_deleteAll(list);

    TLinkedList* list2 = TLinkedList_create();
    int B[] = {16, 12, 4};
    for(int i=0; i<3; i++)
        if(!TLinkedList_sorted(list2, B[i]))
            printf("Erro ao inserir %d\n", B[i]);

    TLinkedList_print(list2);
    TLinkedList* list3 = TLinkedList_intercalar(list, list2);

    TLinkedList_print(list3);

    TLinkedList_deleteOneValue(list3, 2);
    TLinkedList_deleteOneValue(list3, 4);
    TLinkedList_deleteOneValue(list3, 16);

    TLinkedList_print(list3);

    TLinkedList* list4 = TLinkedList_intercalar_ordenadamente(list, list2);

    TLinkedList_print(list4);
    return 0;
}