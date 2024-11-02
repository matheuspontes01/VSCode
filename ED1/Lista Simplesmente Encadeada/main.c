#include "TLinkedList.h"
#include <stdio.h>

int main(){
    TLinkedList* list = TLinkedList_create();
    int V[] = {10, 2, 5};
    for(int i=0; i<3; i++) {
        if(!TLinkedList_sorted(list, V[i]))
            printf("Erro ao inserir %d\n", V[i]);
    }
    printf("Lista 1: \n"); 
    TLinkedList_print(list);

    printf("Lista 1 que insere -1 no inicio: \n"); 
    TLinkedList_insert_begin(list, -1);
    TLinkedList_print(list);
    //TLinkedList_deleteAll(list);

    TLinkedList* list2 = TLinkedList_create();
    int B[] = {4, 16, 5};
    for(int i=0; i<3; i++) {
        if(!TLinkedList_sorted(list2, B[i]))
            printf("Erro ao inserir %d\n", B[i]);
    }
    printf("Lista 2: \n"); 
    TLinkedList_print(list2);
    TLinkedList* list3 = TLinkedList_intercalar(list, list2);

    printf("Lista que intercala duas listas: \n"); 
    TLinkedList_print(list3);

    TLinkedList_deleteOneValue(list3, 2);
    TLinkedList_deleteOneValue(list3, 4);
    TLinkedList_deleteOneValue(list3, 16);

    printf("Lista 3 com valores 2, 4, 16 deletados: \n"); 
    TLinkedList_print(list3);

    TLinkedList* list4 = TLinkedList_intercalar_ordenadamente(list, list2);

    printf("Lista que intercala duas lista de forma ordenada: \n"); 
    TLinkedList_print(list4);

    TLinkedList* list5 = TLinkedList_retornar_impares(list, list2);

    printf("Lista com numeros impares: \n"); 
    TLinkedList_print(list5);

    TLinkedList* list6 = TLinkedList_intersecao(list, list2);

    printf("Lista que possuem as mesmas info nas duas listas: \n"); 
    TLinkedList_print(list6);

    TLinkedList* list7 = TLinkedList_retornar_pares(list, list2);

    printf("Lista com numeros pares: \n"); 
    TLinkedList_print(list7);
    return 0;
}