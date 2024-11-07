#include "TLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

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

    int numero_testes, qtd_dados, pos_loop;

    // Quantidade de testes
    scanf("%d", &numero_testes);

    for (int i = 0; i < numero_testes; i++) {
        // Quantidade de dados e onde ocorre o loop
        scanf("%d %d", &qtd_dados, &pos_loop);
        int *V = malloc(qtd_dados * sizeof(int));
        for (int i = 0; i < qtd_dados; i++) {
            //Leitura dos dados
            scanf("%d", &V[i]);
        }
        
        TLinkedList *list8 = TLinkedList_create();
        for (int i = 0; i < qtd_dados; i++) {
            if (!TLinkedList_insert_end(list8, V[i])) {
                printf("Erro ao inserir o dados V[%d] = %d\n", i, V[i]);
            }
        }

        TLinkedList_createLoop(list8, pos_loop);
        //Posicao do loop
        printf("%d\n", TLinkedList_hasLoop(list8));
    }


    return 0;
}