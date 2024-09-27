#include "TLinkedList.h"
#include <stdio.h>

int main(void){
    TLinkedList *list = TLinkedList_create();
    int V[] = {10, 2, 5};
    for (int i = 0; i < 3; i++){
        if (!TLinkedList_insert_end(list, V[i])){
            printf("Erro ao inserir: %d\n", V[i]);
        }
    }
    TLinkedList_print(list);
}