#include "TDLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{   
    // Descomente isso caso seja int main(int argc, char *argv[])
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

    TDLinkedList_print(list);

    //TDLinkedList_reverse_print(list);

    TDLinkedList_delete_oneValue(list, 2);
    printf("Lista apos remover o 5 da lista\n");
    TDLinkedList_print(list);

    TDLinkedList_delete_oneValue(list, 6);
    printf("Lista apos remover o 6 da lista\n");
    TDLinkedList_print(list);


    TDLinkedList_deleteList(list);
    printf("Lista removida\n");
    TDLinkedList_print(list);
    return 0;
    
}