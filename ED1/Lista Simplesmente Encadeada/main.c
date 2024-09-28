#include "TLinkedList.h"
#include <stdio.h>

int main(){
    TLinkedList* list = TLinkedList_create();
    int V[] = {10, 2, 5};
    for(int i=0; i<3; i++)
        if(!TLinkedList_insert_begin(list, V[i]))
            printf("Erro ao inserir %d\n", V[i]);
    TLinkedList_print(list);
    TLinkedList_insert_begin(list, -1);
    TLinkedList_print(list);
    TLinkedList_deleteAll(list);
    return 0;
}