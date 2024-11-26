#include "TDLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main() {   
    // Descomente isso caso seja int main(int argc, char *argv[])
    // Obs: insere os numeros apos ./a.exe para rodar o programa
    /*
    if (argc < 2) {
        printf("Uso: %s 1 2 3 4\n", argv[0]);
        return 0;
    }
    TDLinkedList *list = TDLinkedList_create();
    for(int i = 1; i < argc; i++)
        if(!TDLinkedList_insert_end(list, atoi(argv[i])))
            printf("Problema ao inserir o valor: %s\n", argv[i]);
    TDLinkedList_print(list);
    TDLinkedList_reverse_print(list);
    return 0;
    */
    
    
    
    
   // Descomente isso caso seja int main(void)
   
    TDLinkedList *list = TDLinkedList_create();
    int V[] = {5, 2, 6, 1};

    for (int i = 0; i < 4; i++) {
        if (!TDLinkedList_sorted(list, V[i])){
            printf("Problema ao inserir o valor: %d\n", V[i]);
        }
    }

    TDLinkedList* list2 = TDLinkedList_create();

    int N[] = {5, 3, 6, 1, 2, 6};

    for (int i = 0; i < 6; i++) {
        if (!TDLinkedList_sorted(list2, N[i])){
            printf("Problema ao inserir o valor: %d\n", N[i]);
        }
    }
    TDLinkedList_equallist_equaldata(list, list2);

    TDLinkedList_check_sorted(list);
    TDLinkedList_print(list);

    //TDLinkedList_reverse_print(list);

    //TDLinkedList_delete_oneValue(list, 6);
    //printf("Lista apos remover o 6 da lista\n");
    //TDLinkedList_print(list);


    //TDLinkedList_deleteList(list);
   // printf("Lista removida\n");
    //TDLinkedList_print(list);

    TDLinkedList_print(list2);

    TDLinkedList* list3 = TDLinkedList_intercalar_ordenado(list, list2);

    TDLinkedList_print(list3);

    printf("Media das infos na lista 3: %.2f\n", TDLinkedList_calcular_media(list3));

    TDLinkedList* list4 = TDLinkedList_gerar_lista_impares(list3);

    printf("Lista so com impares: \n");
    TDLinkedList_print(list4);
    return 0;
}
